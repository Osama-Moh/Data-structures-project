#pragma once
#include "Event.h"


class PreparationEvent: public Event
{
private:
	int Dist;
	int Load;
	int Cost;
public:
	PreparationEvent();
	PreparationEvent(char type, int id, int day, int hour, int load, int dist, int cost);
	~PreparationEvent();
};

