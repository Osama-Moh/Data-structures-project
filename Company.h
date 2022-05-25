#pragma once
# include <iostream>
using namespace std;
# include <fstream>
# include <string>
# include "UI.h" 
# include "LinkedList.h"
# include "CargoLinkedList.h"
# include "LinkedQueue.h"
# include "PriorityQueue.h"
# include "Cargo.h"
# include "Truck.h"
# include "Event.h"
# include "PreparationEvent.h"
# include "PromotionEvent.h"
# include "CancellationEvent.h"


class Company
{
private:
	int NTS, STS, VTS;   // Speed Of Each Truck Type
	int NTN, STN, VTN;   // Number Of Each Truck Type
	int NTC, STC, VTC;	 // Capacity Of Each Truck Type
	int CN, CS, CV;   // CheckUp Time Of Each Truck Type
	int AutoP, MaxW;   // Automatic Promotion Time And Maximum Wait Time
	int J;   // Number Of Delieveries Before CheckUp
	int E;   // Number Of Events

	char ev, typ, colon;
	int id, dist, lt, cost, day, hour;

	int TNOC, TNOSC, TNOVC, TNONC;
	int averagehours, averagedays;
	int TNOT, TNONT, TNOST, TNOVT;						// total no. of trucks, nomral,special and VIP
	int avgactivetime, avgutilt, avgutilc;				//Avgactive for trucks, Avg utilization for trucks, average utilization for cargos
	int hours = 0;
	int days = 1;
	int totalcargos, totalnormal, totalvip, totalspecial;
	int totalwait = 0;

	string fileinname;   // input File Name
	string fileoutname;	//Output file name

	ifstream input;   // Ifstream Object
	ofstream output;   // Ofstream Object
	
	UI* point = new UI;   // Pointer To UI Class
	
	LinkedQueue <Event*> Events;   // List Of Events
	CargoLinkedList NC;   // List Of Normal Waiting Cargos
	LinkedQueue <Cargo*> SC;   // List Of Special Waiting Cargos
	PriorityQueue <Cargo*> VC;   // List Of VIP Waiting Cargos
	LinkedQueue <Truck*> NT;   // List Of Normal Waiting Trucks
	LinkedQueue <Truck*> ST;   // List Of Special Waiting Trucks
	LinkedQueue <Truck*> VT;   // List Of VIP Waiting VIP Trucks
	LinkedQueue <Cargo*> DeliveredNC;   // List Of Normal Delievered Cargos
	LinkedQueue <Cargo*> DeliveredSC;   // List Of Special Delievered Cargos
	LinkedQueue <Cargo*> DeliveredVC;   // List Of VIP Delievered Cargos
	PriorityQueue <Truck*> Checkspecial;   // List Of CheckUp Trucks
	PriorityQueue <Truck*> Checkvip;   // List Of CheckUp Trucks
	PriorityQueue <Truck*> Checknormal;   // List Of CheckUp Trucks
	//PriorityQueue <Truck*> movingnormal;   // List Of CheckUp Trucks
	//PriorityQueue <Truck*> movingspecial;   // List Of CheckUp Trucks
	//PriorityQueue <Truck*> movingvip;   // List Of CheckUp Trucks
	
	PriorityQueue<Truck*> moving;
	LinkedQueue<Cargo*> Deliveredcargos;

	Truck* pTruckN;
	Truck* pTruckS;
	Truck* pTruckV;


public:
	Company();

	void simulate();   // Simulates The Program
	void setfilename(string name);   // Sets The File Name

	void openinput();   // Opens Input File
	void openoutput();   // Opens Output File
	void writetofile();   // Writes To File
	void print();

	void filltruckdata();   // Fills Trucks Data
	void filleventsdata();   // Fills Events Data
	void readtruckdata();   // Reads Trucks Data From The User
	void readevents();   // Reads Events Data From The User

	void moveTruck(Truck* pTruck);   // Needs Implementation
	void addCargo(Cargo* S);   // Adds A Cargo
	Cargo* removeCargo(int ID);   // Removes A Cargo
	void promoteCargo(int ID, int ExtraCost);   // Promotes A Cargo

	Truck* assignVIPCargos();
	Truck* assignSpecialCargos();
	Truck* assignNormalCargos();
	Truck* assignMaxWNormalCargos();
	Truck* assignMaxWSpecialCargos();
	Truck* assignMaxwCargo(char Type);
	Truck* assignCargos(char Type);

	void autoPromote(Cargo* pCargo);
	bool reachedMaxW(Cargo* pCargo);
	void loadCargo(Truck* pTruck, Cargo* pCargo);
	void getNext(Cargo*& pCargo);
	void manageLoading(Truck*& pTruck, Cargo*& pCargo, int& hour, bool& isMaxW);

	void collect();
	void checkDelievered();
	void checkup();
	void gotowait();
	void finishcheckup();
};
