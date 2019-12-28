#include"Queue.h"
int main()
{


	Queue<int> q;


	for (int i = 0; i < 10; i++)
	{
		q.enqueue(i);
	}

	for (int i = 0; i < 3; i++)
	{
		q.dequeue();
 		q.enqueue(i + 10);
	}


	q.print();
	system("pause");
	return 0;
}