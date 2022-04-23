#pragma once


template <typename T>
class Node
{
private:
	T Item;
	Node<T>* Next;
	int Key;

public:
	Node(T newItem, int newKey=1, Node* newNext=nullptr)
	{
		setItem(newItem);
		setNext(newNext);
		setKey(newKey);
	}

	void setItem(T newItem)
	{
		Item=newItem;
	}

	void setNext(Node* newNext)
	{
		Next=newNext;
	}

	void setKey(int newKey)
	{
		Key=newKey>=1?newKey:1;
	}

	T getItem()
	{
		return Item;
	}

	Node* getNext()
	{
		return Next;
	}

	int getKey()
	{
		return Key;
	}

	~Node()
	{

	}
};
