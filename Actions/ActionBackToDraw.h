#ifndef ACTION_SWITCH_TO_DRAW_MODE_H
#define ACTION_SWITCH_TO_DRAW_MODE_H

#include "Action.h"

//Add Switch to draw mode Action class
class ActionBackToDraw : public Action
{
public:
	ActionBackToDraw(ApplicationManager* pApp);

	virtual void Execute();

};

#endif