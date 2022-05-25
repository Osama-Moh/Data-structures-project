#pragma once
# include <iostream>
using namespace std;

class Cargo
{
private:
	char TYP;   // Cargo Type
	int ID;   // Cargo ID
	int PTD;   // Cargo Preparation Time in Days
	int PTH;   // Cargo Preparation Time in Hours
	int LT;   // Cargo Loading and Unloading Time
	int DIST;   // Cargo Shipping Distance
	int COST;   // Cargo Shipping Cost
	int CDT, CDTH, CDTD;
	int Dd, Dh;
	int WT;					// cargo waiting time
	int TID;				// truck id
	int WTD, WTH;

public:
	Cargo();   // No Arguments Constructor
	Cargo(char typ, int id, int ptd, int pth, int lt, int dist, int cost);   // Arguments Constructor
	void setTYP(char typ);   // Sets Cargo Type 
	void setID(int id);   // Sets Cargo ID
	void setPTD(int ptd);   // Sets Cargo Preparation Time in Days
	void setPTH(int pth);   // Sets Cargo Preparation Time in Hours
	void setLT(int lt);   // Sets Cargo Loading and Unloading Time
	void setDIST(int dist);   // Sets Cargo Shipping Distance
	void setCOST(int cost);   // Sets Cargo Shipping Cost
	void setCDT(int days, int hours, int speed, int distance);

	char getTYP();   // Returns Cargo Type
	int getID() const;   // Returns Cargo ID
	int getPTD();   // Returns Cargo Preparation Time in Days
	int getPTH();   // Returns Cargo Preparation Time in Hours
	int getLT();   // Returns Cargo Loading and Unloading Time
	int getDIST();   // Returns Cargo Shipping Distance
	int getCOST();   // Returns Cargo Shipping Cost
	float getPRIORITY();   // Returns Cargo Priority
	int getCDT();

	void setWT(int SD, int SH);
	int getWT();

	void setTID(int id);
	int getTID();

	int getWTH();
	int getWTD();
	int getCDTH();
	int getCDTD();
	friend ostream& operator << (ostream& out,const Cargo& C);
	~Cargo();  // Destructor
	
};
