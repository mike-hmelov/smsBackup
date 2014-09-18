/*
 * SMSBackupThread.cpp
 *
 *  Created on: 16.09.2014
 *      Author: пусик
 */

#include "../inc/SMSBackupThread.h"
#include <FBase.h>
#include <FContent.h>

using namespace Osp::Messaging;
using namespace Osp::Io;
using namespace Osp::Base;

SMSBackupThread::SMSBackupThread(IThreadEventListener& listener) :
	__listener(listener) {
	__pSmsManager = null;
	__pFile = null;
}

SMSBackupThread::~SMSBackupThread() {
	AppLog("Thread destructor");
	if (__pSmsManager)
		delete __pSmsManager;
	if (__pFile)
		delete __pFile;
	Osp::Content::ContentManagerUtil::MoveToMediaDirectory(L"/Home/sms.txt",
			L"/Media/Others/sms.txt");
	Osp::Content::ContentManager manager;
	manager.Construct();
	Osp::Content::OtherContentInfo contentInfo;
	contentInfo.Construct(L"/Media/Others/sms.txt");
	manager.CreateContent(contentInfo);
}

Osp::Base::Object* SMSBackupThread::Run() {
	__listener.OnProgress(0);
	result r = InitSMSManager();
	if (r != E_SUCCESS)
		return null;
	int totalCount = __pSmsManager->GetTotalMessageCount(
			SMS_MESSAGE_BOX_TYPE_ALL);
	AppLog("Total SMS count: %d", totalCount);
	double processedCount = 0;
	for (int start = 0; start < totalCount; start += 10) {
		int foundResult = 0;
		Osp::Base::Collection::IList* list = __pSmsManager->SearchMessageBoxN(
				SMS_MESSAGE_BOX_TYPE_ALL, null, start, 10, foundResult);
		for (int k = 0; k < list->GetCount(); k++) {
			SmsMessage* message = (SmsMessage*) list->GetAt(k);
			ProcessSMSMessage(message);
			AppLog("processing: %x", message);
			processedCount++;
			__listener.OnProgress((int) ((processedCount / totalCount) * 100));
		}
		delete list;
	}
	return null;
}

result SMSBackupThread::InitSMSManager() {
	__pSmsManager = new SmsManager();
	result r = __pSmsManager->Construct(*this);
	if (r != E_SUCCESS)
		return r;
	__pFile = new File();
	__pFile->Construct(String(L"/Home/sms.txt"), String(L"w"), false);
	return E_SUCCESS;
}

void SMSBackupThread::ProcessSMSMessage(SmsMessage* message) {
	DateTime dt;
	String sType;
	String sPhone;
	SmsMessageBoxType type = message->GetMessageBoxType();
	switch (type) {
	case SMS_MESSAGE_BOX_TYPE_INBOX:
		dt = message->GetReceivedTime();
		sType = "inbox";
		//		sPhone = *(String*)message->GetRecipientList().GetListN(RECIPIENT_TYPE_TO)->GetAt(0);
		sPhone = message->GetSenderAddress();
		break;
	case SMS_MESSAGE_BOX_TYPE_SENTBOX:
	case SMS_MESSAGE_BOX_TYPE_OUTBOX:
		dt = message->GetSentTime();
		sType = "out";
		sPhone = *(String*) message->GetRecipientList().GetListN(
				RECIPIENT_TYPE_TO)->GetAt(0);
		break;
	}
	String result;
	result.Format(200,
			L"Type: %d, SType: %S, Phone: %S, Date: %d.%d.%d-%d:%d:%d", type,
			sType.GetPointer(), sPhone.GetPointer(), dt.GetDay(),
			dt.GetMonth(), dt.GetYear(), dt.GetHour(), dt.GetMinute(),
			dt.GetSecond());
	AppLog("%S", result.GetPointer());
	__pFile->Write(result);
	__pFile->Write(L"\n", sizeof(wchar_t));
	__pFile->Write(message->GetText());
	__pFile->Write(L"\n", sizeof(wchar_t));
}

void SMSBackupThread::OnStop(void) {
	__pFile->Flush();
	__listener.OnStop();
}

