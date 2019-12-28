#include"Stack.h"
int main()
{


	SpecialStack<int> s;
	for (int i = 0; i < 10; i++)
	{
		s.push(i-10);
	}
	for (int i = 0; i < 5; i++)
	{
		cout << s.getMin();
		s.pop();
	}

	system("pause");
	return 0;
}