////#include<iostream>
////#include<vector>
////#include<sstream>
////#include<string>
////using namespace std;
////
////string KS(int weight[], int price[], int W, int n)
////{
////	int  count = pow(2, n), sum = 0, max = 0;
////	string Set_nd_profit = "", Temp = "";
////	vector<int>index, Set;
////	for (int i = 0; i < count; i++)
////	{
////		Temp.clear();
////		Set.clear();
////		index.clear();
////		sum = 0;
////		for (int j = 0; j < n; j++)
////		{
////			if ((i & (1 << j)) > 0)
////			{
////				sum = sum + weight[j];
////				Set.push_back(weight[j]);
////				index.push_back(j);
////			}
////		}
////		if (sum <= W)
////		{
////			int size = index.size(), s = 0;
////			for (int k = 0; k < size; k++)
////			{
////				s = s + price[index[k]];
////			}
////
////			if (max < s)
////			{
////				stringstream ss;
////				Set_nd_profit = "\nSet having minimum weight and maximum profit is { ";
////				for (int i = 0; i < Set.size(); i++)
////				{
////					ss << Set[i] << ',';
////				}
////				ss >> Temp;
////				Temp.erase(Temp.length() - 1);
////				Set_nd_profit = Set_nd_profit + Temp + " } and maxmimum profit is ";
////				max = s;
////				ss.clear();
////				Temp.clear();
////				ss << max;
////				ss >> Temp;
////				Set_nd_profit = Set_nd_profit + Temp + "Rs .\n";
////			}
////		}
////	}
////	if (max == 0)
////	{
////		Set_nd_profit = "\nYour bag is too small bro! It cannot contain anything.\n";
////	}
////	return Set_nd_profit;
////}
////
////
////int main()
////{
////	int w[9], p[9];
////	for (int i = 0; i < 9; i++)
////	{
////		cin >> w[i];
////	}
////	for (int i = 0; i < 9; i++)
////	{
////		cin >> p[i];
////	}
////	cout << KS(w, p, 15, 9);
////	system("pause");
////	return 0;
////}
//
//
//#include<iostream>
//#include<iomanip>
//using namespace std;
//
//int max(int a, int b);
//void sort(int * p, int noOfElements);
//void print(int ** p,int rows,int cols);
//void arrange(int * w, int * v, int number);
//bool isPresent(int * p,int number, int val);
//int colIndex(int ** p, int cols, int rowNo, int val);
//int main()
//{
//
//
//	int number;
//	int maxWeight;
//	cout << "enter number" << endl;
//	cin >> number;
//	int *v = new int[number];
//	int * w = new int[number];
//	cout << "enter values" << endl;
//	
//	
//	for (int i = 0; i < number; i++)
//	{
//		cin >> v[i];
//	}
//
//
//
//	cout << "enter weights" << endl;
//	for (int i = 0; i < number; i++)
//	{
//		cin >> w[i];
//	}
//
//
//
//	arrange(w, v, number);
//	
//
//	cout << "enter max weight" << endl;
//	cin >> maxWeight;
//
//
//	int rows = number;
//	int cols = maxWeight+1;
//	int ** matrix = new int *[rows];
//	
//	
//	for (int i = 0; i < rows; i++)
//	{
//		matrix[i] = new int[cols];
//	}
//
//	
//	for (int i = 0; i < rows; i++)
//	{
//		matrix[i][0] = 0;
//	}
//
//	
//	
//	
//	for (int i = 0; i < rows; i++)
//	{
//		for (int j = 1; j < cols; j++)
//		{
//			
//			if (j < w[i])
//			{
//				if (i - 1 < 0)
//				{
//					matrix[i][j] = matrix[i][j - 1];
//				}
//				else
//				{
//					matrix[i][j] = matrix[i - 1][j];
//				}
//			}
//			else
//			{
//				if (i - 1 < 0)
//				{
//					matrix[i][j] = v[i];
//				}
//				else
//				{
//					matrix[i][j] = max(v[i] + matrix[i - 1][j - w[i]], matrix[i - 1][j]);
//				}
//			
//			}
//
//
//		}
//	}
//
//	int i = number - 1;
//	int j = cols - 1;
//	int val = matrix[rows - 1][cols - 1];
//
//	cout << "\n\n";
//	print(matrix, rows, cols);
//	cout << "\n\n Max Profit : " << matrix[rows - 1][cols - 1] << "\n\n";
//
//	int totalWeight = 0;
//	int totalValue = 0;
//
//	cout << "\n\n Weight  :   Value " << endl;
//	while (val>0)
//	{
//		if (i == 0)
//		{
//			cout << setw(5) << w[i] <<"     "<< setw(5) << v[i] << endl;
//			totalWeight += w[i];
//			totalValue += v[i];
//			break;
//		}
//
//		if (matrix[i-1][j] == val)
//		{
//			i--;
//		}
//		else
//		{
//
//			cout << setw(5) << w[i] << "     " << setw(5) << v[i] << endl;
//			totalWeight += w[i];
//			totalValue += v[i];
//			val = val - v[i];
//			j = colIndex(matrix, cols, i - 1, val);
//			i--;
//		}
//
//	}
//	cout << "Total weight : " << totalWeight << endl;
//	cout << "Total value : " << totalValue << endl;
//	
//	
//
//
//
//	system("pause");
//
//	return 0;
//}
//
//
//int max(int a, int b)
//{
//	return a > b ? a : b;
//}
//
//
//void sort(int * p, int noOfElements)
//{
//
//	for (int i = 0; i < noOfElements - 1; i++)
//	{
//		int j = i;
//		int e1 = p[j];
//		int e2 = p[j + 1];
//		while (e1 > e2)
//		{
//			int temp =p[j];
//			p[j] = p[j + 1];
//			p[j + 1] = temp;
//			if (j > 0)
//			{
//				j--;
//
//				e1 =p[j];
//				e2 =p[j + 1];
//
//			}
//			else
//			{
//				break;
//			}
//		}
//	}
//}
//
//
//void print(int ** p,int rows,int cols)
//{
//
//	for (int i = 0; i < rows; i++)
//	{
//		for (int j = 0; j < cols; j++)
//		{
//			cout <<setw(4)<< p[i][j];
//		}
//		cout << endl;
//	}
//}
//
//
//void arrange(int * w, int * v, int number)
//{
//
//
//	int * tempW = new int[number];
//	for (int i = 0; i < number; i++)
//	{
//		tempW[i] = w[i];
//	}
//
//	int * tempV = new int[number];
//	for (int i = 0; i < number; i++)
//	{
//		tempV[i] = v[i];
//	}
//
//
//	sort(w, number);
//	
//
//	int * keeper = new int[number];
//	for (int i = 0; i < number; i++)
//	{
//		keeper[i] = -1;
//	}
//
//	int k = 0;
//	for (int i = 0; i < number; i++)
//	{
//
//
//		for (int j = 0; j < number; j++)
//		{
//			if (tempW[i] == w[j])
//			{
//				if (isPresent(keeper, number, j))
//				{
//
//				}
//				else
//				{
//
//					v[j] = tempV[i];
//					keeper[k] = j;
//					k++;
//					break;
//				}
//			}
//		}
//
//
//	}
//
//	cout << "weight and values after arrangment : " << endl;
//	for (int i = 0; i < number; i++)
//	{
//		cout <<setw(3)<< w[i] << "  | " <<setw(3)<< v[i] << endl;
//	}
//
//}
//
//
//bool isPresent(int * p, int number,int val)
//{
//	for (int i = 0; i < number; i++)
//	{
//		if (p[i] == val)
//		{
//			return true;
//		}
//	}
//
//	return false;
//}
//
//
//int colIndex(int ** p, int cols, int rowNo, int val)
//{
//	for (int i = 0; i < cols; i++)
//	{
//		if (p[rowNo][i] == val)
//		{
//			return i;
//		}
//	}
//	return -1;







