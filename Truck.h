#pragma once
#include "LinkedQueue.h"
#include "PriorityQueue.h"
#include "Cargo.h"
# include <iostream>

class Truck
{
private:
	LinkedQueue<Cargo*> QL;   // Loaded Cargos
	PriorityQueue<Cargo*> QM;   // Moving Cargos
	char TYP;   // Truck Type
	int TC;   // Truck Capacity
	int MT;   // Truck Maintainance Time
	int DT;   // Truck Delievery Time
	int V;   // Truck Speed
	int N;   // Number Of Delieveries Before Checkup
	int ID;		// Truck ID
	int COUNT;   // Truck Delivery Count

	int SDAY, SHOUR;			// start moving time 
	int RDAY, RHOUR;			// return from moving time
	int FDAY, FHOUR;			// finish checkup time
	int totalunloading;			
	int furthercargo;

public:
	Truck();   // No Arguments Constructor
	Truck(char typ, int tc, int mt, int v, int n, int id);   // Arguments Constructor
	void loadCargo(Cargo* C);   // Loads A Cargo
	void unloadCargo(Cargo* C);   // Unloads A Cargo
	bool hasCargo(Cargo* C);   // Searches If A Cargo Is In The Truck Or Not
	void setTYP(char typ);   // Sets Truck Type
	void setTC(int tc);   // Sets Truck Capacity
	void setMT(int mt);   // Sets Truck Maintainance Time
	void setDT();   // Sets Truck Delievery time
	void setV(int v);   // Sets Truck Speed
	void setN(int n);   // Sets Number Of Delieveries Before Checkup
	void setID(int id);	  // Sets Truck ID
	void setCOUNT(int count);   // Sets Truck Delievery Count
	void settotalunloading(int l);
	void setfurthercargo(int fc);
	void setRTIME(int sday, int shour);
	void setFTIME(int duration, int day, int hour);
	
	int getRDAY();
	int getRHOUR();
	int getFHOUR();
	int getFDAY();
	char getTYP();   // Returns Truck Type
	int getTC();   // Returns Truck Capacity
	int getMT();   // Returns Truck Maintainance Time
	int getDT();   // Returns Truck Delievery time
	int getV();   // Returns Truck Speed
	int getN();   // Returns Number Of Delieveries Before Checkup
	int getID() const;  // Return Truck ID
	int getCOUNT();   // Returns Truck Delievery Count
	int gettotalunloading();
	int getfurthercargo();
	int getLoadedCount();
	void Move();
	bool isFull();
	bool getpeek(Cargo* & C);
	void printloadingcargos();
	void printmovingcargos();
	friend ostream& operator << (ostream& out, const Truck& T);
	~Truck();   // Destructor
};

