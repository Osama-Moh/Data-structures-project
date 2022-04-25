#pragma once
#include "Event.h"


class PromotionEvent: public Event
{
private:
	int ExtraCost;
public:
	PromotionEvent();
	PromotionEvent(int id, int day, int hour, int extracost);
	void Execute(Company* C);
	void setExtraCost(int extracost);
	int getExtraCost();
	~PromotionEvent();
};
