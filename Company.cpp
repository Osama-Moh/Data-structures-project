# include <iostream>
using namespace std;
# include <string>
# include "Company.h"


Company::Company()
{

}

void Company::simulate()
{
	UI ui;
	float hour = 00.00;
	int days = 0;
	//	while (days<1)					// while true
	//	{
	ui.print();

	//point->print();

	hour = hour + 1.0;
	if (hour == 24.00)
	{
		hour = 00.00;
		days = days + 1;
	}
		//	}
}

bool Company::openfile(string filein)
{
	ofstream output;
	ifstream input;

	output.open(fileinname, ios::out);
	input.open(fileinname, ios::in);

	if (input.is_open() == true)
	{
		return true;
	}

}

void Company::print()
{


	
}