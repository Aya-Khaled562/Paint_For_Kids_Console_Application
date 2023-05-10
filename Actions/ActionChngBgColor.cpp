#include "ActionChngBgColor.h"
#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"
#include "Action.h"
#include "..\Figures\CFigure.h"

ActionChngBgColor::ActionChngBgColor(ApplicationManager* pApp) :Action(pApp)
{
}

void ActionChngBgColor::Execute()
{
	GUI* pGUI = pManager->GetGUI();
	pGUI->PrintMessage(" Click at color to set a Background ");

	//pGUI->ClearToolBar();
	pGUI->CreateColorMenu();



	COLORSITEM s = pGUI->getcolor();
	if (s != EMPTYY)
	{
		
		switch (s)
		{
		case RED1: {
			pGUI->PrintMessage("the Background color set to RED");
			pGUI->SetBgColor(RED);
		   break;
		}

		case GREEN2:
		{
			pGUI->PrintMessage("the Background color set to GREEN");
			pGUI->SetBgColor(GREEN);
		
			break;
		}
		case YELLOW3:
		{
			pGUI->PrintMessage("the Background color set to YELLOW");
			pGUI->SetBgColor(YELLOW);
			
			break;

		}
		case BLUE5:
		{
			pGUI->PrintMessage("the Background color set to BLUE");
			pGUI->SetBgColor(BLUE);
			break;
		}
		case defaultcolor:
		{
			pGUI->PrintMessage("the draw Background set to default");
			pGUI->SetBgColor(LIGHTGOLDENRODYELLOW);
			break;

		}

		case EMPTYY:
			break;
		default:
			break;
		}
		pGUI->ClearDrawArea();
		pGUI->ClearColorMenu();
		UI.InterfaceMode = MODE_DRAW;
		pManager->UpdateInterface();
		
	}
}
