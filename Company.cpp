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

		point->printmode(n, nc, TDC, hours, days,TMT, &NC, &SC, &VC, &NT, &ST, &VT, &DeliveredNC, &DeliveredSC, &DeliveredVC, &Checknormal, &Checkspecial, &Checkvip, &moving, pTruckN, pTruckS, pTruckV);


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
	for (int j = 1; j <= STN+1; j++)
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
	if (NT.peek(pTruck) && VT.getcount()==0)
		if (VC.getcount() >= pTruck->getTC())
		{
			NT.dequeue(pTruck);
			return pTruck;
		}
	if (ST.peek(pTruck) && VT.getcount()== 0 && NT.getcount()== 0)
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

void Company::autoPromote(Cargo* pCargo)
{
	while (NC.peekFront(pCargo))
		if (24 * (days - pCargo->getPTD()) + (hours - pCargo->getPTH()) >= 24 * AutoP)
			promoteCargo(pCargo->getID(), 0);
		else
		{
			return;
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
		if (pCargo->getLT() == hourL)
		{
			loadCargo(pTruck, pCargo);
			hourL = 0;
			if (pTruck->isFull() || isMaxW)
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

void Company::moveTruck(Truck* pTruck)
{
	int xxx = 0;
	int ttt = 0;
	Cargo* C = nullptr;
	pTruck->Move();
	pTruck->getpeek(C);

	//int count=moving.getcount()
	while (pTruck->getpeek(C))
	{
		int idd = C->getID();
		if (C->getCDT() == (days * 24 + hours))
		{
			moving.dequeue(pTruck);
			// call dilevered 
		}
		else //if (C->getCDT() > (days * 24 + hours) )      // && moving.peek() != pTruck && moving .getcount() !=count
		{			
			xxx = C->getCDT();
			moving.enqueue(pTruck, xxx);
			break;
		}

	}
	if (C == nullptr)
	{
		if ((pTruck->getRDAY() * 24 + pTruck->getRHOUR()) == (days * 24 + hours))
		{
			moving.dequeue(pTruck);
		}
		else
		{
			ttt = pTruck->getRHOUR() + pTruck->getRDAY() * 24;
			moving.enqueue(pTruck, ttt);
		}

	}
	int com = moving.getcount();
}