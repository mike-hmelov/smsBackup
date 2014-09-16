/*
 * SMSBackupThread.cpp
 *
 *  Created on: 16.09.2014
 *      Author: пусик
 */

#include "../inc/SMSBackupThread.h"

using namespace Osp::Xml;
using namespace Osp::Messaging;

SMSBackupThread::SMSBackupThread(IThreadEventListener& listener) :
	__listener(listener)
{
	__pSmsManager = null;
	__pWriter = null;
}

SMSBackupThread::~SMSBackupThread()
{
	if (__pSmsManager != null)
		delete __pSmsManager;
	if (__pWriter)
	{
		xmlTextWriterEndDocument(__pWriter);
		xmlFreeTextWriter(__pWriter);
	}
}

Osp::Base::Object* SMSBackupThread::Run()
{
	__listener.OnProgress(0);
	result r = InitSMSManager();
	if (r != E_SUCCESS)
		return null;
	InitXMLFile();
	double totalCount = __pSmsManager->GetTotalMessageCount(SMS_MESSAGE_BOX_TYPE_ALL);
	AppLog("Total SMS count: %d", totalCount);
	double processedCount = 0;
	for(int start = 0; start < totalCount; start += 10)
	{
		int foundResult = 0;
		Osp::Base::Collection::IList* list = __pSmsManager->SearchMessageBoxN(SMS_MESSAGE_BOX_TYPE_ALL, null, start, 10, foundResult);
		for(int k = 0; k < list->GetCount(); k++)
		{
			SmsMessage* message = (SmsMessage*)list->GetAt(k);
			AppLog("processing: %x", message);
			processedCount++;
			__listener.OnProgress((int)((processedCount / totalCount) * 100));
		}
		delete list;
	}
	return null;
}

result SMSBackupThread::InitSMSManager()
{
	__pSmsManager = new SmsManager();
	result r = __pSmsManager->Construct(*this);
	if (r != E_SUCCESS)
		return r;
	return E_SUCCESS;
}

result SMSBackupThread::InitXMLFile()
{
	__pWriter = xmlNewTextWriterFilename("/Home/sms.xml", 0);
	return xmlTextWriterStartDocument(__pWriter, "1.0", "UTF-8", null);
}

void SMSBackupThread::OnStop(void)
{
	__listener.OnStop();
}

