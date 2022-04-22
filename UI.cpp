# include <iostream>
using namespace std;
# include <string>
# include "UI.h"
# include "Company.h"

UI::UI()
{

}


void UI::setfilename(string name)
{
	filename = name;
}

void UI::setprinttype(int x)
{
	printtype = x;
}

int UI::getprinttype()
{
	return printtype;
}

string UI::getfilename()
{
	return filename;
}

void UI::print()
{
	Company c;
	cout << " Hello" << endl;
	cout << "please choose the printing method you prefer " << endl << "1.interactive" << endl << "2.step by step" << endl << "3.silent " << endl;
	cin >> printtype;
	setprinttype(printtype);
	if (printtype == 1)
	{
		cout << "1.interactive" << endl;
	}
	cout << "Enter file name" << endl;
	cin >> filename;
	setfilename(filename);
	c.print();

	
}