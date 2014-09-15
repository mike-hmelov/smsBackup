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
	if(r != E_SUCCESS)
		return r;
	return r;
}

result SMSBackupForm::OnTerminating(void)
{
	result r = E_SUCCESS;

	// TODO: Add your termination code here

	return r;
}
