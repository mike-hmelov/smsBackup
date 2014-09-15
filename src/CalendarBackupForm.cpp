
#include "CalendarBackupForm.h"

using namespace Osp::Base;
using namespace Osp::Ui;
using namespace Osp::Ui::Controls;


CalendarBackupForm::CalendarBackupForm(void)
{
}

CalendarBackupForm::~CalendarBackupForm(void)
{
}

bool
CalendarBackupForm::Initialize()
{
	Form::Construct(L"IDF_CALENDARBACKUPFORM");

	return true;
}

result
CalendarBackupForm::OnInitializing(void)
{
	result r = E_SUCCESS;
	r = BaseForm::OnInitializing();
	if(r != E_SUCCESS)
		return r;
	return r;
}

result
CalendarBackupForm::OnTerminating(void)
{
	result r = E_SUCCESS;

	// TODO: Add your termination code here

	return r;
}


