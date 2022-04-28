#pragma once
# include <iostream>
using namespace std;
# include <string>
# include <fstream>
# include "UI.h" 
# include "LinkedQueue.h"
# include "PriorityQueue.h"
# include "Truck.h"
# include "Cargo.h"
# include "LinkedList.h"
# include "PreparationEvent.h"
# include "PromotionEvent.h"
# include "CancellationEvent.h"
# include "Event.h"

class Company
{
private:
	int NTS, STS, VTS;											// speed of each truck type (Normal,Special,VIP)
	int NTN, STN, VTN;										    // number of each truck type
	int NTC, STC, VTC;											// capacity of each truck
	int CN, CS, CV;												// time of checkup for normal,special,vip
	int AutoP, MaxW;
	int J;
	int E;														// number of events
	char ev, typ, colon;
	int id, dist, lt, cost, day, hour;
	string fileinname;

	ifstream input;
	ofstream output;
	UI* point = new UI;					// is this a correct way to 

	LinkedQueue <Truck*> NT;
	
	LinkedQueue <Truck*> ST;
	
	LinkedQueue <Truck*> VT;
	
	LinkedQueue <Cargo*> SC;
	
	LinkedList <Cargo*> NC;

	PriorityQueue <Cargo*> VC;

	PriorityQueue <Truck*> Check;

	LinkedQueue<Event*>events;

	LinkedQueue<Cargo*> DeliveredSC;

	LinkedQueue<Cargo*> DeliveredNC;

	LinkedQueue<Cargo*> DeliveredVC;

public:
	Company();

	void simulate();

	void setfilename(string name);

	void openinput();

	void openoutput();

	void writetofile();

	void print();			

	void filltruckdata();

	void filleventsdata();

	void readtruckdata();

	void readevents();

	void addCargo(Cargo* S);

	Cargo* removeCargo(int ID);

	void promoteCargo(int ID, int ExtraCost);
};
