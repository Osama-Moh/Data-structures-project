#pragma once
# include <iostream>
using namespace std;
# include <string>
# include <fstream>
# include "UI.h" 
# include "LinkedQueue.h"
# include "Truck.h"
# include "Cargo.h"
# include "LinkedList.h"



class Company
{
private:
	UI* point;
	string fileinname;
	int nt;
	LinkedQueue <truck>* NT = new LinkedQueue <truck> [nt];
	int st;
	LinkedQueue <truck>* ST = new LinkedQueue <truck>[st];
	int vt;
	LinkedQueue <truck>* VT = new LinkedQueue <truck>[vt];
	LinkedQueue <cargo>* VC;
	LinkedQueue<cargo>* SC;
	LinkedList<cargo>* Nc;
	

public:
	Company();

	void simulate();

	
	bool openfile(string fileinname);
	
	void print();

};
