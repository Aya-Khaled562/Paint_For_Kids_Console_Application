#include "ActionDelete.h"
#include "GUI/GUI.h"
#include "ApplicationManager.h"

ActionDelete::ActionDelete(ApplicationManager* pApp):Action(pApp)
{
}


void ActionDelete::Execute()
{

	GUI* pGUI = pManager->GetGUI();
	int* Figs = pManager->getFigsCount();
	CFigure** FigsList = pManager->getFigList();
	int figSelectFlag = 0;
	for (int i = 0; i < *Figs; i++) {
		if (FigsList[i]->IsSelected())
		{
			delete FigsList[i];
			*Figs = *Figs - 1;
			figSelectFlag = 1;
			for (int j = i; j < *Figs; j++) {
				FigsList[j] = FigsList[j + 1];
			}
			i--;
		}
	}
	if (figSelectFlag == 1) {
		if (UI.InterfaceMode == MODE_DRAW)
			pGUI->PrintMessage("Figure Deleted");
		pGUI->ClearDrawArea();
		pManager->UpdateInterface();
	}
	else {
		pGUI->PrintMessage("Please Select A Figure ...");
	}
}

