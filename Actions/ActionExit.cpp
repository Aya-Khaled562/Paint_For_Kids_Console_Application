#include "ActionExit.h"
#include "ActionSave.h"
#include "../ApplicationManager.h"
#include "../GUI/GUI.h"
#include "../GUI/Input.h"
#include "../GUI/Output.h"
#include "String"
ActionExit::ActionExit(ApplicationManager* pApp):Action(pApp)
{
}

void ActionExit::Execute()
{
	GUI* pGUI = pManager->GetGUI();
	pGUI->PrintMessage("If you want ot save your graph before exit Enter (y) OR (Y) else write (N) or (n) ");
	string str = pGUI->GetSrting();
	if (str == "Y" || str == "y") {
		Action* act = new ActionSave(pManager);
		pManager->ExecuteAction(act);
	}
	else
	{
		pGUI->PrintMessage("see you again");
	}
}
