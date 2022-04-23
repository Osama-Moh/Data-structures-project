#pragma once
# include <iostream>
using namespace std;
# include <string>

class truck
{
private:
	string trucktype;
	float truckcapacity;
	float maintenancetime;
	int j;															// number of journeys 
	float speed;													// in kilometers/hour
	int deliveryinterval;

public:
	truck()
	{

	}

	string gettrucktype()
	{
		return trucktype;
	}

	float gettruckcapacity()
	{
		return truckcapacity;
	}

};