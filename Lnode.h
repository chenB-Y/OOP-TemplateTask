#pragma once
#include <iostream>
#include <stack>
using namespace std;
template <class T>
class Lnode
{
private:
	T data;
	Lnode<T>* next;
	Lnode<T>* previous;
public:
	Lnode()
	{
	}
	~Lnode()
	{ 
	}
	Lnode(T dt)
	{
		this->data = dt;
		this->next = 0;
		this->previous = 0;
	}
	T getdata();
	Lnode<T>* getnext()const;
	Lnode<T>* getprevious() const;
	void setpdata(T _data);
	void setnext(Lnode<T>* next);
	void setprevious(Lnode<T>* prev);
};
template <class T>
T Lnode<T>::getdata()
{
	return this->data;
}
template <class T>
Lnode<T>* Lnode<T>::getnext() const 
{
	return this->next;
}
template <class T>
Lnode<T>* Lnode<T>::getprevious() const
{
	return this->previous;
}
template <class T>
void Lnode<T>::setpdata(T _data)
{
	this->data = _data;
}
template <class T>
void Lnode<T>::setnext(Lnode<T>* next)
{
	this->next = next;
}
template <class T>
void Lnode<T>::setprevious(Lnode<T>* prev)
{
	this->previous = prev;
}