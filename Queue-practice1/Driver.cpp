#include<iostream>
#include"CString.h"
#include"Queue.h"
using namespace std;
int main()
{

	int n;
	do
	{
		cout << "enter n :";
		cin >> n;
	} while (n < 0);
	
	CString first("1");
	Queue<CString> q(n);
	q.enqueue(first);
	
	
	for(int i=0;i<n;i++)
	{	
		first = q.dequeue();
		first.display();
		cout << " ";
		if (i + 1 < n)
		{
			q.enqueue(first.concact("0"));
		}
		i++;
		if (i + 1 < n)
		{
			q.enqueue(first.concact("1"));
		}
	}

	while (!q.isEmpty())
	{
		q.dequeue().display();
		cout << " ";
	}


	


	system("pause");
	return 0;
}