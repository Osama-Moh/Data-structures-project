#include "CancellationEvent.h"
class Company;

CancellationEvent::CancellationEvent()
{
}
CancellationEvent::CancellationEvent(int day, int hour, int id): Event(day, hour, id)
{
}
void CancellationEvent::Execute(Company* C)
{
	Cargo* S=C->removeCargo(ID);
	delete S;
}
CancellationEvent::~CancellationEvent()
{
}
