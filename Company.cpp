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
	Cargo* pointerc;
	Cargo* pointercv;
	//Cargo* pointern;
	openinput();
	//int nn = events.getcount();
	point->print1();
	//point->print2(nt, st, vt, ns, ss, vs, NTC, STC, VTC, J, CN, CS, CV, AutoP, MaxW,nn);
	int hours = 0;
	int days = 1;
	int count = 0;
	while (Events.peek(ptr))		
	{
		if (hours >= 5 && hours <= 23)
		{
			count++;
		}
		while (ptr->getDay() == days && ptr->getHour() == hours)
		{
			if (hours < 5)
			{
				ptr->setHour(5);
			}
			else
			{
				Events.dequeue(ptr);
				ptr->Execute(this);
				Events.peek(ptr);
			}
		}

		if (count == 5)
		{
			SC.dequeue(pointerc);
			VC.dequeue(pointercv);
			//NC.DeleteBeg(pointern);
			DeliveredSC.enqueue(pointerc, 1);
			DeliveredVC.enqueue(pointercv, 1);
			//DeliveredNC.enqueue(pointern, 1);
			count = 0;
		}
		int nsn = SC.getcount();					// delete this before submission 
		int vsv = VC.getcount();
		int ncc = NC.getCount();
		int n = NT.getcount() + ST.getcount() + VT.getcount();
		int nc = SC.getcount() + VC.getcount() + NC.getCount();
		int TDC = DeliveredNC.getcount() + DeliveredSC.getcount() + DeliveredVC.getcount();
		point->printmode(n, nc, TDC, ncc, nsn, vsv, hours, days, &NC, &SC, &VC);
		hours++;
		if (hours == 24)
		{
			hours = 0;
			days++;
		}
	}
	openoutput();
}

void Company::filltruckdata()
{
	for (int i = 1; i <= NTN; i++)
	{
		Truck* pointern = new Truck('N',NTC,CN,NTS,J,i);
		NT.enqueue(pointern,1);
	}
	for (int j = 1; j <= STN; j++)
	{
		Truck* pointers = new Truck('S',STC,CS,STS,J,j);
		ST.enqueue(pointers,1);
	}
	for (int k = 1; k <= VTN; k++)
	{
		Truck* pointerv = new Truck('V',VTC,CV,VTS,J,k);
		VT.enqueue(pointerv,1);
	}
}

void Company::readtruckdata()
{
	input >> NTN >> STN >> VTN >> NTS >> STS >> VTS >> NTC >> STC >> VTC >> J >> CN >> CS >> CV >> AutoP >> MaxW;
}

void Company::readevents()
{
	input >> E;
	for (int i = 1; i <= E; i++)
	{
		input >> ev;
		if (ev == 'R')
			input >> typ >> day >> colon >> hour >> id >> dist >> lt >> cost;
		if (ev == 'X')
			input >> day >> colon >> hour >> id;
		if (ev == 'P')
			input >> day >> colon >> hour >> id >> cost;
		filleventsdata();
	}
}

void Company::filleventsdata()
{
	Event* pointer;
	if (ev == 'R')
	{
		pointer = new PreparationEvent(typ, id, day, hour, lt, dist, cost);
		Events.enqueue(pointer,1);
	}
	if (ev == 'X')
	{
		pointer = new CancellationEvent(id, day, hour);
		Events.enqueue(pointer, 1);
	}
	if (ev == 'P')
	{
		pointer = new PromotionEvent(id, day, hour, cost);
		Events.enqueue(pointer, 1);
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
{
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

void Company::print()
{
	SC.print();
}