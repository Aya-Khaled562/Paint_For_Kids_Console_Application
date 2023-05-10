#include "ActionDrawColor.h"
#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"
#include "Action.h"
#include "..\Figures\CFigure.h"


ActionDrawColor::ActionDrawColor(ApplicationManager* pApp) :Action(pApp)
{}


void ActionDrawColor::Execute() {

	GUI* pGUI = pManager->GetGUI();
	pGUI->PrintMessage(" Click at color to draw shape");

	pGUI->CreateColorMenu();


	COLORSITEM s = pGUI->getcolor();
	if (s != EMPTYY)
	{
		switch (s)
		{
		case RED1: {
			pGUI->PrintMessage("the draw color set to RED");
			pGUI->isDrawed = true;
			pGUI->SetDrawColor(RED);
			pManager->drwSelectedFig(RED);
			break;
		}
		

		case GREEN2:
		{
			pGUI->PrintMessage("the draw color set to green");
			pGUI->isDrawed = true;
			pGUI->SetDrawColor(GREEN);
			pManager->drwSelectedFig(GREEN);

			pManager->drwSelectedFig(GREEN);
			break;
		}
		

		case YELLOW3:
		{
			pGUI->PrintMessage("the draw color set to YELLOW");
			pGUI->isDrawed = true;
			pGUI->SetDrawColor(YELLOW);
			pManager->drwSelectedFig(YELLOW);
			break;
		}
		case defaultcolor:
		{
			pGUI->PrintMessage("the draw color set to default");
			pGUI->SetDrawColor(BLUE);
			pManager->drwSelectedFig(BLUE);
			pGUI->isDrawed = false;
		}
		break;
		case BLUE5:
		{
			pGUI->PrintMessage("the draw color set to BLUE");
			pGUI->SetDrawColor(BLUE);
			pManager->drwSelectedFig(BLUE);

			pGUI->isDrawed = true;
			pGUI->SetDrawColor(BLUE);
			pManager->drwSelectedFig(BLUE);
			break;
		}
		case EMPTYY:
			break;
		default:
			break;
		}
		pGUI->ClearColorMenu();

	}

}


