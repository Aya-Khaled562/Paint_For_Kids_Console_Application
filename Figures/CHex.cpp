#include "CHex.h"
#include <fstream>

CHex::CHex(Point p1,int len,int rlen, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	TopLeft = p1;
	Llen = len;
	Rlen = rlen;
	
	Center.x = (TopLeft.x + (TopLeft.x + Llen)) / 2;
	Center.y = (TopLeft.y + (TopLeft.y + (2 * Rlen))) / 2;
	

}
CHex::CHex(){}

bool CHex::Get(int x, int y) const
{
	boolean c = false;
	int vertexX[6] = { TopLeft.x, TopLeft.x + Llen , TopLeft.x + (1.5 * Llen), (TopLeft.x + Llen), TopLeft.x, abs(TopLeft.x - (0.5 * Llen)) };
	int vertexY[6] = { TopLeft.y,TopLeft.y, TopLeft.y + Rlen, TopLeft.y + (2 * Rlen), TopLeft.y + (2 * Rlen), abs(TopLeft.y + Rlen) };
	for (int i = 0, j = 6 - 1; i < 6; j = i++)
	{
		if (((vertexY[i] > y) != (vertexY[j] > y))
			&& (x < (vertexX[j] - vertexX[i]) * (y - vertexY[i]) / (vertexY[j] - vertexY[i]) + vertexX[i]))
			c = !c;
	}
	return c;
}

string CHex::ShowFigureDetails() const {
	return
		"ID=" + to_string(ID) + " "
		"| start point(" + to_string(TopLeft.x) + "," + to_string(TopLeft.y) + ") "
		"| end point(" + to_string(TopLeft.x + Llen) + "," + to_string(TopLeft.y + (2 * Rlen)) + ") "
		"| center point(" + to_string(Center.x) + "," + to_string(Center.y) + ") "
		"| radius=" + to_string(Llen) + " "
		"| height=" + to_string(Rlen * 2) + " "
		"| area=" + to_string((3 * pow(Llen, 2) * sqrt(3) / 2));
}

void CHex::DrawMe(GUI* pGUI) const
{

	pGUI->DrawHex(TopLeft, Llen, Rlen, FigGfxInfo, Selected);
	

}
void CHex::Save(ofstream& OutFile)
{
	if (OutFile.is_open())
	{
		OutFile<<"HEXAGON"
			<<"\t"<<ID
			<<"\t"<< TopLeft.x
			<<"\t"<< TopLeft.y
			<< "\t" << Llen
			<<"\t"<< Rlen
			<< "\t" << ColorToString(this->FigGfxInfo.DrawClr);
		if (!this->FigGfxInfo.isFilled)
			OutFile << "\t" << "NO-FILL";
		else
			OutFile << "\t" << ColorToString(this->FigGfxInfo.FillClr);
		OutFile << "\n";
		
	}

 }

void CHex::Resize(float size) {
	this->Llen = this->Llen * size;
	this->Rlen = this->Rlen * size;

}
void CHex::Load(ifstream& OutFile)
{
	string drwcolor, fillcolor;
	OutFile >> ID >> TopLeft.x >> TopLeft.y >> Llen >> Rlen >> drwcolor >> fillcolor;

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
