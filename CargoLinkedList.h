#pragma once

#include "LinkedList.h"

class CargoLinkedList : public LinkedList<Cargo*>
{

public:

	Cargo* removeCargo(const int& ID)
	{
		int index = 1;
		Node<Cargo*>* reqCargo = Head;
		while (reqCargo)
		{
			if (reqCargo->getItem()->getID() == ID)
			{
				Cargo* temp = reqCargo->getItem();
				removeNode(temp, index);
				return temp;
			}
			reqCargo = reqCargo->getNext();
			index++;
		}
		return reqCargo->getItem();
	}

};