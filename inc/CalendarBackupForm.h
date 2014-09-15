
#ifndef _CALENDARBACKUPFORM_H_
#define _CALENDARBACKUPFORM_H_

#include <FBase.h>
#include <FUi.h>
#include "BaseForm.h"


class CalendarBackupForm :
	public BaseForm
{

// Construction
public:
	CalendarBackupForm(void);
	virtual ~CalendarBackupForm(void);
	bool Initialize();
	result OnInitializing(void);
	result OnTerminating(void);

// Implementation
protected:

// Generated call-back functions
public:

};

#endif
