#pragma once
#include "Action.h"

class ActionChngBgColor :public Action
{
public:
	ActionChngBgColor(ApplicationManager* pApp);

	virtual void Execute();

};