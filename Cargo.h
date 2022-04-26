#pragma once


class Cargo
{
private:
	char TYP;
	int ID;
	int PTD;
	int PTH;
	int LT;
	int DIST;
	int COST;

public:
	Cargo();
	Cargo(char typ, int id, int ptd, int pth, int lt, int dist, int cost);
	void setTYP(char typ);
	void setID(int id);
	void setPTD(int ptd);
	void setPTH(int pth);
	void setLT(int lt);
	void setDIST(int dist);
	void setCOST(int cost);
	char getTYP();
	int getID();
	int getPTD();
	int getPTH();
	int getLT();
	int getDIST();
	int getCOST();
	int getPRIORITY();
	~Cargo();

};
