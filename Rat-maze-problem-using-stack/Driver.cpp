#include"Stack.h"
#include"CString.h"
#include<string>
#include<iostream>
#include<fstream>
using namespace std;
bool leftAvailable(char ** p, int i, int j);

bool rightAvailable(char ** p, int i, int j);


bool downAvailable(char ** p, int i, int j);


bool upAvailable(char ** p, int i, int j);


int availablePositions(char ** p, int i, int j);


int availableZeroPositions(char ** p, int i, int j);








// be careful with file input . dont forget to add end space after the end of each row in file .









struct pos
{
	int x;
	int y;
	bool operator ==(const pos & ref)
	{
		if (ref.x == x && ref.y == y)
		{
			return true;
		}
		return false;
	}

	pos & operator = (const pos & ref)
	{
		x = ref.x;
		y = ref.y;
		return *this;
	}

	bool operator !=(const pos & ref)
	{
		return x != ref.x || y != ref.y;

	}


};

int matrixSize;

int main()
{
	fstream file;
	file.open("data.txt", ios::in);
	

	file >> matrixSize;

	pos start;
	
	file>> start.x;
	file>> start.y;
	pos end;
	
	file >> end.x;
	file >> end.y;
	
	char** matrix = new char *[matrixSize];
	for (int i = 0; i < matrixSize; i++)
	{
		matrix[i] = new char[matrixSize];
	}
	string input;
	getline(file, input, '\n');
	for (int i = 0; i < matrixSize; i++)
	{

		for (int j = 0; j < matrixSize; j++)
		{
			
			getline(file, input, ' ');
			
			matrix[i][j] = input.at(0);

		}
		getline(file, input, '\n');
	}






	Stack<pos> path(matrixSize * matrixSize);

	path.push(start);
	pos currentPos = start;

	bool upAllowed = true;
	bool downAllowed = true;
	bool rightAllowed = true;
	bool leftAllowed = true;


	while (currentPos != end)
	{
		int positions = availablePositions(matrix, currentPos.x, currentPos.y);
		if (positions == 1 && currentPos!=start)
		{
			pos lastPose = currentPos;
			while (availablePositions(matrix, currentPos.x, currentPos.y) != 3)
			{
				matrix[currentPos.x][currentPos.y] = '0';
				lastPose = currentPos;
				currentPos = path.pop();
				
			}
			if (lastPose.y < currentPos.y)
			{
				leftAllowed = false;
				rightAllowed = true;
				upAllowed = true;
				downAllowed = true;
			}
			else if (lastPose.y > currentPos.y)
			{
				rightAllowed = false;
				leftAllowed = true;
				downAllowed = true;
				upAllowed = true;
			}
			else if (lastPose.x > currentPos.x)
			{
				downAllowed = false;
				upAllowed = true;
				leftAllowed = true;
				rightAllowed = true;
			}
			else if (lastPose.x < currentPos.x)
			{
				upAllowed = false;
				downAllowed = true;
				rightAllowed = true;
				leftAllowed = true;
			}
			else
			{

			}
		

		}
		else
		{
			if ((rightAvailable(matrix, currentPos.x, currentPos.y)) && (rightAllowed) && (matrix[currentPos.x][currentPos.y + 1] != 'f') && (matrix[currentPos.x][currentPos.y+1]!='*'))
			{
				matrix[currentPos.x][currentPos.y] = '*';
				currentPos.y = currentPos.y + 1;
				path.push(currentPos);
				leftAllowed = false;
				rightAllowed = true;
				downAllowed = true;
				upAllowed = true;
			}
			else if ((downAvailable(matrix, currentPos.x, currentPos.y)) && (downAllowed) && (matrix[currentPos.x + 1][currentPos.y] != 'f') &&  (matrix[currentPos.x+1][currentPos.y] != '*'))
			{

				matrix[currentPos.x][currentPos.y] = '*';
				currentPos.x = currentPos.x + 1;
				path.push(currentPos);
				leftAllowed = true;
				rightAllowed = true;
				downAllowed = true;
				upAllowed = false;
			}
			else if ((leftAvailable(matrix, currentPos.x, currentPos.y)) &&( leftAllowed) && (matrix[currentPos.x][currentPos.y - 1] != 'f') && (matrix[currentPos.x][currentPos.y - 1] != '*'))
			{

				matrix[currentPos.x][currentPos.y] = '*';
				currentPos.y = currentPos.y - 1;
				path.push(currentPos);
				leftAllowed = true;
				rightAllowed = false;
				downAllowed = true;
				upAllowed = true;
			}
			else if ((upAvailable(matrix, currentPos.x, currentPos.y)) && (upAllowed)&& (matrix[currentPos.x - 1][currentPos.y] != 'f') && (matrix[currentPos.x-1][currentPos.y] != '*'))
			{

				matrix[currentPos.x][currentPos.y] = '*';
				currentPos.x = currentPos.x - 1;
				path.push(currentPos);
				leftAllowed = true;
				rightAllowed = true;
				downAllowed = false;
				upAllowed = true;
			}
			else
			{
				
				while (!availableZeroPositions(matrix, currentPos.x, currentPos.y)>0)
				{
					currentPos = path.pop();
					matrix[currentPos.x][currentPos.y] = 'f';
				}
			}

			
		}


	}


	for (int i = 0; i < matrixSize; i++)
	{
		for (int j = 0; j < matrixSize; j++)
		{
			if (matrix[i][j] == 'f')
			{
				matrix[i][j] = '0';
			}
		}
	}
	

	fstream output;
	output.open("output.txt", ios::out);
	output << matrixSize;
	output << endl;
	output << start.x;
	output << " ";
	output << start.y;
	output << endl;
	output << end.x;
	output << " ";
	output << end.y;
	output << endl;


	while (!path.isEmpty())
	{
		pos temp = path.pop();
		output << "(" << temp.x << "," << temp.y << ") ";
		matrix[temp.x][temp.y] = '*' ;
	}
	output << endl;

	for (int i = 0; i < matrixSize; i++)
	{
		for (int j = 0; j < matrixSize; j++)
		{
			output << matrix[i][j] << " ";
		}
		output << endl;
	}
	file.close();
	output.close();





	system("pause");
	return 0;
}



