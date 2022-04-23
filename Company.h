#pragma once
# include <iostream>
using namespace std;
# include <string>
# include <fstream>
# include "UI.h" 
# include "LinkedQueue.h"
# include "Truck.h"
# include "Cargo.h"
class Linkedlist;


class Company
{
private:
	ifstream input;
	UI point;
	string fileinname;
	int nt = 3;
	//LinkedQueue <Truck>* NT = new LinkedQueue <Truck> [nt];
	int st;
	//LinkedQueue <Truck>* ST = new LinkedQueue <Truck>[st];
	int vt;
	//LinkedQueue <Truck>* VT = new LinkedQueue <Truck>[vt];
	//LinkedQueue <Cargo>* VC;
	//LinkedQueue<Cargo>* SC;
	//LinkedList <cargo>* Nc;


public:

	void setnt(int x);

	void setfileinname();

	Company();

	void simulate();

	
	bool openfile();
	
	void writetofile();

	void print();

	void readdata();
};
