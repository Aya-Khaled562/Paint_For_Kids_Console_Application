#pragma once
#include "Action.h"
class ActionLoad :public Action
{
	string FileName;
public:
	ActionLoad(ApplicationManager* pMan); // constructor

	virtual void Execute();
	void ReadFileName();

	
	//string convertToString(color c); //convert from color type to string
	color StringToColor(string s)const;
	void Savecurrent();
};

