/*
 * SMSBackupThread.cpp
 *
 *  Created on: 16.09.2014
 *      Author: пусик
 */

#include "../inc/SMSBackupThread.h"

SMSBackupThread::SMSBackupThread(IThreadEventListener& listener):
__listener(listener)
{
	// TODO Auto-generated constructor stub

}

SMSBackupThread::~SMSBackupThread()
{
	// TODO Auto-generated destructor stub
}

Osp::Base::Object* SMSBackupThread::Run()
{
	__listener.OnProgress(90);
	return null;
}

void SMSBackupThread::OnStop(void)
{
	__listener.OnStop();
}

