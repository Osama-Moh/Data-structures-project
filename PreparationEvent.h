#pragma once
#include "Event.h"


class PreparationEvent: public Event
{
private:
	char Type;   // Prepared Cargo Type
	int Dist;   // Prepared Cargo Delievery Distance
	int Load;   // Prepared Cargo Loading and Unloading Time
	int Cost;   // Prepared Cargo Shipping Cost
public:
	PreparationEvent();   // No Arguments Constructor
	PreparationEvent(char type, int id, int day, int hour, int load, int dist, int cost);   // Arguments Constructor
	void Execute(Company* C);   // Prepares A Cargo
	void setType(char type);   //Sets Prepared Cargo Type
	void setLoad(int load);   // Sets Prepared Cargo Loading and Unloading Time
	void setDist(int dist);   // Sets Prepared Cargo Delievery Distance
	void setCost(int cost);   // Sets Prepared Cargo Shipping Cost
	char getType();   // Returns Prepared Cargo Type
	int getLoad();   // Returns Prepared Cargo Loading and Unloading Time
	int getDist();   // Returns Prepared Cargo Delievery Distance
	int getCost();   // Returns Prepared Cargo Shipping Cost
	~PreparationEvent();   // Destructor
};

