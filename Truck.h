#pragma once
#include "LinkedQueue.h"
#include "Cargo.h"


class Truck
{
private:
	LinkedQueue<Cargo*> Q;
	char TYP;
	int TC;
	int MT;
	int DT;
	int V;
	int N;

public:
	Truck();
	Truck(char typ, int tc, int mt, int v);
	void loadCargo(Cargo* C);
	void unloadCargo(Cargo* C);
	void setTYP(char typ);
	void setTC(int tc);
	void setMT(int mt);
	void setDT(int dt);
	void setV(int v);
	void setN(int n);
	char getTYP();
	int getTC();
	int getMT();
	int getDT();
	int getV();
	int getN();
	~Truck();

};

