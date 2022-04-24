#pragma once
#include "LinkedQueue.h"
#include "Cargo.h"

class Event
{
private:
	char Type;
	int Day;
	int Hour;
	int ID;
public:
	Event();
	Event(char type, int day, int hour, int id);
	virtual void Execute(LinkedQueue<Cargo*> Q) = 0;
	void setType(char type);
	void setDay(int day);
	void setHour(int hour);
	void setID(int id);
	char getType();
	int getDay();
	int getHour();
	int getID();
	virtual ~Event();
};

