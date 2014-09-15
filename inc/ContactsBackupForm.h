
#ifndef _CONTACTSBACKUPFORM_H_
#define _CONTACTSBACKUPFORM_H_

#include <FBase.h>
#include <FUi.h>
#include "BaseForm.h"



class ContactsBackupForm :
	public BaseForm
{

// Construction
public:
	ContactsBackupForm(void);
	virtual ~ContactsBackupForm(void);
	bool Initialize();
	result OnInitializing(void);
	result OnTerminating(void);

// Implementation
protected:

// Generated call-back functions
public:

};

#endif
