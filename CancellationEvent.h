#pragma once
#include "Event.h"


class CancellationEvent: public Event
{
public:
	CancellationEvent();
	CancellationEvent(int id, int day, int hour);
	void Execute(Company* C);
	~CancellationEvent();
};
