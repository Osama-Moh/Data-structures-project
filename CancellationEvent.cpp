#include "CancellationEvent.h"


CancellationEvent::CancellationEvent()
{
}
CancellationEvent::CancellationEvent(int day, int hour, int id): Event(day, hour, id)
{
}
void CancellationEvent::Execute(Company* C)
{
	//C->removeCargo(ID);
}
CancellationEvent::~CancellationEvent()
{
}
