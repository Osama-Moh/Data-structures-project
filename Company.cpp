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
	point.print1();
	point.print2(nt, st, vt, ns, ss, vs, NTC, STC, VTC, J, CN, CS, CV, AutoP, MaxW);
	point.print3(E, ev, typ, et, id, dist, lt, cost);
	filltruckdata();

	int hours = 00;
	int days = 1;
	while (days<2)					// while true (this condition will be changed but i make it this way in order to make basic tests
	{
		int n = NT.getcount() + ST.getcount() + VT.getcount();
		point.printmode(n, hours, days);

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
		Truck *pointern;
		NT.enqueue(pointern);
		pointern->setTYP('N');
		pointern->setN(J);
		pointern->setV(ns);
		pointern->setTC(NTC);
		pointern->setMT(CN);
		
	}
	for (int j = 1; j <= st; j++)
	{
		Truck pointers;
		ST.enqueue(pointers);
		pointers.setN(J);
		pointers.setTYP('S');
		pointers.setV(ss);
		pointers.setTC(STC);
		pointers.setMT(CS);
	}
	for (int k = 1; k <= vt; k++)
	{
		Truck pointerv;
		VT.enqueue(pointerv);
		pointerv.setTYP('V');
		pointerv.setN(J);
		pointerv.setV(vs);
		pointerv.setTC(VTC);
		pointerv.setMT(CV);
	}
}

void Company::openinput()					
{													// the file name should be a user input
	input.open("data.txt", ios::in);

	if (input.is_open() == true)
	{
		readtruckdata();
		readevents();
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
			input >> typ >> et >> id >> dist >> lt >> cost;
		}
		if (ev == 'X')
		{
			input >> et >> id;
		}
		if (ev == 'P')
		{
			input >> et >> id >> cost;
		}
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