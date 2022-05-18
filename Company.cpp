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

	openinput();
	point->mainprint();

	int hourV = 0;
	int hourS = 0;
	int hourN = 0;

	int count = 0;
	while (Events.peek(pEvent) || Checknormal.peek(pTruck) || moving.peek(pTruck) || Checkspecial.peek(pTruck))		
	{
		if (hours >= 5 && hours <= 23)
		//	count++;
		while (pEvent->getDay() == days && pEvent->getHour() == hours)
		{
			if (hours < 5)
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

		//if (count == 5)
		//{
		//	if (SC.peek(pCargo))
		//	{
		//		SC.dequeue(pCargo);
		//		DeliveredSC.enqueue(pCargo, 1);
		//	}
		//	if (VC.peek(pCargo))
		//	{
		//		VC.dequeue(pCargo);
		//		DeliveredVC.enqueue(pCargo, 1);
		//	}
		//	if (NC.getCount())
		//	{
		//		NC.DeleteBeg(pCargo);
		//		DeliveredNC.enqueue(pCargo, 1);
		//	}
		//	count = 0;
		//}
		VC.peek(pCargo);
		manageLoading(pTruckV, pCargo, hourV);
		SC.peek(pCargo);
		manageLoading(pTruckS, pCargo, hourS);
		NC.peekFront(pCargo);
		manageLoading(pTruckV, pCargo, hourN);






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
		point->printmode(n, nc, TDC, hours, days, &NC, &SC, &VC, &NT, &ST, &VT,&DeliveredNC,&DeliveredSC,&DeliveredVC,&Checknormal);
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
		NT.enqueue(pointern,1);
	}
	for (int j = 1; j <= STN; j++)
	{
		Truck* pointers = new Truck('S',STC,CS,STS,J,j);
		ST.enqueue(pointers,1);
	}
	for (int k = 1; k <= VTN; k++)
	{
		Truck* pointerv = new Truck('V',VTC,CV,VTS,J,k);
		VT.enqueue(pointerv,1);
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
		pointer = new PreparationEvent(typ, id, day, hour, lt, dist, cost);
		Events.enqueue(pointer,1);
	}
	if (ev == 'X')
	{
		pointer = new CancellationEvent(id, day, hour);
		Events.enqueue(pointer, 1);
	}
	if (ev == 'P')
	{
		pointer = new PromotionEvent(id, day, hour, cost);
		Events.enqueue(pointer, 1);
	}
}

void Company::moveTruck(Truck* pTruck)
{
	if (pTruck->getTYP() == 'N')
		NT.dequeue(pTruck);
	if (pTruck->getTYP() == 'S')
		ST.dequeue(pTruck);
	if (pTruck->getTYP() == 'V')
		VT.dequeue(pTruck);
	pTruck->Move();
	moving.enqueue(pTruck, 1); // Priority Needs To Be Implemented
}

void Company::addCargo(Cargo* S)
{
	if (S->getTYP() == 'N')
		NC.InsertEnd(S);
	if (S->getTYP() == 'S')
		SC.enqueue(S,S->getPRIORITY());
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
	string name = point->getfileinname();
	input.open("data.txt", ios::in);

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
	string fileout = point->getfileoutname();
	output.open("Output.txt", ios::out);
	if (output.is_open() == true)
	{
		writetofile();
	}
	output.close();
}

void Company::writetofile()
{
	output << "CDT" << "    " << "ID" << "    " << "PT" << "    " << "WT" << "    " << "TID" << endl;
	

	output << "------------------------------------------------------------" << endl;
	output << "------------------------------------------------------------" << endl;
	output << "Cargos: " << totalcargos << "   [N: " << totalnormal<< ", S: " << totalspecial << ", V: " << totalvip <<"]" << endl;
	output << "Trucks: " << NT.getcount() + ST.getcount() + VT.getcount();
	output << "   " << "[" << "N: " << NT.getcount() << ", S: " << ST.getcount() << ", V: " << VT.getcount() << "]" << endl;
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
	else if (NT.peek(pTruck))
		if (VC.getcount() >= pTruck->getTC())
		{
			NT.dequeue(pTruck);
			return pTruck;
		}
	else if (ST.peek(pTruck))
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
	else if (VT.peek(pTruck))
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


void Company::manageLoading(Truck*& pTruck, Cargo*& pCargo, int& hourL)
{
	if (pTruck!=nullptr)
	{
		hourL++;
		if (pCargo->getLT() == hourL)
		{
			loadCargo(pTruck, pCargo);
			hourL = 0;
			if (pTruck->isFull())
				moveTruck(pTruck);
		}
	}
	if (pTruck == nullptr)
	{
		pTruck = assignCargos(pCargo->getTYP());
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
		NT.enqueue(ptrw, 1);
	}
	else if (ptrw->getTYP() == 'V')
	{
		VT.enqueue(ptrw, 1);
	}
	else if (ptrw->getTYP() == 'S')
	{
		ST.enqueue(ptrw, 1);
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
			NT.enqueue(ptrfn,1);
		}
		if (ptrfs->getFDAY() == days && ptrfs->getFHOUR() == hours)
		{
			Checkspecial.dequeue(ptrfs);
			ST.enqueue(ptrfs,1);
		}
		if (ptrfv->getFDAY() == days && ptrfv->getFHOUR() == hours)
		{
			Checkvip.dequeue(ptrfv);
			VT.enqueue(ptrfv,1);
		}
		else
		{
			break;
		}
	}
}
