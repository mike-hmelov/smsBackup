#ifndef _SMSBACKUPFORM_H_
#define _SMSBACKUPFORM_H_

#include <FBase.h>
#include <FUi.h>
#include "BaseForm.h"
#include "SMSBackupThread.h"

class SMSBackupForm: public BaseForm, public IThreadEventListener
{

	// Construction
public:
	SMSBackupForm(void);
	virtual ~SMSBackupForm(void);
	bool Initialize(void);

	// Implementation
protected:
	static const int SMS_BACKUP_BUTTON = 1001;

public:
	virtual result OnInitializing(void);
	virtual result OnTerminating(void);

	virtual void OnActionPerformed(const Osp::Ui::Control &source, int actionId);
	virtual void OnProgress(int progress);
	virtual void OnStop();

private:
	void BackupSMS();
private:
	Osp::Ui::Controls::Button *__pBackupButton;
	Osp::Ui::Controls::Progress* __pProgressBar;
	SMSBackupThread *__pThread;
};

#endif	//_SMSBACKUPFORM_H_
