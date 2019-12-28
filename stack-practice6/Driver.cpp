#include"Stack.h"
using namespace std;
int main()
{

	int userSize;
	cout << "enter size" << endl;
	cin >> userSize;
	int *  userArray = new int[userSize];
	cout << "enter numbers\n";
	for (int i = 0; i < userSize; i++)
	{
		cin >> userArray[i];
	}

	Stack<int> s;
	
	for (int i = userSize - 1; i >=0; i--)
	{
		int count = 1;
		int j = i - 1;
		while (j >=0)
		{
			if (userArray[j] <= userArray[i])
			{
				count++;
				j--;
			}
			else
			{
				j--;
			}
			
		}
		s.push(count);
	}
	cout << "\n";
	int i = 0;
	while (!s.isEmpty())
	{
		cout <<userArray[i]<<" : " <<s.pop() << endl;
		i++;
	}



	system("pause");
	return 0;
}