#include "Truck.h"

Truck::Truck()
{
}
Truck::Truck(char typ, int tc, int mt, int v)
{
	setTYP(typ);							// truck type
	setTC(tc);								// truck capacity
	setMT(mt);								// checkup time
	setV(v);								// velocity
	setN(0);								// number of trucks
}
void Truck::addCargo(Cargo C)
{
	Q.enqueue(C);
	setN(++N);
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
