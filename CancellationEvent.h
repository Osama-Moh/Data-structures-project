#pragma once
#include "Event.h"


class CancellationEvent: public Event
{
public:
	CancellationEvent();
	CancellationEvent(char type, int id, int day, int hour);
	~CancellationEvent();
};