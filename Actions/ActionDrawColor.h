#pragma once
#include "Action.h"

class ActionDrawColor :public Action
{
public:
	ActionDrawColor(ApplicationManager* pApp);

	virtual void Execute();

};


