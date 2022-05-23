#pragma once
#include "Node.h"


template <typename T>
class PriorityQueue: public QueueADT<T>
{
private:
	Node<T>* Head;
	int	count = 0;
public:
	//Constructor
	PriorityQueue()
	{
		Head = nullptr; 
	}

	//Function that enqueues the elemtents sorted according to the key
	bool enqueue(const T& newEntry, float newKey)
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
		count++;
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
		count--;
		return true;

	}

	int getcount()
	{
		return count;
	}
	//Function the checks the first element.
	bool peek(T& oldEntry) const
	{
		if (isEmpty())
			return false;

		oldEntry=Head->getItem();
		return true;

	}

	//Function that checks whether the queue is empty or not
	bool isEmpty() const
	{
		return (Head == nullptr);
	}

	void print() 
	{
		T item;
		Node<T>* ptr = Head;
		while (ptr)
		{
			item = ptr->getItem();
			cout << *item;
			if (ptr->getNext())
				cout << ",";
			ptr = ptr->getNext();
		}
	}
	
	~PriorityQueue()
	{
		T temp;
		while(dequeue(temp))
		{
		}
	}
};