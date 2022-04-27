#pragma once
#include "LinkedQueue.h"
#include "Cargo.h"


class Truck
{
private:
	LinkedQueue<Cargo*> Q;   //Loaded Cargos
	char TYP;   // Truck Type
	int TC;   // Truck Capacity
	int MT;   // Truck Maintainance Time
	int DT;   // Truck Delievery Time
	int V;   // Truck Speed
	int N;   // Number Of Delieveries Before Checkup
	int id;		// Truck ID

public:
	Truck();   // No Arguments Constructor
	Truck(char typ, int tc, int mt, int v);   // Arguments Constructor
	void loadCargo(Cargo* C);   // Loads A Cargo
	void unloadCargo(Cargo* C);   // Unloads A Cargo
	void setTYP(char typ);   // Sets Truck Type
	void setTC(int tc);   // Sets Truck Capacity
	void setMT(int mt);   // Sets Truck Maintainance Time
	void setDT(int dt);   // Sets Truck Delievery time
	void setV(int v);   // Sets Truck Speed
	void setN(int n);   // Sets Number Of Delieveries Before Checkup
	char getTYP();   // Returns Truck Type
	int getTC();   // Returns Truck Capacity
	int getMT();   // Returns Truck Maintainance Time
	int getDT();   // Returns Truck Delievery time
	int getV();   // Returns Truck Speed
	int getN();   // Returns Number Of Delieveries Before Checkup
	~Truck();   // Destructor
	friend ostream& operator <<(ostream& print, const Truck& tr);		// operator overloading for the cout << function


};

