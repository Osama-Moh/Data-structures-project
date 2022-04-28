#pragma once
#include "LinkedQueue.h"
#include "Cargo.h"


class Truck
{
private:
	LinkedQueue<Cargo*> QL;   // Loaded Cargos
	LinkedQueue<Cargo*> QM;   // Moving Cargos
	char TYP;   // Truck Type
	int TC;   // Truck Capacity
	int MT;   // Truck Maintainance Time
	int DT;   // Truck Delievery Time
	int V;   // Truck Speed
	int N;   // Number Of Delieveries Before Checkup
	int ID;		// Truck ID

public:
	Truck();   // No Arguments Constructor
	Truck(char typ, int tc, int mt, int v, int n, int id);   // Arguments Constructor
	void loadCargo(Cargo* C);   // Loads A Cargo
	void unloadCargo(Cargo* C);   // Unloads A Cargo
	bool hasCargo(Cargo* C);   // Searches If A Cargo Is In The Truck Or Not
	void setTYP(char typ);   // Sets Truck Type
	void setTC(int tc);   // Sets Truck Capacity
	void setMT(int mt);   // Sets Truck Maintainance Time
	void setDT(int dt);   // Sets Truck Delievery time
	void setV(int v);   // Sets Truck Speed
	void setN(int n);   // Sets Number Of Delieveries Before Checkup
	void setID(int id);	// Sets Truck ID
	char getTYP();   // Returns Truck Type
	int getTC();   // Returns Truck Capacity
	int getMT();   // Returns Truck Maintainance Time
	int getDT();   // Returns Truck Delievery time
	int getV();   // Returns Truck Speed
	int getN();   // Returns Number Of Delieveries Before Checkup
	int getID();   // Returns Truck ID
	~Truck();   // Destructor
	friend ostream& operator <<(ostream& print, const Truck& tr);		// operator overloading for the cout << function


};

