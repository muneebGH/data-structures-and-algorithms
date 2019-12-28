#include<iostream>
using namespace std;
#include"SimpleNumber.h"


void SimpleNumber::add()
{
	cout << "the sum is :";
	cout << a + b;
	cout << endl;
}


void SimpleNumber::subtract()
{
	cout << "the subtraction is :" << a - b << endl;
}


void SimpleNumber::divide()
{
	if (a%b == 0)
	{
		cout << "the division is :" << a / b << endl;
	}
	else
	{
		cout << " cannot be divided" << endl;

	}
	
}

void SimpleNumber::multiply()
{
	cout << "the multiplication is :" << a * b << endl;
}

void SimpleNumber::setA()
{
	cout << " enter A :";
	cin >> a;
	cout <<endl;
}
void SimpleNumber::setB()
{
	cout << " enter B :";
	cin >> b;
	cout << endl;
}