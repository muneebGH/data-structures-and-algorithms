#include"Stack.h"
#include"CString.h"
using namespace std;
int main()
{
	CString a;
	cout << "enter a" << endl;
	a.input();
	cout << "enter b" << endl;
	CString b;
	b.input();
	Stack<int> s;
	int hasil = 0;
	if (a.at(0) == '-')
	{
		a.remove(0);
	}
	if (b.at(0) == '-')
	{
		b.remove(0);
	}
	int aCount = a.getLength() - 1;
	int bCount = b.getLength() - 1;
	int range = a.getLength() >= b.getLength() ? a.getLength() : b.getLength();
	for (int i = 0; i < range; i++)
	{
		int number;
		if (aCount >=0 && bCount >= 0)
		{
			int number = (a.at(aCount) - 48) + (b.at(bCount) - 48)+hasil;
	
			if (number >= 10)
			{
				s.push(number % 10);
				hasil = 1;
				aCount--;
				bCount--;
			}
			else
			{
				s.push(number);
				hasil = 0;
				aCount--;
				bCount--;
			}
		}
		else if (aCount >= 0 && bCount < 0)
		{
			s.push((a.at(aCount) - 48) + hasil);
			aCount--;
		}
		else
		{
			s.push((b.at(bCount) - 48) + hasil);
			bCount--;
		}
	}

	cout << "\nAns: ";
	while (!s.isEmpty())
	{
		cout << s.pop();
	}
	cout << " ";
	system("pause");
	return 0;
}