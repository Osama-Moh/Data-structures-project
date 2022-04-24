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

	void print2(int n, int s, int v, int sn,int ss,int sv, int ntc, int stc, int vtc,int j, int cn, int cs, int cv, int Auto, int max);

	void readtruckdata(int& nt, int& st, int& vt, int& ns, int& ss, int& vs, int& ntc, int& stc, int& vtc, int &j, int &cn, int &cs,int &cv, int &Auto, int & max, ifstream& input);

	void print3(int e);

	void readevents(int &e, ifstream& in);

	void interactive(int trucksnumbet, int time, int days);

	void stepbystep();

	void silent();

	void detectenter();

};