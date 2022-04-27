#include "Event.h"


Event::Event()
{
}
Event::Event(int id, int day, int hour)
{
	setDay(day);
	setHour(hour);
	setID(id);
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
