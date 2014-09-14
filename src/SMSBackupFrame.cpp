#include "SMSBackupFrame.h"

using namespace Osp::Base;
using namespace Osp::Ui;
using namespace Osp::Ui::Controls;

SMSBackupFrame::SMSBackupFrame(void)
{
}

SMSBackupFrame::~SMSBackupFrame(void)
{
}

bool SMSBackupFrame::Initialize()
{
	Form::Construct(L"IDF_SMSBACKUPFRAME");

	return true;
}

result SMSBackupFrame::OnInitializing(void)
{
	result r = E_SUCCESS;

	Footer* pFooter = Form::GetFooter();

	pFooter->SetStyle(FOOTER_STYLE_BUTTON_TEXT);
	pFooter->SetBackButton();
	pFooter->AddActionEventListener(*this);

	Button *pButton_backup = static_cast<Button *> (GetControl(
			"IDC_BUTTON_BACKUP"));
	if (pButton_backup)
	{
		pButton_backup->SetActionId(201);
		pButton_backup->AddActionEventListener(*this);
	}

	return r;
}

result SMSBackupFrame::OnTerminating(void)
{
	result r = E_SUCCESS;

	// TODO: Add your termination code here

	return r;
}

void SMSBackupFrame::OnActionPerformed(const Osp::Ui::Control &source,
		int actionId)
{
	switch (actionId)
	{
	case 201:
		OnBackupButtonClick();
		break;
	}
}

void SMSBackupFrame::OnBackupButtonClick()
{

}
