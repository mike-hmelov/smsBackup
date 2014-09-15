
#include "CallBackupForm.h"

using namespace Osp::Base;
using namespace Osp::Ui;
using namespace Osp::Ui::Controls;


CallBackupForm::CallBackupForm(void)
{
}

CallBackupForm::~CallBackupForm(void)
{
}

bool
CallBackupForm::Initialize()
{
	Form::Construct(L"IDF_CALLBACKUPFORM");

	return true;
}

result
CallBackupForm::OnInitializing(void)
{
	result r = E_SUCCESS;
	r = BaseForm::OnInitializing();
	if(r != E_SUCCESS)
		return r;
	return r;
}

result
CallBackupForm::OnTerminating(void)
{
	result r = E_SUCCESS;

	// TODO: Add your termination code here

	return r;
}


