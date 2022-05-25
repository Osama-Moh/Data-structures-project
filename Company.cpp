# include <iostream>
# include <string>
# include "Company.h"
# include "Truck.h"
# include "Cargo.h"

using namespace std;

Company::Company()
{
}

void Company::simulate()
{	
	Event* pEvent;
	Cargo* pCargo = new Cargo;
	Truck* pTruck = new Truck;
	Cargo* wCargo = nullptr;
	pTruckV = nullptr;
	pTruckS = nullptr;
	pTruckN = nullptr;

	point->mainprint();
	openinput();

	int hourV = 0;
	int hourS = 0;
	int hourN = 0;

	bool isMaxWN = false;
	bool isMaxWS = false;
	bool isMaxWV = false;

	while (Events.peek(pEvent) || SC.peek(wCargo) || VC.peek(wCargo) || !(NC.isEmpty()) || moving.peek(pTruck))		
	{
	
		if (pEvent != nullptr)
		{
			while (24 * pEvent->getDay() + pEvent->getHour() <= 24 * days + hours)
			{
				if (hours < 5 && hours >= 0)
				{
					pEvent->setHour(5);
				}
				else
				{
					if (!Events.dequeue(pEvent))
					{
						break;
					}
					pEvent->Execute(this);
					Events.peek(pEvent);
				}
			}
			pEvent = nullptr;
		}




		if (hours >= 5 && hours <= 23)
		{
			if (!pTruckN)
				autoPromote(pCargo);
			pCargo = nullptr;
			VC.peek(pCargo);
			manageLoading(pTruckV, pCargo, hourV, isMaxWV);
			pCargo = nullptr;
			SC.peek(pCargo);
			manageLoading(pTruckS, pCargo, hourS, isMaxWS);
			pCargo = nullptr;
			NC.peekFront(pCargo);
			manageLoading(pTruckN, pCargo, hourN, isMaxWN);
		}
		checkDelievered();



		finishcheckup();

		int n = NT.getcount() + ST.getcount() + VT.getcount();
		int nc = SC.getcount() + VC.getcount() + NC.getCount();
		int TDC = Deliveredcargos.getcount();
		int TMT = Checknormal.getcount() + Checkspecial.getcount() + Checkvip.getcount();
		
		point->printmode(n, nc, TDC, hours, days,TMT,countmoving, &NC, &SC, &VC, &NT, &ST, &VT, &Checknormal, &Checkspecial, &Checkvip, &moving, pTruckN, pTruckS, pTruckV, &Deliveredcargos);

		hours++;
		if (hours == 24)
		{
			hours = 0;
			days++;
		}

	}
	Fsimulationd = days - 1;
	FsimulationH = hours;
	point->printend();
	openoutput();
}

void Company::filltruckdata()
{
	for (int i = 1; i <= NTN; i++)
	{
		Truck* pointern = new Truck('N',NTC,CN,NTS,J,i);
		NT.enqueue(pointern);
	}
	for (int j = 2; j <= STN+1; j++)
	{
		Truck* pointers = new Truck('S',STC,CS,STS,J,j);
		ST.enqueue(pointers);
	}
	for (int k = 1; k <= VTN; k++)
	{
		Truck* pointerv = new Truck('V',VTC,CV,VTS,J,k);
		VT.enqueue(pointerv);
	}
}

void Company::readtruckdata()
{
	input >> NTN >> STN >> VTN >> NTS >> STS >> VTS >> NTC >> STC >> VTC >> J >> CN >> CS >> CV >> AutoP >> MaxW;
}

void Company::readevents()
{
	input >> E;
	for (int i = 1; i <= E; i++)
	{
		input >> ev;
		if (ev == 'R')
			input >> typ >> day >> colon >> hour >> id >> dist >> lt >> cost;
		if (ev == 'X')
			input >> day >> colon >> hour >> id;
		if (ev == 'P')
			input >> day >> colon >> hour >> id >> cost;
		filleventsdata();
	}
}

void Company::filleventsdata()
{
	Event* pointer;
	if (ev == 'R')
	{
		if (hour <= 23 && hour >= 0)
		{
			pointer = new PreparationEvent(typ, id, day, hour, lt, dist, cost);
			Events.enqueue(pointer);
		}
	}
	if (ev == 'X')
	{
		if (hour <= 23 && hour >= 0)
		{
			pointer = new CancellationEvent(id, day, hour);
			Events.enqueue(pointer);
		}
	}
	if (ev == 'P')
	{
		if (hour <= 23 && hour >= 0)
		{
			pointer = new PromotionEvent(id, day, hour, cost);
			Events.enqueue(pointer);
		}
	}
}

