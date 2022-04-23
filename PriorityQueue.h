#pragma once
#include "Node.h"


template <typename T>
class PriorityQueue: public QueueADT<T>
{
private:
	Node<T>* Head;

public:
	//Constructor
	PriorityQueue()
	{
		Head = nullptr; 
	}

	//Function that enqueues the elemtents sorted according to the key
	bool enqueue(const T& newEntry, const int& newKey)
	{
		//Creating the new node to be inserted 
		Node<T>* temp = new Node<T>(newEntry, newKey);
		Node<T>* ptr;

		//If the entry is in the first place or the list is empty
		if (Head == nullptr || (temp->getKey() < Head->getKey()))
		{
			temp->setNext(Head);
			Head = temp;
		}
		//General Case
		else
		{
			ptr = Head;
			while (ptr->getNext() != nullptr && ptr->getNext()->getKey() <= temp->getKey())
				ptr = ptr->getNext();

			temp->setNext(ptr->getNext());
			ptr->setNext(temp);
		}
		return true;
	}

	//Function the takes out elements out of the queue
	bool dequeue(T& oldEntry)
	{
		if (isEmpty())
			return false;
		
		oldEntry=Head->getItem();
		Node<T>* temp=Head;
		Head=Head->getNext();

		delete temp;
		temp=nullptr;
		return true;

	}

	//Function the checks the first element.
	bool peek(T& oldEntry)
	{
		if (isEmpty())
			return false;

		oldEntry=Head->getItem();
		return true;

	}

	//Function that checks whether the queue is empty or not
	bool isEmpty()
	{
		return (Head == nullptr);
	}

	
	~PriorityQueue()
	{
		T temp;
		while(dequeue(temp))
		{
		}
	}
};