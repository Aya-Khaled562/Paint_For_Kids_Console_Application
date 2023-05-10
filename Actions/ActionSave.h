#pragma once
#include "Action.h"
#include<string>
#include<fstream>
class ActionSave :public Action
{
	string FileName;
public:
	ActionSave(ApplicationManager* pApp);
	virtual void Execute();
	void ReadFileName();

	string ColorToString(color c);

};

