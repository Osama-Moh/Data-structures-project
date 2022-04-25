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
	}
	else if (printtype == 2)
	{
		cout << "Step by step Mode" << endl;
	}
	else
	{
		cout << "Silent" << endl;
		silent();
	}
}

void UI::printmode(int n, int t, int d)
{
	if (printtype == 1)
	{
		interactive(n,t,d);
	}
	else if (printtype == 2)
	{
		stepbystep(n,t,d);
	}

}

void UI::interactive(int n, int t, int d)
{		
		cout << "Current Time (Day:Hour):" << d << ":" << t << endl << endl;
		cout << "--------------------------------" << endl << endl;
		
		cout << " " << "Waiting Cargos: " << endl << endl;
		cout << "--------------------------------" << endl << endl;
		
		cout << " " << "Loading Trucks: " << endl << endl;
		cout << "--------------------------------" << endl << endl;
		
		cout << n << " " << "Empty Trucks:" << endl << endl;
		cout << "--------------------------------" << endl << endl;

		cout << " " << "Moving Cargos: " << endl << endl;
		cout << "--------------------------------" << endl << endl;

		cout << " " << "In-Checkup Trucks: " << endl << endl;
		cout << "--------------------------------" << endl << endl;
		
		cout << " " << "Delivered Cargos: " << endl << endl;
		cout << "--------------------------------" << endl << endl;

		detectenter();
}

void UI::stepbystep(int n, int t, int d)
{
	cout << "Current Time (Day:Hour):" << d << ":" << t << endl << endl;
	cout << "--------------------------------" << endl << endl;

	cout << " " << "Waiting Cargos: " << endl << endl;
	cout << "--------------------------------" << endl << endl;

	cout << " " << "Loading Trucks: " << endl << endl;
	cout << "--------------------------------" << endl << endl;

	cout << n << " " << "Empty Trucks:" << endl << endl;
	cout << "--------------------------------" << endl << endl;

	cout << " " << "Moving Cargos: " << endl << endl;
	cout << "--------------------------------" << endl << endl;

	cout << " " << "In-Checkup Trucks: " << endl << endl;
	cout << "--------------------------------" << endl << endl;

	cout << " " << "Delivered Cargos: " << endl << endl;
	cout << "--------------------------------" << endl << endl;

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

void UI::print3(int e, char ev,char ty, string et,int id,int dist,int ly,int cost)
{
	// this function is used to test that the data from the file is loaded (should be deleted or not to be submited)
	cout << e << endl << ev << "  " << ty << "  " << et << "  " << id << "  " << dist << "  " << ly << "  " << cost << endl;
}



void UI::readeventsnumber(int& e, char& ev, char& ty, int& et, int& id, int& dist, int& lt, int& cost, ifstream& in)
{
	in >> e;
	for (int i = 1; i <= e; i++)
	{
		in >> ev;
		if (ev == 'R')
		{
			in >> ty >> et >> id >> dist >> lt >> cost;
		}
		if (ev == 'X')
		{
			in >> et >> id;
		}
		if (ev == 'P')
		{
			in >> et >> id >> cost;
		}
	}
}

void UI::readevents(char &ev, char &ty, int &et, int &id, int &dist, int &lt, int &cost, ifstream& in)
{
	in >> ev;
	if (ev == 'R')
	{
		in >> ty >> et >> id >> dist >> lt >> cost;
	}
	if (ev == 'X')
	{
		in >> et >> id;
	}
	if (ev == 'P')
	{
		in >> et >> id >> cost;
	}
}

