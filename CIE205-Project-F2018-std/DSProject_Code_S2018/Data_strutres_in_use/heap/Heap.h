#pragma once
#include "QueueNode.h"
#include <iostream>
template<typename T>
class Heap 
{
private:
	QueueNode <T>	**Heap_arr;            // Pointer to dynamically allocated array
	int				 Current_number;        // Number of elements in the heap
	int			     Length;				// Full length of the array

	void swap(QueueNode <T>* &x, QueueNode <T>* &y); //  function to swap two elements 

	int get_parent_ind(int i);//get the parent index of node i 
	
	int get_left_ind(int i); //get the left child index of node i

	int get_right_ind(int i);//get the right child index of node i


public:
	
	Heap();
	
	Heap(int len);                     
	                     
	bool Enqueue(int priority, T  data);			// Add an item to the  and return true if succeeded
	T Dequeue();                       // Get item at the root
	
	//void printAll();								// Print all the elements in the heap
	int getcurrent_number()const ;                  // Return the currnet number of elements in the heap
	int get_size() const;
	
	~Heap();
};


template<typename T>
Heap <T>::Heap()
{
	Length = 300;
	Heap_arr = new QueueNode <T>*[Length]; //Although the value is known before the use , but for the sake of consistancy we will dynamically allocate it
	Current_number = 0;

	for (int i = 0; i < Length; i++)
	{
		Heap_arr[i] = nullptr;
	}

}

template<typename T>
Heap<T>::Heap(int len)
{
	Length = len;
	Heap_arr = new QueueNode <T>*[Length]; //Although the value is known before the use , but for the sake of consistancy we will dynamically allocate it
	Current_number = 0;

	for (int i = 0; i < Length; i++)
	{
		Heap_arr[i] = nullptr;
	}

}

template<typename T>
int Heap<T>::getcurrent_number() const
{
	return Current_number;
}

template<typename T>
int Heap<T>::get_size() const
{
	return Length;
}


template<typename T>
inline void Heap<T>::swap(QueueNode<T>*& x, QueueNode<T>*& y)// in order to work more efficiently i made it inline function
{
	{
		QueueNode<T>* temp = x;
		x = y;
		y = temp;
	}

}

template<typename T>
int Heap<T>::get_parent_ind(int i)
{
	return (i - 1) / 2;
}

template<typename T>
int Heap<T>::get_left_ind(int i)
{
	return (2 * i + 1);
}

template<typename T>
int Heap<T>::get_right_ind(int i)
{
	return (2 * i + 2);
}

template<typename T>
Heap <T> ::~Heap()//because we don't want to free the memory as we will use the objects in other fields
{
	for (int i = 0; i < Length; i++)
	{
		Heap_arr[i] = nullptr;
	}
}

template<typename T>
bool Heap<T>::Enqueue(int priority, T data)
{
	if (Current_number <= Length) //if the heap is not full
	{
		int ind = Current_number;//get the last empty index of the array

		Current_number++;//increase the number by 1

		QueueNode <T>*new_node = new QueueNode<T>(data, priority);

		Heap_arr[ind] = new_node;//putting the new node at the end of the array
		//i preferred while looping than recursion in order to save stack memory

		while (ind > 0 && Heap_arr[ind]->getpriority() > Heap_arr[get_parent_ind(ind)]->getpriority())//loop until the parent node i greater than the wanted node or until you reach the root
		{
			swap(Heap_arr[ind], Heap_arr[get_parent_ind(ind)]);//swap both nodes

			ind = get_parent_ind(ind);//update the index to match the index of the wanted node
		}

		return true;
	}

	return false;
}



template<typename T>
T Heap<T>::Dequeue()
{
	if (Current_number == 0)
	{
		std ::cout << "\nthe queue is empty";
		return nullptr;
	}
	QueueNode<T>* rootnode = Heap_arr[0];

	swap(Heap_arr[0], Heap_arr[Current_number - 1]);//swap the array with the last index of the array 
	Heap_arr[Current_number - 1]= nullptr;
	Current_number--; //decrease the size by 1
	
	if (Current_number == 0) return rootnode->getdata();//if the heap has only one element

	int ind = 0;
	int left = get_left_ind(ind);
	int right = get_right_ind(ind);
	int  max = 0;
	bool cond = true;

	while (cond)//loop until you get to the end of the heap or the current node is greater than or equal to it's chilren

	{//always swap between the current node and it's biggest child
	
		cond = false;
		if (ind < Current_number)
		{
			if (Heap_arr[right] != nullptr)
			{
				if (Heap_arr[ind]->getpriority() < Heap_arr[right]->getpriority())
				{
					cond = true;
				}
			}

			if (Heap_arr[left] != nullptr)
			{
				if (Heap_arr[ind]->getpriority() < Heap_arr[left]->getpriority())
				{
					cond = true;
				}
			}
		}
		
		else
		{
			cond = false;
		}

		if (Heap_arr[right]==nullptr || (Heap_arr[left]->getpriority() > Heap_arr[right]->getpriority()))
		{
			max = left;
		}
		else
		{
			max = right;
		}

		if (Heap_arr[max] != nullptr)
		{
			if (Heap_arr[ind]->getpriority() < Heap_arr[max]->getpriority())
			{
				swap(Heap_arr[ind], Heap_arr[max]);//swap the current element with the left child

				ind = max;//update the indices of the current elemnt and it;s children
				left = get_left_ind(ind);
				right = get_right_ind(ind);

			}
		}
		else// you are in a leaf
		{
			return rootnode->getdata();
		}
	}

	return rootnode->getdata();
}

