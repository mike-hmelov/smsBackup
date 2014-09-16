/*
 * SMSBackupThread.h
 *
 *  Created on: 16.09.2014
 *      Author: пусик
 */

#ifndef SMSBACKUPTHREAD_H_
#define SMSBACKUPTHREAD_H_

#include <FBaseRtThreadThread.h>
#include <FMessaging.h>
#include <FXml.h>
#include "IThreadEventListener.h"

class SMSBackupThread: public Osp::Base::Runtime::Thread, public Osp::Messaging::ISmsListener
{
public:
	SMSBackupThread(IThreadEventListener& listener);
	virtual ~SMSBackupThread();

	virtual void OnStop(void);
	virtual Osp::Base::Object* Run(void);

	virtual void OnSmsMessageSent(result r);
private:
	result InitSMSManager();
	result InitXMLFile();
private:
	IThreadEventListener& __listener;
	Osp::Messaging::SmsManager* __pSmsManager;
	Osp::Xml::xmlTextWriterPtr __pWriter;
};

#endif /* SMSBACKUPTHREAD_H_ */
