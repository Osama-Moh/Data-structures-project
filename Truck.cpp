#include "Truck.h"

Truck::Truck()
{
}
Truck::Truck(char typ, int tc, int mt, int v)
{
	setTYP(typ);						
	setTC(tc);								
	setMT(mt);	   
	setDT(0);
	setV(v);								
	setN(0);								
}
void Truck::loadCargo(Cargo* C)
{
	Q.enqueue(C,1);
	setN(++N);
}
void Truck::unloadCargo(Cargo* C)
{
	Q.dequeue(C);
	setN(--N);
}
void Truck::setTYP(char typ)					
{
	TYP=typ;
}
void Truck::setTC(int tc)
{
	TC=tc;
}
void Truck::setMT(int mt)
{
	MT=mt;
}
void Truck::setDT(int dt)
{
	DT=dt;					// DT=(distance to deliver furthest cargo)/(V)+
}
void Truck::setV(int v)
{
	V=v;
}
void Truck::setN(int n)
{
	N=n;
}
char Truck::getTYP()
{
	return TYP;
}
int Truck::getTC()
{
	return TC;
}
int Truck::getMT()
{
	return MT;
}
int Truck::getDT()
{
	return DT;
}
int Truck::getV()
{
	return V;
}
int Truck::getN()
{
	return N;
}
Truck::~Truck(void)
{
}

ostream& operator<<(ostream& print, const Truck& tr)
{
	print << tr.id << endl;
	return print;
}
