#pragma once
#include "Event.h"


class PromotionEvent: public Event
{
private:
	int ExtraCost;
public:
	PromotionEvent();
	PromotionEvent(char type, int id, int day, int hour, int extracost);
	~PromotionEvent();
};
