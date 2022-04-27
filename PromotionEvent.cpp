#include "PromotionEvent.h"
# include "Company.h"

PromotionEvent::PromotionEvent()
{
}
PromotionEvent::PromotionEvent(int id, int day, int hour, int extracost): Event(id, day, hour)
{
	setExtraCost(extracost);
}
void PromotionEvent::Execute(Company* C)
{
	C->promoteCargo(ID, ExtraCost);
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
