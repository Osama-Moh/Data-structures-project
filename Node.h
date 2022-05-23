#pragma once


template <typename T>
class Node
{
private:
	T Item;
	Node<T>* Next;
	float Key;

public:
	Node()
	{

	}
	Node(T newItem, float newKey=1, Node* newNext=nullptr)
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
	void setKey(float newKey)
	{
		Key = newKey;
	}
	T getItem()
	{
		return Item;
	}
	Node* getNext()
	{
		return Next;
	}
	float getKey()
	{
		return Key;
	}
	~Node()
	{
	}
};
