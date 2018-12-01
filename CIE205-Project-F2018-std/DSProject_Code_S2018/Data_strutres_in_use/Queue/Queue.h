#pragma once
#include <iostream>
#include"Node.h"

using namespace std;
template <class T>


/* I took this part from the lab fo the sake of visualization

General Queue case:

				 frontPtr										backPtr
					\											   /
					 \											  /
					-------- 	--------	--------			--------
					|	|nxt -->|	|nxt -->|	|nxt -->........|	|nxt -->NULL
					--------	--------	--------			--------

Empty Case:

				 frontptr	 backptr
						\	 /
						 \	/
					---- NULL ------


Single Node Case:
				 frontPtr	 backPtr
					\		/
					 \	   /
					--------
					|	|nxt -->NULL
					--------

*/

class Queue
{
private:
	int size;
	Node<T>* frontptr;
	Node<T>* backptr;


public:
	Queue()
	{
		size = 0;
		frontptr = nullptr;
		backptr = nullptr;
	}

	bool isEmpty() const
	{
		
		if (frontptr == nullptr)
			return true;
		else
			return false;
	}


	T front() const//gets the element in the front 
	{
		if (isEmpty())
		{
			return false;
		}
		T val = frontptr->getitem();
		return val;

	}

	bool push_to_front(T val)// put an element to the front of the queue (we didn't use it but in case we needed)
	{
		Node <T> * newptr = new Node<T>(val);
		if (isEmpty())
		{
			frontptr = newptr; // The queue is empty
		}
		else
		{
			newptr->setnext(frontptr);
			frontptr = newptr; // New node is at back
		}

		size++;
		return true;
	}

	int getsize()
	{
		return size;
	}

	bool enque(T val)
	{
		Node <T> * newptr = new Node<T>(val);
		if (isEmpty())
		{
			frontptr = newptr; // The queue is empty
		}
		else
		{
			backptr->setnext(newptr); // The queue was not empty
		}
		backptr = newptr; // New node is at back
		size++;
		return true;

	}

	T deque()
	{
		if (size <= 0)
		{
			cout << "the queue is already empty";
			return nullptr;
		}
		T a;
		Node<T>* tempnode = frontptr;
		a = frontptr->getitem();
		frontptr = frontptr->getnext();

		// Queue is not empty; remove front
		if (tempnode == backptr)	 // Special case: one node in queue
			backptr = nullptr;

		// Free memory reserved by the dequeued node
		delete tempnode;
		size--;

		return a;
	}

	//void print_queue() const
	//{
	//	Node<T>* temp = frontptr;

	//	while (temp != nullptr)//if you did not reach the back of the queue
	//	{
	//		cout << temp->getitem()<< "  ";
	//		temp = temp->getnext();
	//	}
	//}

	~Queue()
	{

	}
};

