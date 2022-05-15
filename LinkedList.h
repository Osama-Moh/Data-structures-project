#ifndef _LINKEDLIST
#define _LINKEDLIST

#include "Node.h"
#include "Cargo.h"

template <typename T>
class LinkedList
{
protected:
	Node<T> *Head;	//Pointer to the head of the list
	//You can add tail pointer too (depending on your problem)

	int count;

	Node<T>* getPointerTo(const int& index)
	{
		int move=1;
		Node<T>* temp=Head;
		while (temp && move<index)
		{
			temp=temp->getNext();
			move++;
		}
		return temp;
	}


public:


	LinkedList()
	{
		Head = nullptr;
		count=0;
	}

	//List is being desturcted ==> delete all items in the list
	~LinkedList()
	{
		DeleteAll(); 
	}
	////////////////////////////////////////////////////////////////////////
	/*
	* Function: PrintList.
	* prints the values of all nodes in a linked list.
	*/
	void PrintList()	const
	{		
		cout<<"\nPrinting list contents:\n\n";
		Node<T> *p = Head;

		while(p)
		{
			cout << "[ " << p->getItem() << " ]";
			cout << "--->";
			p = p->getNext();
		}
		cout << "NULL\n";
	}
	////////////////////////////////////////////////////////////////////////
	/*
	* Function: InsertBeg.
	* Creates a new node and adds it to the beginning of a linked list.
	* 
	* Parameters:
	*	- data : The value to be stored in the new node.
	*/
	void InsertBeg(const T& data)
	{
		Node<T>* R = new Node<T>;
		R->setItem(data);
		R->setNext(Head);
		Head = R;
		count++;
	}

	void InsertEnd(const T& data)
	{
		Node <T>* front = new Node<T>(data);
		front->setNext(NULL);

		if (Head == NULL)
		{
			Head = front;
		}
		else
		{
			Node<T>* rear = Head;

			while (rear->getNext())
			{
				rear = rear->getNext();
			}

			rear->setNext(front);
		}

	}

	////////////////////////////////////////////////////////////////////////
	/*
	* Function: DeleteAll.
	* Deletes all nodes of the list.
	*/
	bool DeleteBeg(T& data)
	{
		if (!Head)
			return false;
		Node<T>* R = Head;
		Head = Head->getNext();
		T = R->getItem();
		delete R;
		R = nullptr;
		count--;
		return true;
	}

	bool DeleteEnd(T& data)
	{
		if (!Head)
			return false;
		Node<T>* R = Head;
		while (R->getNext())
			R = R->getNext();
		T = R->getItem();
		delete R;
		R = nullptr;
		count--;
		return true;
	}

	void DeleteAll()
	{
		Node<T> *P = Head;
		while (Head)
		{
			P = Head->getNext();
			delete Head;
			Head = P;
		}
		count=0;
	}

	int getCount()
	{
		return count;
	}

	bool insertNode(const T& newItem, const int& index)
	{
		if (index==1)
		{
			Node<T>* newNode=new Node<T>;
			newNode->setItem(newItem);
			newNode->setNext(Head);
			Head=newNode;
			count++;
			return true;
		}
		Node<T>* prev=getPointerTo(index-1);
		if (prev)
		{
			Node<T>* newNode=new Node<T>;
			newNode->setItem(newItem);
			newNode->setNext(prev->getNext());
			prev->setNext(newNode);
			count++;
			return true;
		}
		return false;
	}

	bool removeNode(T& oldItem, const int& index)
	{
		if (index==1)
		{
			Node<T>* temp=Head;
			Head=Head->getNext();
			oldItem=temp->getItem();
			delete temp;
			temp=nullptr;
			count--;
			return true;
		}
		Node<T>* prev=getPointerTo(index-1);
		Node<T>* temp=getPointerTo(index);
		if (temp)
		{
			prev->setNext(temp->getNext());
			oldItem=temp->getItem();
			delete temp;
			temp=nullptr;
			count--;
			return true;
		}
		return false;
	}

	void Reverse()
	{
		Node <T>* previous = NULL;
		Node <T>* current = Head;
		Node <T>* next = NULL;
		while (current)
		{
			next = current->getNext();
			current->setNext(previous);
			previous = current;
			current = next;
		}
		Head = previous;
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
};

#endif	