bool upAvailable(char **p, int i, int j)
{
	if (i - 1 >= 0 && (p[i - 1][j] == '0' || p[i - 1][j] == '*'))
	{
		return true;
	}
	return false;
};


bool downAvailable(char ** p, int i, int j)
{
	if (i + 1 < matrixSize && (p[i + 1][j] == '0' || p[i + 1][j] == '*'))
	{
		return true;
	}

	return false;
}


bool rightAvailable(char ** p, int i, int j)
{
	if (j + 1 < matrixSize && (p[i][j + 1] == '0' || p[i][j + 1] == '*'))
	{
		return true;
	}
	return false;
}


bool leftAvailable(char ** p, int i, int j)
{
	if (j - 1 >= 0 && (p[i][j - 1] == '0' || p[i][j - 1] == '*'))
	{
		return true;
	}

	return false;
}







int availablePositions(char ** p, int i, int j)
{
	int count = 0;
	if (i - 1 >= 0)
	{
		if (p[i - 1][j] == '0' || p[i - 1][j] == '*')
		{
			count++;
		}
	}

	if (i + 1 < matrixSize)
	{
		if (p[i + 1][j] == '0' || p[i + 1][j] == '*')
		{
			count++;
		}
	}

	if (j - 1 >= 0)
	{
		if (p[i][j - 1] == '0' || p[i][j - 1] == '*')
		{
			count++;
		}

	}

	if (j + 1 < matrixSize)
	{
		if (p[i][j + 1] == '0' || p[i][j + 1] == '*')
		{
			count++;
		}
	}


	return count;
}





int availableZeroPositions(char ** p, int i, int j)
{
	int count = 0;
	if (i - 1 >= 0)
	{
		if (p[i - 1][j] == '0')
		{
			count++;
		}
	}

	if (i + 1 < matrixSize)
	{
		if (p[i + 1][j] == '0' )
		{
			count++;
		}
	}

	if (j - 1 >= 0)
	{
		if (p[i][j - 1] == '0')
		{
			count++;
		}

	}

	if (j + 1 < matrixSize)
	{
		if (p[i][j + 1] == '0')
		{
			count++;
		}
	}


	return count;
}