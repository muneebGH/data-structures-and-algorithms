#include<iostream>
#include"Stack.h"
using namespace std;
int main()
{
	int userSize;
	cout << "enter count" << endl;
	cin >>userSize;
	cout << "enter numbers\n";
	int * userArray = new int[userSize];
	for (int i = 0; i < userSize; i++)
	{
		cin >> userArray[i];
	}

	Stack<int> s;
	for (int i = 0; i < userSize; i++)
	{
		int j = i+1;
		if (j == userSize)
		{
			j = -1;
		}

		while (userArray[j] < userArray[i] && j>0)
		{
			j++;
			if (j == userSize)
			{
				j = -1;
				
			}
		}

		if (j == -1)
		{
			s.push(j);
		}
		else
		{
			s.push(userArray[j]);
		}
	}

	int i = userSize - 1;
	cout << "\n";
	while (!s.isEmpty())
	{
		cout << userArray[i] << ":" << s.pop() << "\n\n";
		i--;
	}
	system("pause");
	return 0;
}