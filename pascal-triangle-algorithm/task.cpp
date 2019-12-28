#include<iostream>
using namespace std;
int ** createPascalTriangle(int n);
void displayPascalTriangle(int **p, int n);
void deallocatePascalTriangle(int **p, int n);
int main()
{

	int n;
	cout << "enter number : ";
	cin >> n;

	int **p = createPascalTriangle(n);
	displayPascalTriangle(p, n);
	deallocatePascalTriangle(p,n);


	system("pause");
	return 0;
}


int ** createPascalTriangle(int n)
{
	int **p = new int *[n];
	for (int i = 0; i < n; i++)
	{
		p[i] = new int[n];
	}


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			p[i][j] = 0;
		}
	}

	p[0][0] = 1;

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			p[i][j] = p[i - 1][j];
			if (j - 1>= 0)
			{
				p[i][j] += p[i - 1][j - 1];
			}
		}
	}


	return p;
}



void displayPascalTriangle(int **p, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <=i; j++)
		{
			cout << p[i][j];
			cout << " ";
		}
		cout << endl;
	}
}



void deallocatePascalTriangle(int **p, int n)
{
	for (int i = 0; i < n; i++)
	{
		delete[]p[i];
	}

	delete[]p;
}