#include <FApp.h>
#include "SMSBackupForm.h"

using namespace Osp::Base;
using namespace Osp::App;
using namespace Osp::Ui;
using namespace Osp::Ui::Controls;

BaseForm::BaseForm(void)
{
}

BaseForm::~BaseForm(void)
{
}

result BaseForm::OnInitializing(void)
{
	result r = E_SUCCESS;
	Footer* footer = GetFooter();
	footer->AddActionEventListener(*this);
	return r;
}

void BaseForm::OnActionPerformed(const Osp::Ui::Control& source, int actionId)
{
	switch(actionId)
	{
	default:
		Application::GetInstance()->SendUserEvent(actionId, null);
		break;
	}
}

