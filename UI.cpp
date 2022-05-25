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


void UI::setfileinname(string name)
{
	fileinname = name;
}

void UI::setprinttype(int x)
{
	printtype = x;
}

void UI::setfileoutname(string nameout)
{
	fileoutname = nameout;
}

int UI::getprinttype()
{
	return printtype;
}

string UI::getfileinname()
{
	return fileinname;
}

string UI::getfileoutname()
{
	return fileoutname;
}

void UI::detectenter()
{
	cin.get() == '\n';
}

void UI::mainprint()
{
	cout << endl;
	cout << "					Welcom to My Company System " << endl << endl;
	cout << "Please choose the printing mode you prefer by writing its number only: " << endl;
	cout <<"1.Interactive Mode       2.Step By Step Mode               3.Silent Mode" << endl;
	cout << "Number: ";

	cin >> printtype;
	setprinttype(printtype);

	cout << "Data file name is: ";
	cin >> fileinname;
	setfileinname(fileinname);
	cout << "Output file name is: ";
	cin >> fileoutname;

	
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

void UI::printmode(int n, int TNC, int TDC, int t, int d,int tcheck, CargoLinkedList* L, LinkedQueue<Cargo*>* Q, PriorityQueue<Cargo*>* P, LinkedQueue<Truck*>* NT, LinkedQueue<Truck*>* ST, LinkedQueue<Truck*>* VT, PriorityQueue<Truck*>*NCT, PriorityQueue<Truck*>* SCT, PriorityQueue<Truck*>* VCT, PriorityQueue<Truck*>* MT, Truck* pointn, Truck* points, Truck* pointv, LinkedQueue<Cargo*>* DC)
{
	if (printtype == 1)
	{
		interactive(n, TNC, TDC, t, d,tcheck, L, Q, P, NT, ST, VT,NCT,SCT,VCT,MT,pointn,points,pointv,DC);
	}
	else if (printtype == 2)
	{
		stepbystep(n, TNC, TDC, t, d,tcheck, L, Q, P, NT, ST, VT,NCT,SCT,VCT,MT,pointn,points,pointv,DC);
	}

}

void UI::interactive(int n ,int TNC, int TDC, int t, int d,int checkt, CargoLinkedList* L, LinkedQueue<Cargo*>* Q, PriorityQueue<Cargo*>* P, LinkedQueue<Truck*>* NT, LinkedQueue<Truck*>* ST, LinkedQueue<Truck*>* VT,PriorityQueue<Truck*>*NCT, PriorityQueue<Truck*>* SCT, PriorityQueue<Truck*>* VCT, PriorityQueue<Truck*>* MT, Truck* pointn, Truck* points, Truck* pointv, LinkedQueue<Cargo*>* DC)
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
	if (pointn != nullptr)
	{
		cout << pointn->getID() << " ";  cout << "[";  pointn->printloadingcargos(); cout << "]" << " ";
	}
	else
	{
		cout << "[" << "]" << " ";

	}
	if (points != nullptr)
	{
		cout << points->getID() << " ";  cout << "(";  points->printloadingcargos(); cout << ")" << " ";
	}
	else
	{
		cout << "(" << ")" << " ";

	}
	if (pointv != nullptr)
	{
		cout << pointv->getID() << " ";  cout << "{";  pointv->printloadingcargos(); cout << "}" << " ";
	}
	else
	{
		cout << "{" << "}" << endl;

	}
	
	cout << "--------------------------------" << endl << endl;

	cout << n << " " << "Empty Trucks:" << endl;
	cout << "["; NT->print(); cout << "]" << " ";
	cout << "("; ST->print(); cout << ")" << " ";
	cout << "{"; VT->print(); cout << "}" << endl;
	cout << "--------------------------------" << endl << endl;

	cout << 0 << " " << "Moving Cargos: " << endl;
	cout << "["; MT->print(); cout << "]" << " ";
	cout << "(" << ")" << " ";
	cout << "{" << "}" << endl;
	cout << "--------------------------------" << endl << endl;

	cout << checkt << " " << "In-Checkup Trucks: " << endl;
	cout << "["; NCT->print(); cout << "]" << " ";
	cout << "("; SCT->print(); cout << ")" << " ";
	cout << "{"; VCT->print(); cout << "}" << endl;
	cout << "--------------------------------" << endl << endl;

	cout << TDC << " " << "Delivered Cargos: " << endl;
	cout << "["; DC->print(); cout << "]" << " " << endl;
	cout << "--------------------------------" << endl << endl;

}

void UI::stepbystep(int n, int TNC, int TDC, int t, int d,int tcheck, CargoLinkedList* L, LinkedQueue<Cargo*>* Q, PriorityQueue<Cargo*>* P, LinkedQueue<Truck*>* NT, LinkedQueue<Truck*>* ST, LinkedQueue<Truck*>* VT, PriorityQueue<Truck*>*NCT, PriorityQueue<Truck*>* SCT, PriorityQueue<Truck*>* VCT, PriorityQueue<Truck*>* MT, Truck* pointn, Truck* points, Truck* pointv, LinkedQueue<Cargo*>* DC)
{
	cout << "Current Time (Day:Hour):" << d << ":" << t << endl << endl;
	cout << "--------------------------------" << endl << endl;

	cout << TNC << " " << "Waiting Cargos: " << endl;
	cout << "["; L->print(); cout << "]" << " ";
	cout << "("; Q->print(); cout << ")" << " ";
	cout << "{"; P->print(); cout << "}" << endl;
	cout << "--------------------------------" << endl << endl;

	cout << 0 << " " << "Loading Trucks:" << endl;
	if (pointn != nullptr)
	{
		cout << pointn->getID() << " ";  cout << "[";  pointn->printloadingcargos(); cout << "]" << " ";
	}
	else
	{
		cout << "[" << "]" << " ";

	}
	if (points != nullptr)
	{
		cout << points->getID() << " ";  cout << "(";  points->printloadingcargos(); cout << ")" << " ";
	}
	else
	{
		cout << "(" << ")" << " ";

	}
	if (pointv != nullptr)
	{
		cout << pointv->getID() << " ";  cout << "{";  pointv->printloadingcargos(); cout << "}" << " ";
	}
	else
	{
		cout << "{" << "}" << endl;

	}
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

	cout << tcheck << " " << "In-Checkup Trucks: " << endl;
	cout << "["; NCT->print(); cout << "]" << " ";
	cout << "("; SCT->print(); cout << ")" << " ";
	cout << "{"; VCT->print(); cout << "}" << endl;
	cout << "--------------------------------" << endl << endl;

	cout << TDC << " " << "Delivered Cargos: " << endl;
	cout << "["; DC->print(); cout << "]" << " " << endl;
	cout << "--------------------------------" << endl << endl;
	Sleep(1000);
}

void UI::silent()
{
	cout << " Silent Mode" << endl << " Simulation Starts..." << endl << endl;
}

void UI::printend()
{

	cout << "Simulation Ends, Output file created" << endl;
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

