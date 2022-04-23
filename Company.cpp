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
	openfile(fileinname);
	
	
	
	float hour = 00.00;
	int days = 1;
	while (days<2)					// while true (this condition will be changed but i make it this way in order to make basic tests
	{
		point.print();

//		point->print();

		hour = hour + 1.00;
		if (hour == 24.00)
		{
			hour = 00.00;
			days = days + 1;
		}
	}
}

bool Company::openfile(string filein)					// we may change the implementation and remove the input parameter
{														// then we will call the function getfilename from UI class
	ifstream input;

	input.open("data.txt", ios::in);

	if (input.is_open() == true)
	{
		return true;
	}
	input >> nt;
}

void Company::writetofile()
{
	ofstream output;
	output.open("Output.txt", ios::out);
}

void Company::print()
{

	cout << "hey" << endl;
	cout << fileinname << endl;
	cout << nt;
}