#ifndef _SMSBACKUPFORM_H_
#define _SMSBACKUPFORM_H_

#include <FBase.h>
#include <FUi.h>
#include "BaseForm.h"

class SMSBackupForm: public BaseForm
{

	// Construction
public:
	SMSBackupForm(void);
	virtual ~SMSBackupForm(void);
	bool Initialize(void);

	// Implementation
protected:

public:
	virtual result OnInitializing(void);
	virtual result OnTerminating(void);
};

#endif	//_SMSBACKUPFORM_H_
