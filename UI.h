#pragma once
# include <iostream>
# include <fstream>
# include <string>
# include "Truck.h"
# include "CargoLinkedList.h"
# include "LinkedQueue.h"
# include "PriorityQueue.h"
using namespace std;
class Company;

class UI
{
private:
	string fileinname;
	string fileoutname;
	Company* pointc;
	int printtype;

public:
	UI();

	void setfileoutname(string fileoutname);

	void setfileinname(string fileinname);

	void setprinttype(int value);

	int getprinttype();
	
	string getfileinname();

	string getfileoutname();

	void print1();

	void printmode(int n,int TWC,int TDC, int t, int d, CargoLinkedList* NC, LinkedQueue<Cargo*>* SC, PriorityQueue<Cargo*>* VC, LinkedQueue<Truck*>* NT, LinkedQueue<Truck*>* ST, LinkedQueue<Truck*>* VT, LinkedQueue<Cargo*>* DNC, LinkedQueue<Cargo*>* DSC, LinkedQueue<Cargo*>* DVC, PriorityQueue<Truck*>*NCT);

	void print2(int n, int s, int v, int sn,int ss,int sv, int ntc, int stc, int vtc,int j, int cn, int cs, int cv, int Auto, int max, int rv);//delete
	
	void print3(int e, char evt, char truckt, int day , int H, int id, int dist,int lt,int cost);//delete

	void readeventsnumber(int& e, char& ev, char& ty, int& et, int& id, int& dist, int& lt, int& cost, ifstream& in);

	void interactive(int trucksnumbet, int cargosnumber, int deliverc, int time, int days, CargoLinkedList* NC, LinkedQueue<Cargo*>* SC, PriorityQueue<Cargo*>* VC, LinkedQueue<Truck*>* NT, LinkedQueue<Truck*>* ST, LinkedQueue<Truck*>* VT, LinkedQueue<Cargo*>* DNC, LinkedQueue<Cargo*>* DSC, LinkedQueue<Cargo*>* DVC, PriorityQueue<Truck*>*NCT);

	void stepbystep(int trucksnumbet, int cargosnumber, int deliverc, int time, int days, CargoLinkedList* NC, LinkedQueue<Cargo*>* SC, PriorityQueue<Cargo*>* VC, LinkedQueue<Truck*>* NT, LinkedQueue<Truck*>* ST, LinkedQueue<Truck*>* VT, LinkedQueue<Cargo*>* DNC, LinkedQueue<Cargo*>* DSC, LinkedQueue<Cargo*>* DVC);

	void silent();

	void detectenter();

	void readevents(char& e, char& ty, int& et, int& id, int& dist, int& lt, int& cost, ifstream& in);

};