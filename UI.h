#pragma once
# include <iostream>
using namespace std;
# include <string>

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

	void print();
};