void Company::addCargo(Cargo* S)
{
	if (S->getTYP() == 'N')
		NC.InsertEnd(S);
	if (S->getTYP() == 'S')
		SC.enqueue(S);
	if (S->getTYP() == 'V')
		VC.enqueue(S,1/(S->getPRIORITY()));
}

Cargo* Company::removeCargo(int ID)
{
	if (pTruckN)
		if (NC.getOrder(ID) <= pTruckN->getTC() - pTruckN->getLoadedCount())
			return nullptr;
	return NC.removeCargo(ID);
}

void Company::promoteCargo(int ID, int ExtraCost)
{
	Cargo* S = removeCargo(ID);
	if (S == nullptr)
		return;
	S->setTYP('V');
	int Cost = S->getCOST() + ExtraCost;
	S->setCOST(Cost);
	addCargo(S);
}

void Company::openinput()
{
	fileinname = point->getfileinname();
	input.open(fileinname, ios::in);

	if (input.is_open() == true)
	{
		readtruckdata();
		filltruckdata();
		readevents();
	}
	input.close();
}

void Company::openoutput()
{
	fileoutname = point->getfileoutname();
	output.open(fileoutname, ios::out);
	if (output.is_open() == true)
	{
		writetofile();
	}
	output.close();
}

void Company::writetofile()
{
	Cargo* print;
	output << "CDT" << "     " << "ID" << "    " << "PT" << "	    " << "WT" << "			" << "TID" << endl;
	collect();
	while (Deliveredcargos.dequeue(print))
	{
		output << print->getCDTD() << ":" << print->getCDTH() << "    " << print->getID() << "    " << print->getPTD() << ":" << print->getPTH() << "    ";
		output << "    " << print->getWTD() << ":" << print->getWTH() << "			" << print->getTID() << endl;

		settotalwait(print->getWT());
	}
	output << "------------------------------------------------------------" << endl;
	output << "------------------------------------------------------------" << endl;
	output << "Cargos: " << TNOC << "   [N: " << TNONC << ", S: " << TNOSC << ", V: " << TNOVC << "]" << endl;
	averagedays = (gettotalwait() / TNOC) / 24;
	averagehours = (gettotalwait() / TNOC) % 24;
	output << "Cargo Avg. Wait: " << averagedays << ":" << averagehours << endl;
	output << "Auto-promoted Cargos: " << AUTOpercent << " %" << endl;
	output << "Trucks: " << TNOT;
	output << "   " << "[" << "N: " << NTN << ", S: " << STN << ", V: " << VTN << "]" << endl;
	writetrucksdata();
}

void Company::writetrucksdata()
{
	Truck* print;
	while (NT.dequeue(print))
	{
		settotalactive(print->getactivetime());
		setutilization(print->gettotalcargos(), print->getTC(), print->gettripcount(), print->getactivetime());
	}
	while (VT.dequeue(print))
	{
		settotalactive(print->getactivetime());
		setutilization(print->gettotalcargos(), print->getTC(), print->gettripcount(), print->getactivetime());
	}
	while (ST.dequeue(print))
	{
		settotalactive(print->getactivetime());
		setutilization(print->gettotalcargos(), print->getTC(), print->gettripcount(), print->getactivetime());
	}
	output << "Avg. Active time = " << (totalactivetime/TNOT)*100  << " % " << endl;
	output << "Avg. utilization = " << avgutilize/TNOT << " %" << endl;
}

void Company::collect()
{
	TNOC = Deliveredcargos.getcount();
	TNOT = NTN + STN + VTN;
	AUTOpercent = (Aucargo * 100) / TNONC;
}

void Company::print()
{
	SC.print();
}

Truck* Company::assignVIPCargos()
{
	Truck* pTruck = nullptr;
	if (VT.peek(pTruck))
		if (VC.getcount() >= pTruck->getTC() || (Events.isEmpty() && VC.getcount() <= pTruck->getTC()))
		{
			VT.dequeue(pTruck);
			return pTruck;
		}
	if (NT.peek(pTruck) && VT.getcount() == 0)
		if (VC.getcount() >= pTruck->getTC() || (Events.isEmpty() && VC.getcount() <= pTruck->getTC()))
		{
			NT.dequeue(pTruck);
			return pTruck;
		}
	if (ST.peek(pTruck) && VT.getcount() == 0 && NT.getcount() == 0)
		if (VC.getcount() >= pTruck->getTC() || (Events.isEmpty() && VC.getcount() <= pTruck->getTC()))
		{
			ST.dequeue(pTruck);
			return pTruck;
		}
	return nullptr;
}

