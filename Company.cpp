# include <iostream>
using namespace std;
# include <string>
# include "Company.h"

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
		point.print2(nt, st, vt,ns,ss,vs);
		
		hour = hour + 1.00;
		if (hour == 24.00)
		{
			hour = 00.00;
			days = days + 1;
		}
	}
}

void Company::openfile()					// we may change the implementation and remove the input parameter
{														// then we will call the function getfilename from UI class
	input.open("data.txt", ios::in);

	if (input.is_open() == true)
	{
		point.readdata(nt,st,vt,ns,ss,vs,input);
	}
	
}

void Company::setnt(int x)
{
	nt = x;
}



void Company::writetofile()
{
	ofstream output;
	output.open("Output.txt", ios::out);
}

void Company::print()
{

}