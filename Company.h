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
	int NTC, STC, VTC;
	int J;
	int CN, CS, CV;
	int AutoP, MaxW;
	int E;

	ifstream input;
	UI point;
	string fileinname;

	LinkedQueue <Truck> NT;
	
	LinkedQueue <Truck> ST;
	
	LinkedQueue <Truck> VT;
	
	LinkedQueue <Cargo> SC;
	
	//LinkedList <Cargo*> Nc;


public:


	Company();

	void simulate();

	
	void openfile();
	
	void writetofile();

	void print();

	void filltruckdata();

	void filleventsdata();

	void fillcargodata();
};
