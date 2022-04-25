#pragma once
#include "Event.h"


class PreparationEvent: public Event
{
private:
	char Type;
	int Dist;
	int Load;
	int Cost;
public:
	PreparationEvent();
	PreparationEvent(int id, int day, int hour, char type, int load, int dist, int cost);
	void Execute(Company* C);
	void setType(char type);
	void setLoad(int load);
	void setDist(int dist);
	void setCost(int cost);
	char getType();
	int getLoad();
	int getDist();
	int getCost();
	~PreparationEvent();
};

