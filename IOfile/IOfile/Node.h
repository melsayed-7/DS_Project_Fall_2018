#pragma once
template <class T>
class Node
{
private:
	T item;
	Node <T>* next;

public:

	Node()
	{
		item = 0;
		next = nullptr;
	}

	Node(T a)
	{
		item = a;
		next = nullptr;
	}

	Node(T a,const  Node<T>* nextNodePtr)
	{
		item = a;
		next = nextNodePtr;	
	}
	
	void setitem(T a)
	{
		item = a;
	}

	void setnext(Node <T>* a)
	{
		next = a;
	}

	T getitem()
	{
		return item;
	}
	Node <T>* getnext()
	{
		return next;
	}
	

};

