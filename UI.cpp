# include <iostream>
using namespace std;
# include <string>
# include "UI.h"
# include "Company.h"
# include <fstream>

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

void UI::print1()
{
	

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
	
	
	//print2();

	
	
}

void UI::print2(int n,int s,int v,int sn,int ss,int sv)
{
	cout << "well done" << endl;
	cout << n << "  " << s << "  " << v << endl;
	cout << sn << "  " << ss << "  " << sv << endl;
}

void UI::readdata(int& nt, int& st, int& vt, int& ns, int& ss, int& vs, ifstream& input)
{
	Company c;
	c.openfile();
	input >> nt >> st >> vt >> ns >> ss >> vs;

}