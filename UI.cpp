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
		cout << "The printing method will be the interactive" << endl;
	}
	else if (printtype == 2)
	{
		cout << "step by step mode" << endl;
	}
	else
	{
		cout << " silent" << endl;
	}

	cout << "Enter file name" << endl;
	//cin >> filename;
	//setfilename(filename);
	//cout << "read from the user, UI " << filename << endl;
	c.print();
	
	
}