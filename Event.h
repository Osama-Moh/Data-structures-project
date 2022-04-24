#pragma once
#include "LinkedQueue.h"
#include "Cargo.h"

class Event
{
private:
public:
	Event();
	Event(int ID);
	virtual void Execute(LinkedQueue<Cargo*> Q) = 0;
	virtual ~Event();
};

