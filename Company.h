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
	int  ns, ss, vs;
	int nt, st, vt;
	ifstream input;
	UI point;
	string fileinname;

	LinkedQueue <Truck*> NT;
	
	LinkedQueue <Truck*> ST;
	
	LinkedQueue <Truck*> VT;
	LinkedQueue <Cargo*> VC;
	//LinkedQueue<Cargo>* SC;
	//LinkedList <Cargo>* Nc;


public:

	void setnt(int x);

	void setfileinname();

	Company();

	void simulate();

	
	void openfile();
	
	void writetofile();

	void print();

};
