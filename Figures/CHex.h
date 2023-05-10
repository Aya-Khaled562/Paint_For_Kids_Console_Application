#pragma once
#include "CFigure.h"

class CHex :public CFigure
{
	Point TopLeft;
	int Llen;
	int Rlen;
	int length;
	Point Center;
	static int hexCount;

public:

	CHex(Point,int,int, GfxInfo GfxInfo);

	CHex();

	virtual void DrawMe(GUI* pOut) const;
	virtual string ShowFigureDetails() const;
	virtual bool Get(int x, int y) const;
	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& OutFile);
	virtual void Resize(float);
};

