#pragma once
#include "Cargo.h"
#include <iostream>
using namespace std;
class Company;

class Event
{
protected:
	int Day;   // Event Execution Day
	int Hour;   // Event Execution Hour
	int ID;   // Executed Cargo ID

public:
	Event();   // No Arguments Constructor
	Event(int id, int day, int hour);   // Arguments Constructor
	virtual void Execute(Company* C) = 0;   // Executes Event
	void setDay(int day);   // Sets Event Execution Day
	void setHour(int hour);   // Sets Event Execution Hour
	void setID(int id);   // Sets Executed Cargo ID
	int getDay();   // Returns Event Execution Day
	int getHour();   // Returns Event Execution Hour
	int getID() const;   // Returns Executed Cargo ID
	virtual ~Event();   // Destructor
	friend ostream& operator << (ostream& out, const Event& E);
};

