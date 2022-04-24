#include "Event.h"


Event::Event()
{
}
Event::Event(char type, int day, int hour, int id)
{
	setType(type);
	setDay(day);
	setHour(hour);
	setID(id);
}
void Event::setType(char type)
{
	Type=type;
}
void Event::setDay(int day)
{
	Day=day;
}
void Event::setHour(int hour)
{
	Hour=hour;
}
void Event::setID(int id)
{
	ID=id;
}
char Event::getType()
{
	return Type;
}
int Event::getDay()
{
	return Day;
}
int Event::getHour()
{
	return Hour;
}
int Event::getID()
{
	return ID;
}
Event::~Event()
{
}
