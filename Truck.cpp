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
	setV(v);								
	setN(n);
	setID(id);
}
void Truck::loadCargo(Cargo* C)
{
	QL.enqueue(C);
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
	COUNT = COUNT + count;
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
	{
		QM.enqueue(C, C->getDIST());
		C->setWT(SDAY, SHOUR);
		C->setTID(ID);
	}
}

bool Truck::isFull()
{
	return getTC() == QL.getcount();
}

ostream& operator << (ostream& out, const Truck& T)
{
	out << T.getID();
	if ((T.QM).getcount() > 0)
	{
		Cargo* pCargo = nullptr;
		T.getpeek(pCargo);
		if (pCargo->getTYP() == 'N')
		{
			out << '[';
			(T.QM).print();
			out << ']';
		}
		if (pCargo->getTYP() == 'S')
		{
			out << '(';
			(T.QM).print();
			out << ')';
		}
		if (pCargo->getTYP() == 'V')
		{
			out << '{';
			(T.QM).print();
			out << '}';
		}
	}
	return out;
}

void Truck::setRTIME(int sd,int sh)
{
	setDT();
	setactivetime();
	RDAY = sd + ((sh + DT) / 24);
	RHOUR = (sh + (DT % 24)) % 24;
	SDAY = sd;
	SHOUR = sh;
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

int Truck::getLoadedCount()
{
	return QL.getcount();
}

bool Truck::getpeek(Cargo*& C1) const
{
	if (QM.peek(C1))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Truck::printloadingcargos()
{
	QL.print();
}

void Truck::printmovingcargos()
{
	QM.print();
}
void Truck::setactivetime()
{
	setDT();
	activetime = DT - (furthercargo / V);
}

int Truck::getactivetime()
{
	return activetime;
}

void Truck::settripcount()
{
	tripcount++;
}

int Truck::gettripcount()
{
	return tripcount;
}

void Truck::settotalcargos(int c)
{
	totalcargos = totalcargos + c;
}

int Truck::gettotalcargos()
{
	return totalcargos;
}

int Truck::getmovingcargos()
{
	return QM.getcount();
}