#include<iostream>
#include<stack>
#include<string>

using namespace std;

struct location
{
	int x_index, y_index;

	location(int x = 0, int y = 0)
	{
		x_index = x, y_index = y;
	}

	bool isValidIndex()
	{
		if (x_index > -1 && x_index < 23 && y_index > -1 && y_index < 50)
			return true;

		return false;
	}
};



bool solveMaze(string mz[], location lc, bool &cont)
{
	if (cont)
	{
		if (mz[lc.x_index][lc.y_index] == 'E')
		{
			cont = false;
			return cont;
		}
		if (mz[lc.x_index][lc.y_index] != 'S')
		{
			mz[lc.x_index][lc.y_index] = '@';
		}

		location top = location(lc.x_index - 1, lc.y_index);
		location down = location(lc.x_index + 1, lc.y_index);
		location left = location(lc.x_index, lc.y_index - 1);
		location right = location(lc.x_index, lc.y_index + 1);

		if (down.isValidIndex() && (mz[down.x_index][down.y_index] == ' ' || mz[down.x_index][down.y_index] == 'E'))
			solveMaze(mz, down, cont);
		if (right.isValidIndex() && (mz[right.x_index][right.y_index] == ' ' || mz[right.x_index][right.y_index] == 'E'))
			solveMaze(mz, right, cont);
		if (left.isValidIndex() && (mz[left.x_index][left.y_index] == ' ' || mz[left.x_index][left.y_index] == 'E'))
			solveMaze(mz, left, cont);
		if (top.isValidIndex() && (mz[top.x_index][top.y_index] == ' ' || mz[top.x_index][top.y_index] == 'E'))
			solveMaze(mz, top, cont);
		/*
				if (cont && mz[lc.x_index][lc.y_index] == '@')
				{
					mz[lc.x_index][lc.y_index] = ' ';
				}
		*/
	}
	return cont;
}


int main()
{
	string maze[23] = 
	{
		"******************",
		"***                              *** ***",
		"*** ***** ***** *** **",
		"*** ***** *          * *      **",
		"        ***** *  ***  * ** ** **",
		"*** * *    * *  ***        ** **",
		"*** * ** * *  ******* **",
		"*** * ** *    ******* **",
		"*** * ** ********* ***",
		"*** * *                      **** **",
		"*     * * ** ** ******* **",
		"* *** * ** **                ** **",
		"* ***    ** ********* **",
		"* **** ** ********* **",
		"*            ** **** **** **",
		"***S*** **** **** **",
		"*** **** *****      *** **",
		"***     *** **** ** *** **",
		"*******              ** *** **",
		"************* *** **",
		"************* ****",
		"*************            E",
		"******************"
	};

	location var;
	for (int i = 0; i < 23; i++)
	{
		for (int j = 0; j < 50; j++)
		{
			if (maze[i][j] == 'S')
			{
				var = location(i, j);
			}
		}
	}
	bool moveOn = true;
	moveOn = solveMaze(maze, var, moveOn);

	cout << "Is there a solution:" << moveOn << endl;
	for (int i = 0; i < 23; i++)
	{
		cout << maze[i] << "\n";
	}

	return 0;
}
//}
//
