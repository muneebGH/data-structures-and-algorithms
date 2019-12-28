#include"Sparse.h"
using namespace std;
int main()
{


	int rows;
	int cols;
	cout << "enter number of rows\n";
	cin >> rows;
	cout << "enter number of cols\n";
	cin >> cols;
	if (rows < 0 || cols < 0)
	{
		exit(0);
	}

	Sparse<int> s(rows, cols);
	int val;
	for (int i = 0; i < rows; i++)
	{
		cout << "enter row no :" << i + 1 << "   ";
		for (int j = 0; j < cols; j++)
		{
			cin >> val;
			s.setElement(i, j, val);
		}
		cout << endl;
	}
	cout << "first Matrix\n";
	s.printMatrix();
	cout << "first transpose\n";
	s.transpose();
	int rows2;
	int cols2;
	cout << "enter number of rows\n";
	cin >> rows2;
	cout << "enter number of cols\n";
	cin >> cols2;
	if (rows2 < 0 && cols2 < 0)
	{
		exit(0);
	}

	Sparse<int> s2(rows2, cols2);
	
	for (int i = 0; i < rows2; i++)
	{
		cout << "enter row no :" << i + 1 << "   ";
		for (int j = 0; j < cols2; j++)
		{
			cin >> val;
			s2.setElement(i, j, val);
		}
		cout << endl;
	}
	cout << "2nd matrix\n";
	s2.printMatrix();
	cout << "2nd transpose\n";
	s2.transpose();
	cout << "sum";
	s+ s2;
	system("pause");
	return 0;

}