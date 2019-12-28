#include"Polynomial.h"
#include<iostream>
using namespace std;
int main()
{
	Polynomial p(5);
	Term t[5];
	t[0].cof = 1;
	t[0].exp = 1;

	t[1].cof = 1;
	t[1].exp = 3;

	t[2].cof = 1;
	t[2].exp = 2;

	t[3].cof = 1;
	t[3].exp = 5;

	t[4].cof = 1;
	t[4].exp = 4;

	for (int i = 0; i < 5; i++)
	{
		p.insert(t[i]);
	}
	p.sorting();
	p.display();




	system("pause");
	return 0;
}