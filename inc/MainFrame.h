#ifndef _MAINFRAME_H_
#define _MAINFRAME_H_

#include <FBase.h>
#include <FUi.h>
#include "BaseFrame.h"

class MainFrame :
	public BaseFrame,
	public Osp::Ui::IActionEventListener
{

// Construction
public:
	MainFrame(void);
	virtual ~MainFrame(void);
	bool Initialize(void);

// Implementation
protected:
	static const int ID_BUTTON_SMS = 101;
	static const int ID_BUTTON_CONTACTS = 102;
	static const int ID_BUTTON_CALLLOG = 103;
	static const int ID_BUTTON_CALENDAR = 104;
	static const int ID_BUTTON_BOOKMARKS = 105;
private:
	Osp::Ui::Controls::Button *__pButtonSMS;
	Osp::Ui::Controls::Button *__pButtonContacts;
	Osp::Ui::Controls::Button *__pButtonCalllogs;
	Osp::Ui::Controls::Button *__pButtonCalendar;
	Osp::Ui::Controls::Button *__pButtonBookmarks;

public:
	virtual result OnInitializing(void);
	virtual result OnTerminating(void);
	virtual void OnActionPerformed(const Osp::Ui::Control& source, int actionId);
};

#endif	//_MAINFRAME_H_
