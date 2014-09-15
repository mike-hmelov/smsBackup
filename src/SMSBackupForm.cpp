#include "SMSBackupForm.h"

using namespace Osp::Base;
using namespace Osp::Ui;
using namespace Osp::Ui::Controls;

SMSBackupForm::SMSBackupForm(void)
{
}

SMSBackupForm::~SMSBackupForm(void)
{
}

bool SMSBackupForm::Initialize()
{
	// Construct an XML form
	Construct(L"IDF_SMSBACKUPFORM");

	return true;
}

result SMSBackupForm::OnInitializing(void)
{
	result r = E_SUCCESS;
	r = BaseForm::OnInitializing();
	if (r != E_SUCCESS)
		return r;
	__pBackupButton = static_cast<Button *> (GetControl("IDC_BUTTON_BACKUP"));
	if (__pBackupButton == null)
		return E_INVALID_ARG;
	__pBackupButton->SetActionId(1001);
	__pBackupButton->AddActionEventListener(*this);
	__pProgressBar = static_cast<Progress*> (GetControl("IDC_PROGRESS"));
	if (__pProgressBar == null)
		return E_INVALID_ARG;
	return r;
}

result SMSBackupForm::OnTerminating(void)
{
	result r = E_SUCCESS;

	// TODO: Add your termination code here

	return r;
}

void SMSBackupForm::OnActionPerformed(const Osp::Ui::Control &source, int actionId)
{
	switch (actionId)
	{
	case SMS_BACKUP_BUTTON:
		BackupSMS();
		break;
	default:
		BaseForm::OnActionPerformed(source, actionId);
		break;
	}
}

void SMSBackupForm::BackupSMS()
{
	OnProgress(0);
	__pBackupButton->SetEnabled(false);
	__pThread = new SMSBackupThread(*this);
	__pThread->Construct();
	__pThread->Start();
}

void SMSBackupForm::OnProgress(int progress)
{
	__pProgressBar->SetValue(progress);
	__pProgressBar->RequestRedraw(true);
}

void SMSBackupForm::OnStop()
{
	__pBackupButton->SetEnabled(true);
	delete __pThread;
}

