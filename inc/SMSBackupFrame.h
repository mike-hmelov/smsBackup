
#ifndef _SMSBACKUPFRAME_H_
#define _SMSBACKUPFRAME_H_

#include <FBase.h>
#include <FUi.h>



class SMSBackupFrame :
	public Osp::Ui::Controls::Form,
 	public Osp::Ui::IActionEventListener
{

// Construction
public:
	SMSBackupFrame(void);
	virtual ~SMSBackupFrame(void);
	bool Initialize();
	result OnInitializing(void);
	result OnTerminating(void);

// Implementation
protected:

// Generated call-back functions
public:


	virtual void OnActionPerformed(const Osp::Ui::Control &source, int actionId);

private:
	void OnBackupButtonClick();

};

#endif
