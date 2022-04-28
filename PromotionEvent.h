#pragma once
#include "Event.h"
class Company;


class PromotionEvent: public Event
{
private:
	int ExtraCost;   // Promoted Cargo Extra Cost
public:
	PromotionEvent();   // No Arguments Constructor
	PromotionEvent(int id, int day, int hour, int extracost);   // Arguments Constructor
	void Execute(Company* C);   // Promotes A Cargo
	void setExtraCost(int extracost);   // Sets Promoted Cargo Extra Cost
	int getExtraCost();   // Returns Promoted Extra Cost
	~PromotionEvent();   // Destructor
};
