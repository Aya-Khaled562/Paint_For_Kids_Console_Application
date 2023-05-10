#include "ApplicationManager.h"
#include "Actions/ActionAddSquare.h"
#include "Actions/ActionAddEllipse.h"
#include "Actions/ActionAddHex.h"
#include "Actions/ActionFillColor.h"
#include "Actions/ActionChngBgColor.h"
#include "Actions/ActionDrawColor.h"
#include "Actions/ActionSelect.h"
#include"Actions/ActionResize.h"
#include "Actions\ActionSendBack.h"
#include "Actions\ActionBringFront.h"
#include "ActionDelete.h"
#include"Actions/ActionSave.h"
#include"Actions/ActionLoad.h"
#include "Actions/ActionToPlay.h"
#include "Actions/ActionBackToDraw.h"
#include "Actions/ActionSwitchToDrawMode.h"
#include "Actions/ActionExit.h"
#include "Actions/ActionPickByType.h"
#include "Actions/ActionPickByColor.h"
#include "Actions/ActionPickByTypeAndColor.h"
#include <iostream>
#include <fstream>
#include <string>
//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pGUI = new GUI;	
	
	FigCount = 0;
		
	//Create an array of figure pointers and set them to NULL		
	for(int i=0; i<MaxFigCount; i++)
		FigList[i] = NULL;	
}

void ApplicationManager::Run()
{
	ActionType ActType;
	do
	{		
		//1- Read user action
		ActType = pGUI->MapInputToActionType();

		//2- Create the corresponding Action
		Action *pAct = CreateAction(ActType);
		
		//3- Execute the action
		ExecuteAction(pAct);

		//4- Update the interface
		UpdateInterface();	

	}while(ActType != EXIT);
	
}


//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
//Creates an action
Action* ApplicationManager::CreateAction(ActionType ActType) 
{
	Action* newAct = NULL;
	
	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
		case DRAW_SQUARE:
			newAct = new ActionAddSquare(this);
			break;

		case DRAW_ELPS:
			///create AddLineAction here
			newAct = new ActionAddEllipse(this);
			break;
		case DRAW_HEX:
			newAct = new ActionAddHex(this);
			break;
		case CHNG_FILL_CLR:
			newAct=new ActionFillColor(this);
			break;
		case CHNG_DRAW_CLR:
			newAct = new ActionDrawColor(this);
			break;
		case CHNG_BK_CLR:
			newAct = new ActionChngBgColor(this);
			break;
	
		case DRAWING_AREA:
			newAct = new ActionSelect(this);
			break;
			
		case SAVE:
			newAct = new ActionSave(this);
			break;
		
		case LOAD:
			newAct = new ActionLoad(this);
						
			break;

		case RESIZE:
			newAct = new ActionResize(this, SelectedFig);
			break;

		case BRNG_FRNT:
			newAct = new ActionBringFront(this);
			break;

		case SEND_BACK:
			newAct = new ActionSendBack(this);
			break;

		case GO_BACK:
			newAct = new ActionBackToDraw(this);
			break;
		case DEL:
			newAct = new ActionDelete(this);
			break;
		case TO_PLAY:
			newAct = new ActionToPlay(this);
			break;
		case TO_DRAW:
			newAct = new ActionSwitchToDrawMode(this);
			break;
		case P_BY_Shape:
			newAct = new ActionPickByType(this);
			break;
		case P_BY_COLOR:
			newAct = new ActionPickByColor(this);
			break;
		case P_BY_BOTH:
			newAct = new PickByTypeAndColor(this);
			break;
		case EXIT:
			newAct = new ActionExit(this);
			break;
		
		case STATUS:	//a click on the status bar ==> no action
			return NULL;
			break;

	}	
	return newAct;
}
//////////////////////////////////////////////////////////////////////
//Executes the created Action
void ApplicationManager::ExecuteAction(Action* &pAct) 
{	
	//Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//Action is not needed any more ==> delete it
		pAct = NULL;
	}
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//
//Add a figure to the list of figures
int* ApplicationManager::getSelectedFigCount() {
	return &selectedFigCount;

};
//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if(FigCount < MaxFigCount )
		FigList[FigCount++] = pFig;	
}
////////////////////////////////////////////////////////////////////////////////////
CFigure *ApplicationManager::GetFigure(int x, int y) const
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL


	///Add your code here to search for a figure given a point x,y	
	for (int i = FigCount - 1; i >= 0; i--)
		if (FigList[i]->HiddenStatus() == false) {

			if (FigList[i]->Get(x, y))
				return FigList[i];
		}
	return NULL;

	
}
//////////////////////////////////////////////////////////////////
CFigure* ApplicationManager::GetSelectedFigure() const
{
	//check if a figure selected
	for (int i = (FigCount - 1); i >= 0; i--) {
		if (FigList[i]->IsSelected()) return FigList[i];
	}
	return NULL;
}
//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{
	pGUI->ClearDrawArea();
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->HiddenStatus() == false)
			FigList[i]->DrawMe(pGUI);        //Call Draw function (virtual member fn)
	}
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the interface
GUI *ApplicationManager::GetGUI() const
{	return pGUI; }


