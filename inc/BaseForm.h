#ifndef _BASEFORM_H_
#define _BASEFORM_H_

#include <FBase.h>
#include <FUi.h>

class BaseForm: public Osp::Ui::Controls::Form, public Osp::Ui::IActionEventListener
{

	// Construction
public:
	BaseForm(void);
	virtual ~BaseForm(void);

	// Implementation
public:
	static const int FOOTER_BUTTON_SMS = 1000;
	static const int FOOTER_BUTTON_CONTACT = 2000;
	static const int FOOTER_BUTTON_CALL = 3000;
	static const int FOOTER_BUTTON_CALENDAR = 4000;

public:
	virtual result OnInitializing(void);
	virtual void OnActionPerformed(const Osp::Ui::Control& source, int actionId);
};

#endif	//_BASEFORM_H_
