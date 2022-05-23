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
	Truck* pTruckV = nullptr;
	Truck* pTruckS = nullptr;
	Truck* pTruckN = nullptr;
	Cargo* wCargo = nullptr;

	point->mainprint();
	openinput();

	int hourV = 1;
	int hourS = 1;
	int hourN = 1;

	int count = 0;
	while (Events.peek(pEvent) || SC.peek(wCargo) || VC.peek(wCargo) || !(NC.isEmpty()))		
	{
	
		while (pEvent->getDay() == days && pEvent->getHour() == hours)
		{
			if (hours < 5 && hours>=0)
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



		//if (NT.getcount() > 3 && hours == 7)
		//{
		//	NT.dequeue(ptrnt);
		//	moving.enqueue(ptrnt, 1);
		//}
		checkup();
		finishcheckup();
		int nsn = SC.getcount();					// delete this before submission 
		int vsv = VC.getcount();
		int ncc = NC.getCount();
		int n = NT.getcount() + ST.getcount() + VT.getcount();
		int nc = SC.getcount() + VC.getcount() + NC.getCount();
		int TDC = DeliveredNC.getcount() + DeliveredSC.getcount() + DeliveredVC.getcount();
		int TMT = Checknormal.getcount() + Checkspecial.getcount() + Checkvip.getcount();

		point->printmode(n, nc, TDC, hours, days,TMT, &NC, &SC, &VC, &NT, &ST, &VT, &DeliveredNC, &DeliveredSC, &DeliveredVC, &Checknormal, &Checkspecial, &Checkvip, &moving);


		if (hours >= 5 && hours <= 23)
		{
			pCargo = nullptr;
			VC.peek(pCargo);
			manageLoading(pTruckV, pCargo, hourV);
			pCargo = nullptr;
			SC.peek(pCargo);
			manageLoading(pTruckS, pCargo, hourS);
			pCargo = nullptr;
			NC.peekFront(pCargo);
			manageLoading(pTruckN, pCargo, hourN);
		}


		hours++;
		if (hours == 24)
		{
			hours = 0;
			days++;
		}

	}
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
		VC.enqueue(S,S->getPRIORITY());
}

Cargo* Company::removeCargo(int ID)
{
	return NC.removeCargo(ID);
}

void Company::promoteCargo(int ID, int ExtraCost)
{
	Cargo* S = removeCargo(ID);
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
	output << "CDT" << "    " << "ID" << "    " << "PT" << "    " << "WT" << "    " << "TID" << endl;
	totalcargos = Deliveredcargos.getcount();
	while (Deliveredcargos.dequeue(print))
	{
		output << "    " << print->getID() << "    " << print->getPTD() << ":" << print->getPTH() << "    " << endl;
		
	}
	output << "------------------------------------------------------------" << endl;
	output << "------------------------------------------------------------" << endl;
	output << "Cargos: " << totalcargos << "   [N: " << totalnormal<< ", S: " << totalspecial << ", V: " << totalvip <<"]" << endl;
	output << "Trucks: " << NT.getcount() + ST.getcount() + VT.getcount();
	output << "   " << "[" << "N: " << NT.getcount() << ", S: " << ST.getcount() << ", V: " << VT.getcount() << "]" << endl;
	//int avgwait = totalwait / totalcargos;
	//output << "AVG WT:  " << avgwait;
}

void Company::print()
{
	SC.print();
}

Truck* Company::assignVIPCargos()
{
	Truck* pTruck = nullptr;
	if (VT.peek(pTruck))
		if (VC.getcount() >= pTruck->getTC())
		{
			VT.dequeue(pTruck);
			return pTruck;
		}
	else if (NT.peek(pTruck) && VT.getcount()==0)
		if (VC.getcount() >= pTruck->getTC())
		{
			NT.dequeue(pTruck);
			return pTruck;
		}
	else if (ST.peek(pTruck) && VT.getcount()== 0 && NT.getcount()== 0)
		if (VC.getcount() >= pTruck->getTC())
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
	else if (VT.peek(pTruck) && NT.getcount()==0)
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

Truck* Company::assignMaxwCargo()
{
	Truck* pTruck = nullptr;
	if (NT.peek(pTruck))
		return pTruck;
	if (VT.peek(pTruck))
		return pTruck;
}

void Company::loadCargo(Truck* pTruck, Cargo* pCargo)
{
	if (pCargo->getTYP() == 'N')
		NC.DeleteBeg(pCargo);
	if (pCargo->getTYP() == 'S')
		SC.dequeue(pCargo);
	if (pCargo->getTYP() == 'V')
		VC.dequeue(pCargo);
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

void Company::manageLoading(Truck*& pTruck, Cargo*& pCargo, int& hourL)
{
	if (!pCargo)
		return;
	if (pTruck != nullptr)
	{
		hourL++;
		if (pCargo->getLT() == hourL)
		{
			loadCargo(pTruck, pCargo);
			hourL = 0;
			if (pTruck->isFull() || reachedMaxW(pCargo))
			{
				hourL = 1;
				moveTruck(pTruck);
				pTruck = nullptr;
				return;
			}
		}
	}
	if (pTruck == nullptr)
	{
		pTruck = assignCargos(pCargo->getTYP());
		if (!pTruck && reachedMaxW(pCargo))
			pTruck = assignMaxwCargo();
		if (pCargo->getLT() == hourL)
		{
			loadCargo(pTruck, pCargo);
			hourL = 0;
			if (pTruck->isFull() || reachedMaxW(pCargo))
			{
				hourL = 1;
				moveTruck(pTruck);
				pTruck = nullptr;
				return;
			}
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
	int xxx = 0;
	Cargo* C = nullptr;
	pTruck->Move();
	pTruck->getpeek(C);
	if (C != nullptr)
	{
		xxx = C->getCDT();
		moving.enqueue(pTruck, xxx); // Priority Needs To Be Implemented
	}
	if (C->getCDT() == (days * 24 + hours))
	{
		moving.dequeue(pTruck);
	}
}

