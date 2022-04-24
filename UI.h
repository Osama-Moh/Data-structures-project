#pragma once
# include <iostream>
using namespace std;
# include <string>
# include <fstream>;
class UI
{
private:
	//ifstream input;
	string filename;
	int printtype;


public:
	UI();

	void setfilename(string filename);

	void setprinttype(int value);

	int getprinttype();
	
	string getfilename();

	void print1();

	void print2(int n, int s, int v, int sn,int ss,int sv);

	void readdata(int& nt, int& st, int& vt, int& ns, int& ss, int& vs, ifstream& input);


};