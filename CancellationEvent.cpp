#include "CancellationEvent.h"
# include "Company.h"
CancellationEvent::CancellationEvent()
{
}
CancellationEvent::CancellationEvent(int id, int day, int hour): Event(id, day, hour)
{
}
void CancellationEvent::Execute(Company* C)
{
	Cargo* S=C->removeCargo(ID);
	if (S != nullptr)
		delete S;
}
CancellationEvent::~CancellationEvent()
{
}
