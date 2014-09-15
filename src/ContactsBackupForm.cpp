
#include "ContactsBackupForm.h"

using namespace Osp::Base;
using namespace Osp::Ui;
using namespace Osp::Ui::Controls;


ContactsBackupForm::ContactsBackupForm(void)
{
}

ContactsBackupForm::~ContactsBackupForm(void)
{
}

bool
ContactsBackupForm::Initialize()
{
	Form::Construct(L"IDF_CONTACTSBACKUPFORM");

	return true;
}

result
ContactsBackupForm::OnInitializing(void)
{
	result r = E_SUCCESS;
	r = BaseForm::OnInitializing();
	if(r != E_SUCCESS)
		return r;
	return r;
}

result
ContactsBackupForm::OnTerminating(void)
{
	result r = E_SUCCESS;

	// TODO: Add your termination code here

	return r;
}


