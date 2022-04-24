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

void UI::detectenter()
{
	cin.get() == '\n';
}

void UI::print1()
{
	cout << endl;
	cout << "					Welcom to My company system " << endl << endl;
	cout << "Please choose the printing mode you prefer by writing its number only: " << endl;
	cout <<"1.interactive Mode" << endl << "2.Step by step Mode" << endl << "3.Silent Mode" << endl;
	cout << "Number : ";
	cin >> printtype;
	setprinttype(printtype);
	cout << "The printing mode will be the : ";
	if (printtype == 1)
	{
		cout << "Interactive Mode" << endl;
	//	interactive();
	}
	else if (printtype == 2)
	{
		cout << "Step by step Mode" << endl;
		//stepbystep();
	}
	else
	{
		cout << "Silent" << endl;
		//silent();
	}
}

void UI::interactive(int n, int t, int d)
{
	int hours = 00;
	int days = 1;
	//while (days < 2)
	//{
		cout << "Current Time (Day:Hour):" << d << ":" << t << endl << endl;
		cout << "--------------------------------" << endl << endl;
		cout << n << " " << "Empty Trucks:" << endl << endl;
		cout << "--------------------------------" << endl << endl;

		detectenter();


	//	hours++;
	//	if (hours == 24)
	//	{
	//		hours = 00;
	//		days++;
		//}
//	}
}

void UI::stepbystep()
{
	int hours = 00;
	int days = 1;
	while (days < 2)
	{
		cout << "Current Time (Day:Hour):" << days << ":" << hours << endl;


		hours++;
		if (hours == 24)
		{
			hours = 00;
			days++;
		}
	}
}

void UI::silent()
{
	cout << " Silent Mode" << endl << " Simulation Starts..." << endl << " Simulation ends, Output file created" << endl;
}

void UI::print2(int n, int s, int v, int sn, int ss, int sv, int ntc, int stc, int vtc, int j, int cn, int cs, int cv, int Auto, int max)
{		
	// this function is used to test that the data from the file is loaded (should be deleted or not to be submited)
	cout << "well done" << endl;
	cout << n << "  " << s << "  " << v << endl;
	cout << sn << "  " << ss << "  " << sv << endl;
	cout << ntc << "  " << stc << "  " << vtc << endl;
	cout << j << "  " << cn << "  " << cs << "  " << cv << endl;
	cout << Auto << "  " << max << endl;
}

void UI::print3(int e)
{
	// this function is used to test that the data from the file is loaded (should be deleted or not to be submited)
	cout << e << endl;
}

void UI::readtruckdata(int& nt, int& st, int& vt, int& ns, int& ss, int& vs, int &ntc, int &stc,int &vtc, int& j, int& cn, int& cs, int& cv, int &Auto, int &max, ifstream& input)
{
	//Company c;
	//c.openfile();
	input >> nt >> st >> vt >> ns >> ss >> vs >> ntc >> stc >> vtc >> j >> cn >> cs >> cv >> Auto >> max;

}

void UI::readevents(int& e, ifstream& in)
{
	in >> e;

}