//#pragma once
//#include "pch.h"
#include "stdafx.h"
#include "QueueNode.h"

template<typename T>
QueueNode<T>::QueueNode()
{

}

//template<typename T>
//QueueNode<T>::QueueNode(T dat, double prio)
//{
//	priority = prio;
//	data = dat;
//}

template<typename T>
T QueueNode<T>::getdata() const
{
	return data;
}

template<typename T>
double QueueNode<T>::getpriority() const
{
	return priority;
}

template<typename T>
void QueueNode<T>::setdata(T dat) 
{
	data = dat;
}

template<typename T>
void QueueNode<T>::setpriority(double prio)
{
	priority = prio;
}

template<typename T>
QueueNode<T>::~QueueNode()
{
}
