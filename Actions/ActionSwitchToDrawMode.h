

#include "Action.h"

//Add Switch to draw mode Action class
class ActionSwitchToDrawMode : public Action
{
public:
	ActionSwitchToDrawMode(ApplicationManager* pApp);

	virtual void Execute();

};