Truck* Company::assignSpecialCargos()
{
	Truck* pTruck = nullptr;
	if (ST.peek(pTruck))
		if (SC.getcount() >= pTruck->getTC())
		{
			ST.dequeue(pTruck);
			return pTruck;
		}
	return nullptr;
}

Truck* Company::assignNormalCargos()
{
	Truck* pTruck = nullptr;
	if (NT.peek(pTruck))
		if (NC.getCount() >= pTruck->getTC())
		{
			NT.dequeue(pTruck);
			return pTruck;
		}
	if (VT.peek(pTruck) && NT.getcount() == 0)
		if (NC.getCount() >= pTruck->getTC())
		{
			VT.dequeue(pTruck);
			return pTruck;
		}
	return nullptr;
}

Truck* Company::assignCargos(char Type)
{
	if (Type == 'N')
		return assignNormalCargos();
	if (Type == 'S')
		return assignSpecialCargos();
	if (Type == 'V')
		return assignVIPCargos();
}

Truck* Company::assignMaxWNormalCargos()
{
	Truck* pTruck = nullptr;
	if (NT.peek(pTruck))
	{
		NT.dequeue(pTruck);
		return pTruck;
	}
	if (VT.peek(pTruck))
	{
		VT.dequeue(pTruck);
		return pTruck;
	}
	return nullptr;
}

Truck* Company::assignMaxWSpecialCargos()
{
	Truck* pTruck = nullptr;
	if (ST.peek(pTruck))
	{
		ST.dequeue(pTruck);
		return pTruck;
	}
	return nullptr;
}

Truck* Company::assignMaxwCargo(char Type)
{
	if (Type == 'N')
		return assignMaxWNormalCargos();
	if (Type == 'S')
		return assignMaxWSpecialCargos();
}

void Company::loadCargo(Truck* pTruck, Cargo* pCargo)
{
	if (pCargo->getTYP() == 'N')
	{
		TNONC++;
		pTruck->settotalcargos(1);
		NC.DeleteBeg(pCargo);
	}
	if (pCargo->getTYP() == 'S')
	{
		TNOSC++;
		pTruck->settotalcargos(1);
		SC.dequeue(pCargo);
	}
	if (pCargo->getTYP() == 'V')
	{
		TNOVC++;
		pTruck->settotalcargos(1);
		VC.dequeue(pCargo);
	}
	pTruck->loadCargo(pCargo);
}

bool Company::reachedMaxW(Cargo* pCargo)
{
	if (pCargo->getTYP() == 'V')
		return false;
	if ((24 * (days - pCargo->getPTD()) + (hours - pCargo->getPTH())) >= MaxW)
		return true;
	return false;
}

void Company::autoPromote(Cargo* pCargo)
{
	while (NC.peekFront(pCargo))
	{
		if (24 * (days - pCargo->getPTD()) + (hours - pCargo->getPTH()) >= 24 * AutoP)
		{
			Aucargo++;
			promoteCargo(pCargo->getID(), 0);
		}
		else
		{
			return;
		}
	}
}

void Company::getNext(Cargo*& pCargo)
{
	if (pCargo->getTYP() == 'N')
		if (!NC.peekFront(pCargo))
		{
			pCargo = nullptr;
			return;
		}
	if (pCargo->getTYP() == 'S')
		if (!SC.peek(pCargo))
		{
			pCargo = nullptr;
			return;
		}
	if (pCargo->getTYP() == 'V')
		if (!VC.peek(pCargo))
		{
			pCargo = nullptr;
			return;
		}
}

void Company::manageLoading(Truck*& pTruck, Cargo*& pCargo, int& hourL, bool& isMaxW)
{
	if (!pCargo)
		return;
	if (pTruck != nullptr)
	{
		hourL++;
		if (pCargo->getLT() <= hourL)
		{
			pTruck->settotalunloading(pCargo->getLT());
			pTruck->setfurthercargo(pCargo->getDIST());
			loadCargo(pTruck, pCargo);
			hourL = 0;
			if (pTruck->isFull() || isMaxW || (VC.isEmpty() && Events.isEmpty() && pCargo->getTYP() == 'V'))
			{
				moveTruck(pTruck);
				pTruck = nullptr;
				isMaxW = false;
			}
		}
	}
	if (pTruck == nullptr)
	{
		getNext(pCargo);
		if (!pCargo)
			return;
		pTruck = assignCargos(pCargo->getTYP());
		if (!pTruck && reachedMaxW(pCargo))
		{
			pTruck = assignMaxwCargo(pCargo->getTYP());
			if (pTruck)
				isMaxW = true;
		}
	}

}
void Company::checkup()
{

	Truck* ptrt;
	while (moving.peek(ptrt))
	{
		if (ptrt->getRDAY()==days && ptrt->getRHOUR()==hours)	
		{
			if (ptrt->getCOUNT() == ptrt->getN())
			{
				int finishtime = 0;
				int duration = 0;
				duration = ptrt->getMT();
				if ((duration+hours) <= 24)
				{
					finishtime = 24 - duration;
				}
				else if ((duration+hours) > 24)
				{
					finishtime = 24 - (duration - 24);
				}
				moving.dequeue(ptrt);
				if (ptrt->getTYP() == 'N')
				{
					Checknormal.enqueue(ptrt,finishtime);
					ptrt->setCOUNT(0);
					ptrt->setFTIME(duration, days, hours);
				}
				else if (ptrt->getTYP() == 'V')
				{
					Checkvip.enqueue(ptrt, finishtime);
					ptrt->setCOUNT(0);
					ptrt->setFTIME(duration, days, hours);
				}
				else if (ptrt->getTYP() == 'S')
				{
					Checkspecial.enqueue(ptrt, finishtime);
					ptrt->setCOUNT(0);
					ptrt->setFTIME(duration, days, hours);
				}
			}
			else
			{
				gotowait();
			}
		}
		else
		{
			break;
		}
	}
}

