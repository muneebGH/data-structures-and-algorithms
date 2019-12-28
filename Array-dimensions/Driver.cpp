#include<iostream>
using namespace std;


void printND(int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "i" << i + 1;
		for (int j = i + 1; j < n; j++)
		{
			cout << "D" << j + 1;
		}
		if (i != n - 1)
		{
			cout << "+";
		}
	}
}
int main()
{

	int dimension;
	cout << "eneter dimension: ";
	cin >> dimension;
	if (dimension == 0)
	{
		exit(0);
	}

	printND(dimension);


	system("pause");
	return 0;

}


