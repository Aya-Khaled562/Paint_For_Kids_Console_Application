#include "ActionSwitchToDrawMode.h"
#include "../GUI/GUI.h"
#include "../ApplicationManager.h"

ActionSwitchToDrawMode::ActionSwitchToDrawMode(ApplicationManager* pApp):Action(pApp)
{
}

void ActionSwitchToDrawMode::Execute()
{
	GUI* pGUI = pManager->GetGUI();
	pGUI->ClearToolBar();
	pGUI->CreateDrawToolBar();


	pGUI->PrintMessage("Back to Draw mode");
	UI.InterfaceMode = MODE_DRAW;
}

