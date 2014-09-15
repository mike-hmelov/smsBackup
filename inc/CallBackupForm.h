
#ifndef _CALLBACKUPFORM_H_
#define _CALLBACKUPFORM_H_

#include <FBase.h>
#include <FUi.h>
#include "BaseForm.h"


class CallBackupForm :
	public BaseForm
{

// Construction
public:
	CallBackupForm(void);
	virtual ~CallBackupForm(void);
	bool Initialize();
	result OnInitializing(void);
	result OnTerminating(void);

// Implementation
protected:

// Generated call-back functions
public:

};

#endif
