#pragma once
#include "Action.h"
#include "../Figures/CFigure.h"

class ActionPickByType : public Action
{
	CFigure* Fig;
	Point P;
	int figuresNumber, pickedFigNumber, numberOfWrongFig, numberOfRightFig, randomFigNumber;
	int FigsList[4];
	void PrintScore(int);

	public:
		ActionPickByType(ApplicationManager*);
		void ReadActionParameters();
		void Execute();
};