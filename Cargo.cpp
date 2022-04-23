#include "Cargo.h"

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
char Cargo::getTYP()
{
	return TYP;
}
int Cargo::getID()
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
Cargo::~Cargo()
{
}
