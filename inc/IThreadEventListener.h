/*
 * IThreadEventListener.h
 *
 *  Created on: 16.09.2014
 *      Author: пусик
 */

#ifndef ITHREADEVENTLISTENER_H_
#define ITHREADEVENTLISTENER_H_

#include <FBaseRtIEventListener.h>

class IThreadEventListener : public Osp::Base::Runtime::IEventListener
{
public:
	IThreadEventListener();
	virtual ~IThreadEventListener();

	virtual void OnProgress(int progress) = 0;
	virtual void OnStop() = 0;
};

#endif /* ITHREADEVENTLISTENER_H_ */
