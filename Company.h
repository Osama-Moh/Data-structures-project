#pragma once
# include <iostream>
using namespace std;
# include <string>
# include <fstream>
# include "UI.h" 
# include "LinkedQueue.h"


class Company
{
private:
	UI* point;
	string fileinname;
	int nt;
	LinkedQueue <int>* NT = new LinkedQueue <int> [nt];
	int st;
	LinkedQueue <int>* ST = new LinkedQueue <int>[st];
	int vt;
	LinkedQueue <int>* VT = new LinkedQueue <int>[vt];


public:
	Company();

	void simulate();

	
	bool openfile(string fileinname);
	
	void print();

};
