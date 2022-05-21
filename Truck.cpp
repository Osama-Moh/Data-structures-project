#include "Truck.h"
# include <iostream>
Truck::Truck()
{
}
Truck::Truck(char typ, int tc, int mt, int v, int n, int id)
{
	setTYP(typ);						
	setTC(tc);								
	setMT(mt);	   
	//setDT(0);
	setV(v);								
	setN(n);
	setID(id);
}
void Truck::loadCargo(Cargo* C)
{
	QL.enqueue(C,1);
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
void Truck::setDT()
{
	DT = (furthercargo / V) * 2 + totalunloading;
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
void Truck::setCOUNT(int count)
{
	COUNT = count;
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
int Truck::getID() const
{
	return ID;
}
int Truck::getCOUNT()
{
	return COUNT;
}
Truck::~Truck()
{
}
void Truck::Move()
{
	Cargo* C = nullptr;
	while (QL.dequeue(C))
		QM.enqueue(C, C->getDIST());
}

bool Truck::isFull()
{
	return getTC() == QL.getcount();
}

ostream& operator << (ostream& out, const Truck& T)
{
	out << T.getID();
	return out;
}

void Truck::setRTIME(int sd,int sh, int dt)
{
		RDAY = sd + ((sh+dt)/24);
		RHOUR = (sh + (dt % 24))%24;
}

int Truck::getRDAY()
{
	return RDAY;
}

int Truck::getRHOUR()
{
	return RHOUR;
}

void Truck::setFTIME(int duration, int sd, int sh)
{
	if ((duration+sh)<  24)
	{
		FDAY = sd;
		FHOUR = duration + sh;
	}
	else if ((duration+sh) == 24)
	{
		FHOUR = 00;
		FDAY = sd + 1;
	}
	else if ((duration + sh) > 24)
	{
		FHOUR = (duration + sh) - 24;
		FDAY = sd + 1;
	}
}

int Truck::getFDAY()
{
	return FDAY;
}

int Truck::getFHOUR()
{
	return FHOUR;
}

void Truck::settotalunloading(int l)
{
	totalunloading = totalunloading + l;
}

int Truck::gettotalunloading()
{
	return totalunloading;
}

void Truck::setfurthercargo(int fc)
{
	if (fc > furthercargo)
	{
		furthercargo = fc;
	}
}

int Truck::getfurthercargo()
{
	return furthercargo;
}

