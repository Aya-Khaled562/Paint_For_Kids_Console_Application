#pragma once
#include "Action.h"
class ActionToPlay : public Action
{
private:
public:
	ActionToPlay(ApplicationManager* pMan);
	virtual void Execute();

};
