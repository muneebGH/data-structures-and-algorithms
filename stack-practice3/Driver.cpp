#include<iostream>
#include"Stack.h"
using namespace std;
void runEquation();
int main()
{
	system("pause");
	return 0;
}


void runEquation()
{

	Stack<int> s(100);
	CString eq;
	eq.input();
	
	CString temp(eq);
	while (eq.getLength() != 1)
	{

		CString numbers = eq.tokenize("+=//*");
		
		char symbol = temp.at(numbers.getLength());
		while (numbers.getLength() != 0)
		{
			int element = 0;
			if (numbers.find(" ")!=-1)
			{
				element = numbers.left(numbers.find(" ")).toInteger();
				s.push(element);
				numbers.remove(0, numbers.find(" ") + 1);
			}
			else
			{
			
				s.push(numbers.toInteger());
				break;
			}

		}

		while (s.sp!=1)
		{
			if (symbol == '+')
			{
				s.push(s.pop() + s.pop());
			}
			else if (symbol == '-')
			{
				s.push(s.pop() - s.pop());
			}
			else if (symbol == '/')
			{
				s.push(s.pop() / s.pop());
			}
			else
			{
				s.push(s.pop() * s.pop());
			}
		}


	}


	s.print();
}


