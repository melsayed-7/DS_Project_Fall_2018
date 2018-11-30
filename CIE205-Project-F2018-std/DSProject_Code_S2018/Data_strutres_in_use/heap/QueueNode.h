#pragma once
template<typename T>
class QueueNode
{
private:
	T data;
	double priority;


public:
	QueueNode();
	QueueNode(T dat, double prio);

	T getdata() const;
	double getpriority() const;

	void setdata(T dat);
	void setpriority(double prio);
	~QueueNode();
};

template<typename T>
QueueNode<T>::QueueNode()
{
}

template<typename T>
QueueNode<T>::QueueNode(T dat, double prio)
{
	priority = prio;
	data = dat;
}

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
