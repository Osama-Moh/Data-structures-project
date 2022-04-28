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

	string fileinname;   // File Name
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
	PriorityQueue <Truck*> Check;   // List Of CheckUp Trucks
	LinkedQueue <Cargo*> DeliveredNC;   // List Of Normal Delievered Cargos
	LinkedQueue <Cargo*> DeliveredSC;   // List Of Special Delievered Cargos
	LinkedQueue <Cargo*> DeliveredVC;   // List Of VIP Delievered Cargos

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

	void addCargo(Cargo* S);   // Adds A Cargo
	Cargo* removeCargo(int ID);   // Removes A Cargo
	void promoteCargo(int ID, int ExtraCost);   // Promotes A Cargo

};
