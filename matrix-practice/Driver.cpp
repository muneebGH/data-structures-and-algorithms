#include<iostream>
using namespace std;
int rows;
int cols;

bool minimumInCol(int ** mat, int col, int val);

bool minimunInRow(int ** mat, int row, int val);
int main()
{
	int ** mat;
	cout << "enter number of rows :";
	
	cin >> rows;
	cout << "enter number of columns: ";
	
	cin >> cols;
	mat = new int *[rows];

	for (int i = 0; i < rows; i++)
	{
		mat[i] = new int[cols];

	}


	cout << "enter matrix \n";
	for (int i= 0; i < rows; i++)
	{
		cout << "enter row no: " << i + 1 << ": ";
		for (int j = 0; j < cols; j++)
		{
			cin >> mat[i][j];
		}
		cout << endl;

	}


	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (minimunInRow(mat, i, mat[i][j]) && minimumInCol(mat, j, mat[i][j]))
			{
				cout << "i:" << i << " j:" << j << endl;
			}
		}
	}

	system("pause");
	return 0;
}


bool minimunInRow(int ** mat,int row,int val)
{
	for (int i = 0; i < cols; i++)
	{
		if (val > mat[row][i])
		{
			return false;
		}
	}

	return true;
}



bool minimumInCol(int ** mat,int col,int val)
{
	for (int i = 0; i < rows; i++)
	{
		if (val < mat[i][col])
		{
			return false;
		}
	}

	return true;
		
}