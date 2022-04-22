#pragma once
# include <iostream>
using namespace std;
# include <string>
# include <fstream>
# include "UI.h" 



class Company
{
private:
	UI* point;
	int x;

public:
	UI ui;
	Company ()
	{

	}

	void simulate()
	{
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
	string filename = ui.getfilename();
	bool openfile(string filename)
	{
		ofstream output;
		ifstream input;

		output.open(filename, ios::out);
		input.open(filename, ios::in);

		if (input.is_open() == true)
		{
			return true;
		}
	}
	
	void print()
	{
		
		
			cout << "The file has been opened successfully";
		
	}

};
