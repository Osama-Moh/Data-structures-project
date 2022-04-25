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
	int  ns, ss, vs;											// speed of each truck type
	int nt, st, vt;												// number of each truck type
	int NTC, STC, VTC;											// capacity of each truck
	int J;
	int CN, CS, CV;												// time of checkup for normal,special,vip
	int AutoP, MaxW;											
	int E;														// number of events
	char ev, typ;
	string et;
	int id, dist, lt, cost;
	ifstream input;
	ofstream output;
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

	void openinput();

	void openoutput();

	void writetofile();

	void print();

	void filltruckdata();

	void filleventsdata();

	void fillcargodata();

	void readtruckdata();

	void readevents();
};
