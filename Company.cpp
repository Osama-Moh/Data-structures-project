# include <iostream>
using namespace std;
# include <string>
# include "Company.h"
# include "Truck.h"

Company::Company()
{

}

void Company::simulate()
{	
	Event* ptr;
	openinput();
	int nn = events.getcount();
	point->print1();
	point->print2(nt, st, vt, ns, ss, vs, NTC, STC, VTC, J, CN, CS, CV, AutoP, MaxW,nn);
	//point->print3(E, ev, typ, day , hour, id, dist, lt, cost);
	int hours = 00;
	int days = 1;
	while (events.peek(ptr))		
	{
		while (ptr->getDay() == days && ptr->getHour() == hours)
		{
			events.dequeue(ptr);
			ptr->Execute(this);
			events.peek(ptr);

		}
		int nsn = SC.getcount();
		int vsv = VC.getcount();
		int ncc = NC.getCount();
		int n = NT.getcount() + ST.getcount() + VT.getcount();
		point->printmode(n,ncc,nsn,vsv, hours, days);
		hours++;
		if (hours == 24)
		{
			hours = 00;
			days++;
		}
	}
	openoutput();
}

void Company::filltruckdata()
{
	for (int i = 1; i <= nt; i++)
	{
		Truck* pointern = new Truck;
		NT.enqueue(pointern,1);
		pointern->setTYP('N');
		pointern->setN(J);
		pointern->setV(ns);
		pointern->setTC(NTC);
		pointern->setMT(CN);
		
	}
	for (int j = 1; j <= st; j++)
	{
		Truck* pointers = new Truck;
		ST.enqueue(pointers,1);
		pointers->setN(J);
		pointers->setTYP('S');
		pointers->setV(ss);
		pointers->setTC(STC);
		pointers->setMT(CS);
	}
	for (int k = 1; k <= vt; k++)
	{
		Truck* pointerv = new Truck;
		VT.enqueue(pointerv,1);
		pointerv->setTYP('V');
		pointerv->setN(J);
		pointerv->setV(vs);
		pointerv->setTC(VTC);
		pointerv->setMT(CV);
	}
}

void Company::readtruckdata()
{
	input >> nt >> st >> vt >> ns >> ss >> vs >> NTC >> STC >> VTC >> J >> CN >> CS >> CV >> AutoP >> MaxW;
}

void Company::readevents()
{
	input >> E;
	for (int i = 1; i <= E; i++)
	{
		input >> ev;
		if (ev == 'R')
		{
			input >> typ >> day >> colon >> hour >> id >> dist >> lt >> cost;
		}
		if (ev == 'X')
		{
			input >> day >> colon >> hour >> id;
		}
		if (ev == 'P')
		{
			input >> day >> colon >> hour >> id >> cost;
		}
		filleventsdata();
	}
}

void Company::filleventsdata()
{
	Event* pointer;
	if (ev == 'R')
	{
		pointer = new PreparationEvent(typ, id, day, hour, lt, dist, cost);
		events.enqueue(pointer,1);
	}
	if (ev == 'X')
	{
		pointer = new CancellationEvent(id, day, hour);
		events.enqueue(pointer, 1);
	}
	if (ev == 'P')
	{
		pointer = new PromotionEvent(id, day, hour, cost);
		events.enqueue(pointer, 1);
	}
}

void Company::addCargo(Cargo* S)
{
	if (S->getTYP() == 'N')
		NC.InsertBeg(S);
	if (S->getTYP() == 'S')
		SC.enqueue(S,S->getPRIORITY());
	if (S->getTYP() == 'V')
		VC.enqueue(S,S->getPRIORITY());
}

Cargo* Company::removeCargo(int ID)
{
	return NC.removeCargo(ID);
}

void Company::promoteCargo(int ID, int ExtraCost)
{
	Cargo* S = removeCargo(ID);
	S->setTYP('V');
	int Cost = S->getCOST() + ExtraCost;
	S->setCOST(Cost);
	addCargo(S);
}

void Company::openinput()
{													// the file name should be a user input
	input.open("data.txt", ios::in);

	if (input.is_open() == true)
	{
		readtruckdata();
		filltruckdata();
		readevents();
	}

}

void Company::openoutput()
{
	output.open("Output.txt", ios::out);
	if (output.is_open() == true)
	{
		writetofile();
	}
}

void Company::writetofile()
{

}