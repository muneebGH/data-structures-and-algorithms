#include<iostream>
using namespace std;
int main()
{

	int size;
	cout << "enter size";
	cin >> size;
	int diagonals;
	cout << "enter diagonals";
	cin >> diagonals;
	cout <<"no of elements"<< (diagonals * 2) + ((size - 2)*(diagonals + 1))<<"\n";

	bool in;
	int i;
	int j;
	cout << "enter i:";
	cin >> i;
	cout << "enter j";
	cin >> j;
	if (i != size - 1)
	{
		if (i == 0 && j <= diagonals - 1)
		{
			in = true;
		}
		else if (i != 0 && j <= diagonals)
		{
			in = true;
		}
		else
		{
			in = false;
		}
	}
	else
	{
		if (j > (size - diagonals - 1))
		{
			in = true;
		}
		else
		{
			in = false;
		}
	}


	if (in)
	{
		if (j < i)
		{
			cout << "below band\n";
		}
		else if (j > i)
		{
			cout << "above band\n";
		}
		else
		{
			cout << "in band\n";
		}
	}
	else
	{
		cout << "isnt in band\n";
	}

	int totalBands = (diagonals * 2) - 1;


	system("pause");
	return 0;
}

