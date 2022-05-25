#include "Cargo.h"
# include <iostream>
using namespace std;

Cargo::Cargo()
{
}
Cargo::Cargo(char typ, int id, int ptd, int pth, int lt, int dist, int cost)
{
	setTYP(typ);
	setID(id);
	setPTD(ptd);
	setPTH(pth);
	setLT(lt);
	setDIST(dist);
	setCOST(cost);
}
void Cargo::setTYP(char typ)
{
	TYP=typ;
}
void Cargo::setID(int id)
{
	ID=id;
}
void Cargo::setPTD(int ptd)
{
	PTD=ptd;
}
void Cargo::setPTH(int pth)
{
	PTH=pth;
}
void Cargo::setLT(int lt)
{
	LT=lt;
}
void Cargo::setDIST(int dist)
{
	DIST=dist;
}
void Cargo::setCOST(int cost)
{
	COST=cost;
}
void Cargo::setCDT(int days, int hours, int speed, int distance)
{
	CDT = (24 * days + hours) + (distance / speed) + LT;
	CDTD = CDT / 24;
	CDTH = CDT % 24;
}
char Cargo::getTYP()
{
	return TYP;
}
int Cargo::getID() const
{
	return ID;
}
int Cargo::getPTD()
{
	return PTD;
}
int Cargo::getPTH()
{
	return PTH;
}
int Cargo::getLT()
{
	return LT;
}
int Cargo::getDIST()
{
	return DIST;
}
int Cargo::getCOST()
{
	return COST;
}
float Cargo::getPRIORITY()
{
	return TYP == 'V' ? float((COST*COST)/((24*PTD+PTH)*(DIST*LT))) : 0;
}
Cargo::~Cargo()
{
	
}
ostream& operator << (ostream& out,const Cargo& C)
{
	out << C.getID();
	return out;
}
int Cargo::getCDT()
{
	return CDT;
}

void Cargo::setWT(int SD, int SH)
{
	WT = (SD * 24 + SH) - (PTD * 24 + PTH);
	WTD = WT / 24;
	WTH = WT % 24;
}

int Cargo::getWT()
{
	return WT;
}

void Cargo::setTID(int id)
{
	TID = id;
}

int Cargo::getTID()
{
	return TID;
}

int Cargo::getWTD()
{
	return WTD;
}

int Cargo::getWTH()
{
	return WTH;
}

int Cargo::getCDTD()
{
	return CDTD;
}

int Cargo::getCDTH()
{
	return CDTH;
}