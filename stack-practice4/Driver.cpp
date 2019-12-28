#include<iostream>
#include"CString.h"
#include"Stack.h"
using namespace std;
int main()
{
	cout << "enter expression :";
		
		CString toCheck;
		
		toCheck.input();
		toCheck.makeLower();
		toCheck.trim();
		Stack<char> s1(toCheck.getLength());
		int range = toCheck.getLength();
		for (int i = 0; i < range; i++)
		{
			if (toCheck.at(i) >= 97 && toCheck.at(i) <= 122)
			{
				s1.push(toCheck.at(i));
			}
		}




		bool palindrome = true;
		Stack<char> temp = s1;


		Stack<char> s2;
		while (!temp.isEmpty())
		{
			s2.push(temp.pop());
		}


		while (!s1.isEmpty() && !s2.isEmpty())
		{
			if (s1.pop() != s2.pop())
			{
				palindrome = false;
			}
		}
		if (palindrome)
		{
			
			cout << "\n\nis palindrome\n Press Y to continue";
			
		}
		else
		{
			cout << "\n\n is not palindrome\n press Y to continue";
		}

	system("pause");
	return  0;
}