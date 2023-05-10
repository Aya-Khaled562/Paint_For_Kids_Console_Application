#pragma once
#include "Actions/Action.h"




class ActionDelete :public Action
{
	//CFigure* deletedFigure;
public:

	ActionDelete(ApplicationManager*);
	virtual void Execute();
};