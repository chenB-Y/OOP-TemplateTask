#pragma once
#include "Lnode.h"
template <class T>
class List 
{

private:
	Lnode<T>* head;
public:
	List() : head(nullptr)
	{
	}
	List(const List& liset)
	{
		this->head = liset->head;
	}
	~List()
	{
		Lnode<T>* node = this->head;
		Lnode<T>* tempNode;
		while (node != nullptr)
		{
			tempNode = node;
			node = tempNode->getnext();
			delete tempNode;
		}
	}
	void insertNode(const T& data);
	Lnode<T>* find(const T& data);
	void remove(Lnode<T>* node);
	void print();
	void printReverse();
	Lnode <T>* begin();
	Lnode <T>* end();
};
template <class T>
void List<T>::insertNode(const T& _data)
{
	Lnode<T>* newNode = new Lnode<T>(_data);
	if (head != nullptr)
	{
		newNode->setnext(head);
		head->setprevious(newNode->getnext());
	}
	head = newNode;
}
template <class T>
Lnode<T>* List<T>::find(const T& data)
{
	Lnode<T>* node = head;
	while (node->getnext() != nullptr)
	{
		if (head->getdata()== data)
			return head;
		else
			head = head->getnext();
	}
	return head;
}
template <class T>
void List<T>::remove(Lnode<T>* n)
{
	Lnode<T>* tempnode, * tempnode2;
	if (head == nullptr)
	{
		cout << "LIST IS EMPTY" << endl;
		return;
	}
	else if (head->getdata() == n->getdata())
	{
		tempnode = head;
		if (head->getnext() != nullptr)
		{
			head = head->getnext();
			head->setprevious(nullptr);
			delete tempnode;
			tempnode = nullptr;
		}
		else
		{
			delete head;
			head = nullptr;
			delete tempnode;
			tempnode = nullptr;
			return;
		}
	}
	tempnode2 = head;
	while (tempnode2->getnext()->getnext() != nullptr)
	{
		if (tempnode2->getnext()->getdata() == n->getdata())
		{
			tempnode = tempnode2->getnext();
			tempnode2->setnext(tempnode->getnext());
			tempnode->getnext()->setprevious(tempnode2);
			delete tempnode;
			tempnode = nullptr;
			return;
		}
		tempnode2 = tempnode2->getnext();
	}
	if (tempnode2->getnext()->getdata() == n->getdata())
	{
		tempnode = tempnode2->getnext();
		delete tempnode;
		tempnode = nullptr;
		tempnode->setnext(nullptr);
		return;
	}
	cout << "element not found" << endl;
}
template <class T>
void List<T>::print()
{
	Lnode<T>* temp = this->head;
	if (head == nullptr)
	{
		cout << "LIST IS EMPTY!" << endl;
		return;
	}
	int k = 1;
	cout << "Print of LinkedList:" << endl;
	while (temp != nullptr)
	{ 
		cout << "the data in the " << k << " place of the linkedlist is " << temp->getdata() << endl;
		temp = temp->getnext();
		k++;
	}
}
template <class T>
void List<T>::printReverse()
{
	stack<T> stack;
	Lnode<T>* temp = this->head;
	while (temp != nullptr)
	{
		stack.push(temp->getdata());
		temp = temp->getnext();
	}
	cout << "Print of REVERSE LinkedList" << endl;
	int k = 1;
	while (!stack.empty())
	{
		cout << "the data in the " << k <<" place of the linkedlist is " << stack.top() << endl;
		stack.pop();
		k++;
	}
}
template <class T>
Lnode<T>* List<T>::begin()
{
	cout << "the first node in the LinkedList is :"<< endl;
	return head;
}
template <class T>
Lnode <T>* List<T>::end()
{
	Lnode<T>* temp;
	temp = head;
	cout << "the last node in the LinkedList is :" << endl;
	while (temp->getnext() != nullptr)
	{
		temp = temp->getnext();
	}
	return temp;
}





