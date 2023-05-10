#include "CEllipse.h"
#include "fstream"

CEllipse::CEllipse(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	TopLeftCorner = P1;
	low = P2;
	Center.x = (P1.x + P2.x) / 2;
	Center.y = (P1.y + P2.y) / 2;
	a = abs(TopLeftCorner.x - Center.x);
	b = abs(TopLeftCorner.y - Center.y);
}
CEllipse::CEllipse(){}
bool CEllipse::Get(int x, int y) const
{
	// (x - h) ^ 2 / a ^ 2 + (y - k) ^ 2 / b ^ 2 <= 1
	// center(h,k)
	// a is radius x-axis
	// b is radius y-axis
	if (pow(x - Center.x, 2) / pow(a, 2) + pow(y - Center.y, 2) / pow(b, 2) <= 1)
	{
		return true;
	}
	return false;
}

string CEllipse::ShowFigureDetails() const {
	return
		"ID=" + to_string(ID) + " "
		"| start point(" + to_string(TopLeftCorner.x) + "," + to_string(TopLeftCorner.y) + ") "
		"| end point(" + to_string(low.x) + "," + to_string(low.y) + ") "
		"| center point(" + to_string(Center.x) + "," + to_string(Center.y) + ") "
		"| radius x-axis=" + to_string(a) + " "
		"| radius y-axis=" + to_string(b) + " "
		"| area=" + to_string(M_PI * a * b);
}


void CEllipse::DrawMe(GUI* pGUI) const
{
	
	pGUI->DrawEllipse(TopLeftCorner, low, FigGfxInfo, Selected);
	


}
void CEllipse::Save(ofstream& OutFile)
{
	if (OutFile.is_open())
	{
		OutFile << "Ellips"
			<< "\t" << ID
			<< "\t" << TopLeftCorner.x
			<< "\t" << TopLeftCorner.y
			<< "\t" << low.x
			<< "\t" << low.y
		    << "\t" << ColorToString(this->FigGfxInfo.DrawClr);
			if (!this->FigGfxInfo.isFilled)
				OutFile << "\t" << "NO-FILL";
			else
				OutFile << "\t" << ColorToString(this->FigGfxInfo.FillClr);
			OutFile << "\n";

	}
 }
void CEllipse::Load(ifstream& OutFile)
{
	string drwcolor, fillcolor;
	OutFile >> ID >> TopLeftCorner.x >> TopLeftCorner.y >> low.x >>low.y>> drwcolor >> fillcolor;

	this->Drwcolor = StringToColor(drwcolor);
	if (fillcolor == "NO-FILL")
	{
		this->Isfill = false;

	}
	else
	{
		this->Fillcolor = StringToColor(fillcolor);


	}
	this->Selected = false;
	setGFX();



}

void CEllipse::Resize(float size) {
	this->low.x = this->low.x * size;
	this->low.y = this->low.y * size;

}


