#include <FApp.h>
#include "MainFrame.h"

using namespace Osp::Base;
using namespace Osp::Ui;
using namespace Osp::Ui::Controls;
using namespace Osp::App;

MainFrame::MainFrame(void)
{
}

MainFrame::~MainFrame(void)
{
}

bool MainFrame::Initialize()
{
	// Construct an XML form
	Construct(L"IDF_MAINFRAME");

	return true;
}

result MainFrame::OnInitializing(void)
{
	result r = E_SUCCESS;
	InitializeButton(__pButtonSMS, L"IDC_BUTTON_SMS", ID_BUTTON_SMS, *this);
	InitializeButton(__pButtonContacts, L"IDC_BUTTON_CONTACTS",
			ID_BUTTON_CONTACTS, *this);
	InitializeButton(__pButtonCalllogs, L"IDC_BUTTON_CALLLOG",
			ID_BUTTON_CALLLOG, *this);
	InitializeButton(__pButtonCalendar, L"IDC_BUTTON_CALENDAR",
			ID_BUTTON_CALENDAR, *this);
	InitializeButton(__pButtonBookmarks, L"IDC_BUTTON_BOOKMARKS",
			ID_BUTTON_BOOKMARKS, *this);
	return r;
}

result MainFrame::OnTerminating(void)
{
	result r = E_SUCCESS;
	return r;
}

void MainFrame::OnActionPerformed(const Osp::Ui::Control& source, int actionId)
{
	switch (actionId)
	{
	case ID_BUTTON_SMS:
	{
		Application::GetInstance()->SendUserEvent(1000, null);
	}
		break;
	case ID_BUTTON_CONTACTS:
	{
		AppLog("ACTION %d \n", actionId);
	}
		break;
	case ID_BUTTON_CALLLOG:
	{
		AppLog("ACTION %d \n", actionId);
	}
		break;
	case ID_BUTTON_CALENDAR:
	{
		AppLog("ACTION %d \n", actionId);
	}
		break;
	case ID_BUTTON_BOOKMARKS:
	{
		AppLog("ACTION %d \n", actionId);
	}
		break;
	default:
		break;
	}
}

