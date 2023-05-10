#include "CSquare.h"
#include <fstream>
#include<iostream>
#include<string.h>

CSquare::CSquare(Point P1, int len, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	TopLeftCorner = P1;
	length = len;
	Center.x = (P1.x + (P1.x + length)) / 2;
	Center.y = (P1.y + (P1.y + length)) / 2;
	
}
CSquare::CSquare() {};
	

void CSquare::DrawMe(GUI* pGUI) const
{
	//Call Output::DrawRect to draw a Square on the screen	
	pGUI->DrawSquare(TopLeftCorner, length, FigGfxInfo, Selected);
	

}

bool CSquare::Get(int x, int y) const
{
	if (x >= TopLeftCorner.x && x <= TopLeftCorner.x + length &&
		y >= TopLeftCorner.y && TopLeftCorner.y + length)
		return true;
	return false;
}

void CSquare::Resize(float size) {
	this->length = this->length * size;

}

string CSquare::ShowFigureDetails() const {
	return
		"ID=" + to_string(ID) + " "
		"| start point(" + to_string(TopLeftCorner.x) + "," + to_string(TopLeftCorner.y) + ") "
		"| end point(" + to_string(TopLeftCorner.x + length) + "," + to_string(TopLeftCorner.y + length) + ") "
		"| center point(" + to_string(Center.x) + "," + to_string(Center.y) + ") "
		"| length=" + to_string(length) +
		"| area=" + to_string(pow(length, 2));
}

void CSquare::Save(ofstream& OutFile)
{
	if (OutFile.is_open())
	{

		OutFile << "SQUARE"
			<< "\t" << ID
			<< "\t" << TopLeftCorner.x
			<< "\t" << TopLeftCorner.y
			<< "\t" << length
			<< "\t" << ColorToString(this->FigGfxInfo.DrawClr);
		if (!this->FigGfxInfo.isFilled)
			OutFile << "\t" << "NO-FILL";
		else

			OutFile << "\t" << ColorToString(this->FigGfxInfo.FillClr);
		OutFile << "\n";
	}
}
void CSquare::Load(ifstream& OutFile)
{

	string drwcolor, fillcolor;
	OutFile >> ID >> TopLeftCorner.x >> TopLeftCorner.y >> length >> drwcolor >> fillcolor;
	
	this->Drwcolor = StringToColor(drwcolor);
	if (fillcolor == "NO-FILL")
	{
		this->Isfill =false;
		
	}
	else
	{
		this->Fillcolor = StringToColor(fillcolor);

			
	}
	this->Selected = false;
	setGFX();
	
	
	
		
	
}