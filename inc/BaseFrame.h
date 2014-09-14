/*
 * BaseFrame.h
 *
 *  Created on: 14.09.2014
 *      Author: пусик
 */

#ifndef BASEFRAME_H_
#define BASEFRAME_H_

#include <FBase.h>
#include <FUi.h>

class BaseFrame : public Osp::Ui::Controls::Form
{
public:
	virtual ~BaseFrame(void);
protected:
	void InitializeButton(Osp::Ui::Controls::Button*& button, const Osp::Base::String& id,
			const int actionId, const Osp::Ui::IActionEventListener& listener) const;
};

#endif /* BASEFRAME_H_ */
