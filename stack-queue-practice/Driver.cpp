#include<iostream>
#include"Queue.h"
#include"Stack.h"
using namespace std;
int main()
{

	int size;
	cout << "enter size\n";
	cin >> size;

	Queue<int> q(size);
	int element;
	for (int i = 0; i < size; i++)
	{
		cin >> element;

		q.enqueue(element);
	}

	int reverseCount;
	cout << "enter reverse count\n";
	cin >> reverseCount;
	
	Stack<int> s(reverseCount);
	for (int i = 0; i< reverseCount; i++)
	{
		s.push(q.dequeue());

	}


	for (int i = 0; i < reverseCount; i++)
	{
		q.enqueue(s.pop());

	}

	int range = size - reverseCount;
	for (int i = 0; i < range; i++)
	{
		element = q.dequeue();
		q.enqueue(element);
	}

	for (int i = 0; i < size; i++)
	{
		cout << q.dequeue() << " ";
	}
	system("pause");
	return 0;
}