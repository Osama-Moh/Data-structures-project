#include "Truck.h"

Truck::Truck()
{
}
Truck::Truck(char typ, int tc, int mt, int v, int n, int id)
{
	setTYP(typ);						
	setTC(tc);								
	setMT(mt);	   
	setDT(0);
	setV(v);								
	setN(n);
	setID(id);
}
void Truck::loadCargo(Cargo* C)
{
	QL.enqueue(C,1);
	if (QL.getcount() == TC)
		while (QL.dequeue(C))
			QM.enqueue(C,1);

}
void Truck::unloadCargo(Cargo* C)
{
	QM.dequeue(C);
}
bool Truck::hasCargo(Cargo* C)
{
	return true;
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
	DT=dt;
}
void Truck::setV(int v)
{
	V=v;
}
void Truck::setN(int n)
{
	N=n;
}
void Truck::setID(int id)
{
	ID=id;
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
int Truck::getID()
{
	return ID;
}
Truck::~Truck(void)
{
}

ostream& operator<<(ostream& print, const Truck& tr)
{
	print << tr.ID << endl;
	return print;
}
