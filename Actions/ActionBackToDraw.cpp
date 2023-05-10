#include "ActionBackToDraw.h"
#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"
#include "ActionLoad.h"

ActionBackToDraw::ActionBackToDraw(ApplicationManager* pApp):Action(pApp)
{
}

void ActionBackToDraw::Execute()
{
	GUI* pGUI = pManager->GetGUI();
	pGUI->ClearToolBar();
	pGUI->CreateDrawToolBar();
	if (UI.InterfaceMode == MODE_PLAY) {
		Action* loadAct = new ActionLoad(pManager);
		loadAct->Execute();
	}

	pGUI->PrintMessage("Back to Draw mode");
	UI.InterfaceMode = MODE_DRAW;
}
