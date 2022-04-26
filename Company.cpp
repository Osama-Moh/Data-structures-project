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
	openinput();
	point->print1();
	point->print2(nt, st, vt, ns, ss, vs, NTC, STC, VTC, J, CN, CS, CV, AutoP, MaxW,0);
	point->print3(E, ev, typ, day , hour, id, dist, lt, cost);

	int hours = 00;
	int days = 1;
	while (days<2)					// while true (this condition will be changed but i make it this way in order to make basic tests
	{
		int n = NT.getcount() + ST.getcount() + VT.getcount();
		point->printmode(n, hours, days);

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
	int x;
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
			//input >> et >> id;
		}
		if (ev == 'P')
		{
			//input >> et >> id >> cost;
		}
		filleventsdata();
	}
}

void Company::filleventsdata()
{
	if (ev == 'R')
	{
		PreparationEvent* pointerr = new PreparationEvent;
		rv.enqueue(pointerr,1);
		pointerr->setCost(cost);
		pointerr->setDist(dist);
		pointerr->setID(id);
		pointerr->setLoad(lt);
		pointerr->setType(typ);
	}
	if (ev == 'X')
	{
		CancellationEvent* pointerc = new CancellationEvent;
		cv.enqueue(pointerc,1);
		pointerc->setID(id);
	}
	if (ev == 'P')
	{
		PromotionEvent* pointerp = new PromotionEvent;
		pv.enqueue(pointerp,1);
		pointerp->setExtraCost(cost);
		pointerp->setID(id);
	}

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

void Company::print()			// isa will be deleted
{

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