CFigure** ApplicationManager::getFigList()
{
	return FigList;
}
int ApplicationManager::getFigCount()
{
	return FigCount;
}
int* ApplicationManager::getFigsCount() {
	return &FigCount;
}

void ApplicationManager::fillSelectedFig(color c)
{


	CFigure** list = getFigList();
	int figCount = getFigCount();
	for (int i = 0; i < figCount; i++)
	{
		if (list[i]->IsSelected())
		{
			list[i]->ChngFillClr(c);

		}


	}
	UpdateInterface();
}
void ApplicationManager::drwSelectedFig(color c)
{


	CFigure** list = getFigList();
	int figCount = getFigCount();
	for (int i = 0; i < figCount; i++)
	{
		if (list[i]->IsSelected())
		{
			list[i]->ChngDrawClr(c);
			list[i]->SetSelected(false);

		}


	}
	UpdateInterface();
}


void ApplicationManager::SaveAll(ofstream& outputfile)
{
	if (outputfile.is_open())
	{
		outputfile << to_string(FigCount) << "\n";

		for (int i = 0; i < FigCount; i++)
		{
			FigList[i]->Save(outputfile);
		}
	}


}

//==================================================================================//
//							Bring To Front											//
//==================================================================================//

void ApplicationManager::BringToFront(int selectedIndex)
{
	if (selectedIndex != FigCount - 1)
	{
		for (int i = selectedIndex; i < FigCount - 1; i++)
		{
			CFigure* temp = FigList[i];
			FigList[i] = FigList[i + 1];
			FigList[i + 1] = temp;
		}

	}
}

//==================================================================================//
//							Send To Back											//
//==================================================================================//

void ApplicationManager::SendToBack(int selectedIndex)
{
	if (selectedIndex != 0)
	{
		for (int i = selectedIndex; i > 0; i--)
		{
			CFigure* temp = FigList[i];
			FigList[i] = FigList[i - 1];
			FigList[i - 1] = temp;
		}
	}
}


//==================================================================================//
//							Resize section 							//
//==================================================================================//

// handle load action

void ApplicationManager::Save_load()
{
		 
	
		pGUI->PrintMessage("do you want to save current paint Y/N");

		string confirm = pGUI->GetSrting();

		if (confirm == "y" || confirm == "Y")
		{
			Action* act = new ActionSave(this);

			ExecuteAction(act);

			


		}
		
			pGUI->ClearDrawArea();
		

}
	
	
	

 


void ApplicationManager::ClearFigList()
{
	for (int i = 0; i < MaxFigCount; i++)
		FigList[i] = NULL;
	    FigCount = 0;
}
int ApplicationManager::getSelectedFigure()
{

	for (int i = 0; i < FigCount; i++)
		if (FigList[i]->IsSelected())
			return i;
	return -1;
}
////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<FigCount; i++)
		delete FigList[i];
	delete pGUI;
	
}
// Play mode
CFigure* ApplicationManager::DrawnFigs(int i) const
{
	return FigList[i];
}

