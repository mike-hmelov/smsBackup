/**
 * Name        : SMSBackup
 * Version     : 
 * Vendor      : 
 * Description : 
 */

#include "SMSBackup.h"
#include "SMSBackupForm.h"
#include "BaseForm.h"

using namespace Osp::App;
using namespace Osp::Base;
using namespace Osp::System;
using namespace Osp::Ui;
using namespace Osp::Ui::Controls;

SMSBackup::SMSBackup()
{
}

SMSBackup::~SMSBackup()
{
}

Application*
SMSBackup::CreateInstance(void)
{
	// Create the instance through the constructor.
	return new SMSBackup();
}

bool SMSBackup::OnAppInitializing(AppRegistry& appRegistry)
{
	// Uncomment the following statement to listen to the screen on/off events.
	//PowerManager::SetScreenEventListener(*this);

	// Create a form
	__pSMSBackupForm = new SMSBackupForm();
	__pContactBackupForm = new ContactsBackupForm();
	__pCalendarBackupForm = new CalendarBackupForm();
	__pCallBackupForm = new CallBackupForm();
	__pSMSBackupForm->Initialize();
	__pContactBackupForm->Initialize();
	__pCallBackupForm->Initialize();
	__pCalendarBackupForm->Initialize();

	// Add the form to the frame
	Frame *pFrame = GetAppFrame()->GetFrame();
	pFrame->AddControl(*__pSMSBackupForm);
	pFrame->AddControl(*__pCalendarBackupForm);
	pFrame->AddControl(*__pCallBackupForm);
	pFrame->AddControl(*__pContactBackupForm);

	// Set the current form
	pFrame->SetCurrentForm(*__pSMSBackupForm);

	// Draw and Show the form
	__pSMSBackupForm->Draw();
	__pSMSBackupForm->Show();

	return true;
}

bool SMSBackup::OnAppTerminating(AppRegistry& appRegistry, bool forcedTermination)
{
	return true;
}

void SMSBackup::OnForeground(void)
{
}

void SMSBackup::OnBackground(void)
{
}

void SMSBackup::OnLowMemory(void)
{
}

void SMSBackup::OnBatteryLevelChanged(BatteryLevel batteryLevel)
{
}

void SMSBackup::OnScreenOn(void)
{
}

void SMSBackup::OnScreenOff(void)
{
}

void SMSBackup::OnUserEventReceivedN(RequestId requestId, Osp::Base::Collection::IList *pArgs)
{
	Frame *pFrame = GetAppFrame()->GetFrame();
	BaseForm *pNewForm;
	switch (requestId)
	{
	case BaseForm::FOOTER_BUTTON_CALENDAR:
		pFrame->SetCurrentForm(*__pSMSBackupForm);
		pNewForm = __pSMSBackupForm;
		break;
	case BaseForm::FOOTER_BUTTON_CALL:
		pFrame->SetCurrentForm(*__pCallBackupForm);
		pNewForm = __pCallBackupForm;
		break;
	case BaseForm::FOOTER_BUTTON_CONTACT:
		pFrame->SetCurrentForm(*__pContactBackupForm);
		pNewForm = __pContactBackupForm;
		break;
	case BaseForm::FOOTER_BUTTON_SMS:
		pFrame->SetCurrentForm(*__pSMSBackupForm);
		pNewForm = __pSMSBackupForm;
		break;
	}
	pNewForm->Draw();
	pNewForm->Show();
	AppLog("REQUEST: %d", requestId);
}

