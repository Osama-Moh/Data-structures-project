#pragma once
#include "Company.h"

class Event
{
protected:
	int Day;
	int Hour;
	int ID;

public:
	Event();
	Event(int day, int hour, int id);
	virtual void Execute(Company* C) = 0;
	void setDay(int day);
	void setHour(int hour);
	void setID(int id);
	int getDay();
	int getHour();
	int getID();
	virtual ~Event();
};