void Company::gotowait()
{
	Truck* ptrw;
	moving.dequeue(ptrw);
	if (ptrw->getTYP() == 'N')
	{
		NT.enqueue(ptrw);
	}
	else if (ptrw->getTYP() == 'V')
	{
		VT.enqueue(ptrw);
	}
	else if (ptrw->getTYP() == 'S')
	{
		ST.enqueue(ptrw);
	}
}

void Company::finishcheckup()
{
	Truck* ptrfn = new Truck;
	Truck* ptrfs = new Truck;
	Truck* ptrfv = new Truck;
	while (Checknormal.peek(ptrfn) || Checkspecial.peek(ptrfs) || Checkvip.peek(ptrfv))
	{
		if (ptrfn->getFDAY() == days && ptrfn->getFHOUR() == hours)
		{
			Checknormal.dequeue(ptrfn);
			NT.enqueue(ptrfn);
		}
		if (ptrfs->getFDAY() == days && ptrfs->getFHOUR() == hours)
		{
			Checkspecial.dequeue(ptrfs);
			ST.enqueue(ptrfs);
		}
		if (ptrfv->getFDAY() == days && ptrfv->getFHOUR() == hours)
		{
			Checkvip.dequeue(ptrfv);
			VT.enqueue(ptrfv);
		}
		else
		{
			break;
		}
	}
}

void Company::moveTruck(Truck* pTruck)
{
	pTruck->setRTIME(days, hours);
	pTruck->Move();
	countmoving = countmoving + pTruck->getmovingcargos();
	Cargo* pCargo = nullptr;
	if (pTruck->getpeek(pCargo))
	{
		pCargo->setCDT(days, hours, pTruck->getV(), pCargo->getDIST());
		moving.enqueue(pTruck, pCargo->getCDT());
	}

}

void Company::checkDelievered()
{
	Truck* pTruck = nullptr;
	Cargo* pCargo = nullptr;
	while (moving.peek(pTruck))
	{
		if (pTruck->getpeek(pCargo))
		{
			if (pCargo->getCDT() <= 24 * days + hours)
			{
				int distance = pCargo->getDIST();
				pTruck->unloadCargo(pCargo);
				Deliveredcargos.enqueue(pCargo);
				countmoving--;
				moving.dequeue(pTruck);
				if (pTruck->getpeek(pCargo))
				{
					pCargo->setCDT(days, hours, pTruck->getV(), pCargo->getDIST() - distance);
					moving.enqueue(pTruck, pCargo->getCDT());
					pCargo = nullptr;
				}
				else
				{
					moving.enqueue(pTruck, 24*pTruck->getRDAY()+pTruck->getRHOUR());
					pCargo = nullptr;
				}
			}
			else
			{
				return;
			}
		}
		else
		{
			if (24 * pTruck->getRDAY() + pTruck->getRHOUR() <= 24 * days + hours)
			{
				pTruck->settripcount();
				pTruck->setCOUNT(1);
				checkup();
			}
			else
			{
				return;
			}
		}
	}	
}

void Company::settotalwait(int wait)
{
	totalwait = totalwait + wait;
}

int Company::gettotalwait()
{
	return totalwait;
}

void Company::settotalactive(int act)
{
	totalactivetime = act + totalactivetime;
}

void Company::setutilization(int count, int capacity, int trips, int active)
{
	if (trips == 0)
	{
		avgutilize = avgutilize + 0;
	}
	else
	{
		avgutilize = avgutilize + (count / (capacity * trips)) * (active * (Fsimulationd * 24 + FsimulationH));
	}
}
