# include <iostream>
using namespace std;
# include <string>
# include "UI.h"
# include "Company.h"
# include <fstream>
# include <Windows.h>

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
	cout << "					Welcom to My Company System " << endl << endl;
	cout << "Please choose the printing mode you prefer by writing its number only: " << endl;
	cout <<"1.Interactive Mode       2.Step By Step Mode               3.Silent Mode" << endl;
	cout << "Number: ";

	cin >> printtype;
	setprinttype(printtype);

	cout << "file name is: ";
	cin >> filename;
	
	
	cout << endl << "The printing mode will be the : ";
	
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

void UI::printmode(int n, int TNC, int TDC, int t, int d, CargoLinkedList* L, LinkedQueue<Cargo*>* Q, PriorityQueue<Cargo*>* P, LinkedQueue<Truck*>* NT, LinkedQueue<Truck*>* ST, LinkedQueue<Truck*>* VT, LinkedQueue<Cargo*>* DNC, LinkedQueue<Cargo*>* DSC, LinkedQueue<Cargo*>* DVC)
{
	if (printtype == 1)
	{
		interactive(n, TNC, TDC, t, d, L, Q, P, NT, ST, VT, DNC, DSC, DVC);
	}
	else if (printtype == 2)
	{
		stepbystep(n, t, d);
	}

}

void UI::interactive(int n ,int TNC, int TDC, int t, int d, CargoLinkedList* L, LinkedQueue<Cargo*>* Q, PriorityQueue<Cargo*>* P, LinkedQueue<Truck*>* NT, LinkedQueue<Truck*>* ST, LinkedQueue<Truck*>* VT, LinkedQueue<Cargo*>* DNC, LinkedQueue<Cargo*>* DSC, LinkedQueue<Cargo*>* DVC)
{		
	detectenter();

	cout << "Current Time (Day:Hour):" << d << ":" << t << endl << endl;
	cout << "--------------------------------" << endl << endl;
			
	cout << TNC << " " << "Waiting Cargos: " << endl;
	cout << "["; L->print(); cout << "]"<<" ";
	cout << "("; Q->print(); cout << ")" << " ";
	cout << "{"; P->print(); cout << "}" << endl;
	cout << "--------------------------------" << endl << endl;

	cout << 0 << " " << "Loading Trucks:" << endl;
	cout << "[" << "]" << " ";
	cout << "(" << ")" << " ";
	cout << "{" << "}" << endl;
	cout << "--------------------------------" << endl << endl;

	cout << n << " " << "Empty Trucks:" << endl;
	cout << "["; NT->print(); cout << "]" << " ";
	cout << "("; ST->print(); cout << ")" << " ";
	cout << "{"; VT->print(); cout << "}" << endl;
	cout << "--------------------------------" << endl << endl;

	cout << 0 << " " << "Moving Cargos: " << endl;
	cout << "[" << "]" << " ";
	cout << "(" << ")" << " ";
	cout << "{" << "}" << endl;
	cout << "--------------------------------" << endl << endl;

	cout << 0 << " " << "In-Checkup Trucks: " << endl;
	cout << "[" << "]" << " ";
	cout << "(" << ")" << " ";
	cout << "{" << "}" << endl;
	cout << "--------------------------------" << endl << endl;

	cout << TDC << " " << "Delivered Cargos: " << endl;
	cout << "["; DNC->print(); cout << "]" << " ";
	cout << "("; DSC->print(); cout << ")" << " ";
	cout << "{"; DVC->print(); cout << "}" << endl;
	cout << "--------------------------------" << endl << endl;

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
	Sleep(1000);
}

void UI::silent()
{
	cout << " Silent Mode" << endl << " Simulation Starts..." << endl << " Simulation ends, Output file created" << endl;
}

void UI::print2(int n, int s, int v, int sn, int ss, int sv, int ntc, int stc, int vtc, int j, int cn, int cs, int cv, int Auto, int max,int nrv)
{		
	// this function is used to test that the data from the file is loaded (should be deleted or not to be submited)
	cout << n << "  " << s << "  " << v << endl;
	cout << sn << "  " << ss << "  " << sv << endl;
	cout << ntc << "  " << stc << "  " << vtc << endl;
	cout << j << "  " << cn << "  " << cs << "  " << cv << endl;
	cout << Auto << "  " << max << endl;
	cout << nrv << endl;
}

void UI::print3(int e, char ev,char ty, int d, int h,int id,int dist,int lt,int cost)
{
	// this function is used to test that the data from the file is loaded (should be deleted or not to be submited)
	if (ev == 'R')
	{
		cout << ev << "  " << ty << "  " << d << " "<< h << "  " << id << "  " << dist << "  " << lt << "  " << cost << endl;
	}
	else if (ev == 'P')
	{
		//cout << ev << "  " << et << "  " << id << "  " << cost << endl;
	}
	else if (ev == 'X')
	{
	//	cout << ev << "  " << et << "  " << id << endl;
	}
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

