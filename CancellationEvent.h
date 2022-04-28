#pragma once
#include "Event.h"


class CancellationEvent: public Event
{
public:
	CancellationEvent();   // No Arguments Constructor
	CancellationEvent(int id, int day, int hour);   // Arguments Constructor
	void Execute(Company* C);   // Cancels A Cargo
	~CancellationEvent();   // Destructor
};
