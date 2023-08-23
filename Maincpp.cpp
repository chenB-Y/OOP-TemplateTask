#include "List.h"
void main()
{
	List<int> l;
	for (int i = 0; i < 10; i++)
	{
		l.insertNode(i);
	}
	l.print();
	l.printReverse();
	cout << "******************************" << endl;
	cout << l.begin()->getdata() << endl;
	cout << "******************************" << endl;
	cout << l.end()->getdata() << endl;
	cout << "******************************" << endl;
	Lnode<int> n1(4);
	l.remove(&n1);
	Lnode<int> n2(7);
	l.remove(&n2);
	cout << "remove node with data 4 , 7" << endl;
	l.print();
	cout << "******************************" << endl;
	cout << "found at adress: " << endl;
	cout << l.find(5)<< endl;
	cout << "******************************" << endl;
	return;
}