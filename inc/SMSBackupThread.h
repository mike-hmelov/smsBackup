/*
 * SMSBackupThread.h
 *
 *  Created on: 16.09.2014
 *      Author: пусик
 */

#ifndef SMSBACKUPTHREAD_H_
#define SMSBACKUPTHREAD_H_

#include <FBaseRtThreadThread.h>
#include "IThreadEventListener.h"

class SMSBackupThread : public Osp::Base::Runtime::Thread
{
public:
	SMSBackupThread(IThreadEventListener& listener);
	virtual ~SMSBackupThread();

	virtual void OnStop(void);
	virtual Osp::Base::Object* Run(void);

private:
	IThreadEventListener& __listener;
};

#endif /* SMSBACKUPTHREAD_H_ */
