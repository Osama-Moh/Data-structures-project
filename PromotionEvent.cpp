#include "PromotionEvent.h"


PromotionEvent::PromotionEvent()
{
}
PromotionEvent::PromotionEvent(int day, int hour, int id, int extracost): Event(day, hour, id)
{
	setExtraCost(extracost);
}
void PromotionEvent::Execute(Company* C)
{
	//C->promoteCargo(ID, ExtraCost);
}
void PromotionEvent::setExtraCost(int extracost)
{
	ExtraCost=extracost;
}
int PromotionEvent::getExtraCost()
{
	return ExtraCost;
}
PromotionEvent::~PromotionEvent()
{
}
