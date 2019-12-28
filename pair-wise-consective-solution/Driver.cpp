#include<iostream>
#include"Queue.h"
using namespace std;
bool pairWiseConsecutive(Queue<int> ref);
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

	if (pairWiseConsecutive(q))
	{
		cout << "it is pairwise consecutive\n";
	}
	else
	{
		cout << "it isnt pair wise consecutive\n";
	}

	cout << "the queue is : "; q.print();
	system("pause");
	return 0;
}



bool pairWiseConsecutive(Queue<int> ref)
{
	int a;
	int b;
	while (!ref.isEmpty())
	{
		a = ref.dequeue();
		b = ref.dequeue();
		if (b - a != 1)
		{
			return false;
		}
	}


	return true;
}