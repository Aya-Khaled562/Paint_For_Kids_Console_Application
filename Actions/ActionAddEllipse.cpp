#include "ActionAddEllipse.h"

#include "..\Figures\CEllipse.h"

#include "..\ApplicationManager.h"

#include "..\GUI\GUI.h"

ActionAddEllipse::ActionAddEllipse(ApplicationManager* pApp) :Action(pApp)
{}

void ActionAddEllipse::Execute()
{
	Point P1, P2;

	//Get a Pointer to the Interface
	GUI* pGUI = pManager->GetGUI();
	GfxInfo ElipGfxInfo;
	if(pGUI->isfilled)
		ElipGfxInfo.isFilled = true;
	else

		ElipGfxInfo.isFilled = false;
	
		
	
		//default is not filled
	//get drawing, filling colors and pen width from the interface
	ElipGfxInfo.DrawClr = pGUI->getCrntDrawColor();
	ElipGfxInfo.FillClr = pGUI->getCrntFillColor();
	ElipGfxInfo.BorderWdth = pGUI->getCrntPenWidth();


	//Step 1 - Read Ellipse data from the user

	pGUI->PrintMessage("New Ellipse: Click at first point");
	//Read 1st point and store in point P1
	pGUI->GetPointClicked(P1.x, P1.y);

	pGUI->PrintMessage("New Ellipse: Click at second point");
	//Read 2nd point and store in point P2
	pGUI->GetPointClicked(P2.x, P2.y);

	pGUI->ClearStatusBar();

	if (P1.y <= UI.ToolBarHeight || P2.y <= UI.ToolBarHeight)
	{
		pGUI->PrintMessage("out drow area  ");
	}
	else
	{
		//Step 2 - prepare Ellipse data
			//User has entered two points P1&P2
			//2.1- Identify the Top left corner of the Ellipse
		Point topLeft;
		topLeft.x = P1.x < P2.x ? P1.x : P2.x;
		topLeft.y = P1.y < P2.y ? P1.y : P2.y;

		Point low;
		low.x = P2.x > P1.x ? P2.x : P1.x;
		low.y = P2.y > P1.y ? P2.y : P1.y;

		//2.2- Calcuate Ellipse side legnth
		//The Ellipse side length would be the longer distance between the two points coordinates
		//int SideLength = max(abs(P1.x - P2.x), abs(P1.y - P2.y));



		//Step 3 - Create a Ellipse with the parameters read from the user

		CEllipse* E = new CEllipse(topLeft, low, ElipGfxInfo);
		//Step 4 - Add the Ellipse to the list of figures
		pManager->AddFigure(E);
	}

	

}
