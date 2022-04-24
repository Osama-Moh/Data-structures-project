# include <iostream>
using namespace std;
# include <string>
# include "Company.h"
# include "Truck.h"

void Company::setfileinname()
{
	fileinname = point.getfilename();
}


Company::Company()
{

}

void Company::simulate()
{	
	openfile();
	
	float hour = 00.00;
	int days = 1;
	while (days<2)					// while true (this condition will be changed but i make it this way in order to make basic tests
	{
		point.print1();
		point.print2(nt, st, vt,ns,ss,vs,NTC,STC,VTC,J,CN,CS,CV,AutoP,MaxW);
		
		hour = hour + 1.00;
		if (hour == 24.00)
		{
			hour = 00.00;
			days = days + 1;
		}
	}
}

void Company::filltruckdata()
{
	for (int i = 1; i <= nt; i++)
	{
		//char N = N;
		Truck* pointern;
		NT.enqueue(pointern);
		//pointern->setTYP(N);
		pointern->setN(i);
		pointern->setV(ns);
		pointern->setTC(NTC);
	}
	for (int j = 1; j <= st; j++)
	{
		//char S = S;
		Truck* pointers;
		ST.enqueue(pointers);
		pointers->setN(j);
		//pointers->setTYP(S);
		pointers->setV(ss);
		pointers->setTC(STC);
	}
	for (int k = 1; k <= vt; k++)
	{
	//	char V = V;
		Truck* pointerv;
		VT.enqueue(pointerv);
		//pointerv->setTYP(V);
		pointerv->setN(k);
		pointerv->setV(vs);
		pointerv->setTC(VTC);
	}
}


void Company::openfile()					
{													// the file name should be a user input
	input.open("data.txt", ios::in);

	if (input.is_open() == true)
	{
		point.readtruckdata(nt,st,vt,ns,ss,vs,NTC,STC,VTC,J,CN,CS,CV,AutoP,MaxW,input);
	}
	
}


void Company::writetofile()
{
	ofstream output;
	output.open("Output.txt", ios::out);
}

void Company::print()
{

}