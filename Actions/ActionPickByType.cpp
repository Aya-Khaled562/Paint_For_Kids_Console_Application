#include "ActionPickByType.h"
#include "../ApplicationManager.h"
#include "../Figures/CEllipse.h"
#include "../Figures/CHex.h"
#include "../Figures/CSquare.h"

ActionPickByType::ActionPickByType(ApplicationManager* pApp) :Action(pApp)
{
	figuresNumber = 0;
	numberOfRightFig = 0;
	numberOfWrongFig = 0;
	for (int i = 0; i < 4; i++)
		FigsList[i] = 0;
}

void ActionPickByType::PrintScore(int score)
{
	GUI* pGUI = pManager->GetGUI();
	string message;

	if (score == 1) 
	{
		numberOfRightFig++;
		message = "Right!, Your score is: " + to_string(numberOfRightFig) + " Right, and " + to_string(numberOfWrongFig) + " Wrong.";

	}
	else if (score == 2)
	{
		numberOfWrongFig++;
		message = "Wrong!, Your score is: " + to_string(numberOfRightFig) + " Right, and " + to_string(numberOfWrongFig) + " Wrong.";
	}
	else if (pickedFigNumber == 0 && numberOfRightFig > numberOfWrongFig)
	{
		message = "YOU WIN!, Your score is: " + to_string(numberOfRightFig) + " Right, and " + to_string(numberOfWrongFig) + " Wrong.";
	}
	else
		message = "YOU LOSE!, Your score is: " + to_string(numberOfRightFig) + " Right, and " + to_string(numberOfWrongFig) + " Wrong.";
	pGUI->PrintMessage(message);
}

void ActionPickByType::ReadActionParameters()
{
	for (int i = 0; i < pManager->getFigCount(); i++)
	{
		Fig = pManager->DrawnFigs(i);

		if (dynamic_cast<CEllipse*>(Fig))
			FigsList[0]++;

		else if (dynamic_cast<CHex*>(Fig))
			FigsList[1]++;

		else FigsList[2]++;
	}

	for (int i = 0; i < 4; i++)
		if (FigsList[i] != 0)figuresNumber++;
}

void ActionPickByType::Execute()
{
	GUI* pGUI = pManager->GetGUI();
	ReadActionParameters();
	if (figuresNumber > 1)
	{
		CFigure* clickedFig;
		randomFigNumber = rand() % pManager->getFigCount();

		Fig = pManager->DrawnFigs(randomFigNumber);
		if (dynamic_cast<CEllipse*>(Fig))
		{
			pickedFigNumber = FigsList[0];
			pGUI->PrintMessage("Pick all Ellips");
		}
		else if (dynamic_cast<CHex*>(Fig))
		{
			pickedFigNumber = FigsList[1];
			pGUI->PrintMessage("Pick all Hexagons");
		}
		
		else
		{
			pickedFigNumber = FigsList[2];
			pGUI->PrintMessage("Pick all Squares");
		}

		while (pickedFigNumber > 0)
		{
			pGUI->GetPointClicked(P.x, P.y);
			if (P.y > UI.ToolBarHeight || P.x > (UI.MenuItemWidth * PLAY_ITM_COUNT))
			{
				clickedFig = pManager->GetFigure(P.x, P.y);
				if (clickedFig != NULL)
				{
					if (dynamic_cast<CEllipse*>(Fig) && dynamic_cast<CEllipse*>(clickedFig))
					{
						PrintScore(1);
						clickedFig->Hide();
						pManager->UpdateInterface();
						pickedFigNumber--;
					}
					else if (dynamic_cast<CHex*>(Fig) && dynamic_cast<CHex*>(clickedFig))
					{
						PrintScore(1);
						clickedFig->Hide();
						pManager->UpdateInterface();
						pickedFigNumber--;
					}
					
					else if (dynamic_cast<CSquare*>(Fig) && dynamic_cast<CSquare*>(clickedFig))
					{
						PrintScore(1);
						clickedFig->Hide();
						pManager->UpdateInterface();
						pickedFigNumber--;
					}
					else 
					{
						PrintScore(2);
						clickedFig->Hide();
						pManager->UpdateInterface();
					}
				}
			}
			else
			{
				pGUI->PrintMessage("Toolbar clicked, game aborted.");
				pickedFigNumber = -1;
			}
			if (pickedFigNumber == 0)
				PrintScore(3);
		}
	}
	else
	{
		pGUI->PrintMessage("You must have at least two or more figures to play to play pick by figure!");
	}
	for (int i = 0; i < pManager->getFigCount(); i++)
		pManager->DrawnFigs(i)->Show();
	pManager->UpdateInterface();
}