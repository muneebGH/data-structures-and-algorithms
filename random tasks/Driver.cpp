#include<iostream>
using namespace std;
int main()
{


	int count;
	cin >> count;

	int k;
	cin >> k;
	int * p = new int[count];
	for (int i = 0; i < count; i++)
	{
		cin >> p[i];
	}

	if (p[k] > 0)
	{
		cout << k + 1;
	}
	else
	{
		int count2=0;
		for (int i = 0; i < k; i++)
		{
			if (p[i] > 0)
			{
				count2++;
			}
		}

		cout << count2;
	}

	//system("pause");
	return 0;
}