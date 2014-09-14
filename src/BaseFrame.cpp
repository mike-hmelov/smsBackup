/*
 * BaseFrame.cpp
 *
 *  Created on: 14.09.2014
 *      Author: пусик
 */

#include "BaseFrame.h"

using namespace Osp::Base;
using namespace Osp::Ui::Controls;

BaseFrame::~BaseFrame()
{
}

void BaseFrame::InitializeButton(Button*& button, const String& id, const int commandId, const Osp::Ui::IActionEventListener& listener) const
{
	button = static_cast<Button *> (GetControl(id));
	button->SetActionId(commandId);
	button->AddActionEventListener(listener);
}
