#ifndef _LINKEDLIST
#define _LINKEDLIST

#include "Node.h"
#include "Cargo.h"

template <typename T>
class LinkedList
{
private:
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
	void InsertBeg(const T &data)
	{
		Node<T> *R = new Node<T>;
		R->setItem(data);
		R->setNext(Head);
		Head = R;
		count++;
	}

	////////////////////////////////////////////////////////////////////////
	/*
	* Function: DeleteAll.
	* Deletes all nodes of the list.
	*/
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
			newNode->setNext(temp->getNext());
			temp->setNext(newNode);
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

	Cargo* removeCargo(const int& ID)
	{
		int index=1;
		Node<Cargo*>* reqCargo=Head;
		while (reqCargo)
		{
			if (reqCargo->getItem()->getID()==ID)
			{
				removeNode(reqCargo, index);
				return reqCargo;
			}
			reqCargo=reqCargo->getNext();
			index++;
		}
		return reqCargo;
	}

	////////////////     Requirements   ///////////////////
	//
	// Implement the following member functions


	//[1]InsertEnd 
	//inserts a new node at end if the list
	void InsertEnd(const T &data);	

	//[2]Find 
	//searches for a given value in the list, returns true if found; false otherwise.
	bool Find(int Key);

	//[3]CountOccurance
	//returns how many times a certain value appeared in the list
	int CountOccurance(const T &value);

	//[4] DeleteFirst
	//Deletes the first node in the list
	void DeleteFirst();


	//[5] DeleteLast
	//Deletes the last node in the list
	void DeleteLast();

	//[6] DeleteNode
	//deletes the first node with the given value (if found) and returns true
	//if not found, returns false
	//Note: List is not sorted
	bool DeleteNode(const T &value);	

	//[7] DeleteNodes
	//deletes ALL node with the given value (if found) and returns true
	//if not found, returns false
	//Note: List is not sorted
	bool DeleteNodes(const T &value);	

	//[8]Merge
	//Merges the current list to another list L by making the last Node in the current list 
	//point to the first Node in list L
	void Merge(const LinkedList& L);

	//[9] Reverse
	//Reverses the linked list (without allocating any new Nodes)
	void Reverse();
		
};

#endif	
