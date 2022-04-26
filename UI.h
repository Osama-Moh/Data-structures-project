#pragma once
# include <iostream>
using namespace std;
# include <string>
# include <fstream>;
class UI
{
private:
	string filename;
	int printtype;


public:
	UI();

	void setfilename(string filename);

	void setprinttype(int value);

	int getprinttype();
	
	string getfilename();

	void print1();

	void printmode(int n, int t, int d);

	void print2(int n, int s, int v, int sn,int ss,int sv, int ntc, int stc, int vtc,int j, int cn, int cs, int cv, int Auto, int max, int rv);
	
	void print3(int e, char evt, char truckt, int day , int H, int id, int dist,int lt,int cost);

	void readeventsnumber(int& e, char& ev, char& ty, int& et, int& id, int& dist, int& lt, int& cost, ifstream& in);

	void interactive(int trucksnumbet, int time, int days);

	void stepbystep(int n, int t, int d);

	void silent();

	void detectenter();

	void readevents(char& e, char& ty, int& et, int& id, int& dist, int& lt, int& cost, ifstream& in);

};