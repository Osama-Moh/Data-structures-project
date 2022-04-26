#include "PreparationEvent.h"
# include "Cargo.h"

PreparationEvent::PreparationEvent()
{
}
PreparationEvent::PreparationEvent(int id, int day, int hour, char type, int load, int dist, int cost):Event(id, day, hour)
{
	setType(type);
	setLoad(load);
	setDist(dist);
	setCost(cost);
}
void PreparationEvent::Execute(Company* C)
{
	Cargo* S=new Cargo(Type, Day, Hour, ID, Load, Dist, Cost);
	C->addCargo(S);
}
void PreparationEvent::setType(char type)
{
	Type=type;
}
void PreparationEvent::setLoad(int load)
{
	Load=load;
}
void PreparationEvent::setDist(int dist)
{
	Dist=dist;
}
void PreparationEvent::setCost(int cost)
{
	Cost=cost;
}
char PreparationEvent::getType()
{
	return Type;
}
int PreparationEvent::getLoad()
{
	return Load;
}
int PreparationEvent::getDist()
{
	return Dist;
}
int PreparationEvent::getCost()
{
	return Cost;
}
PreparationEvent::~PreparationEvent()
{
}
