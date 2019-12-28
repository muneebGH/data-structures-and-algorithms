#include"ComplexNumber.h"
#include<iostream>
using namespace std;
void ComplexNumber::add()
{
	cout << "the sum is :" << a.real + b.real << " + " << a.img + b.img << "i" << endl;
}

void ComplexNumber::subtract()
{
	cout << "the subtraction is :" << a.real + b.real << " + " << a.img + b.img << "i" << endl;
}

void ComplexNumber::multiply()
{
	cout << "the multiplication is :";
	int n1 = a.real * b.real;
	int n2 = a.img * b.img;
	cout << n1 - n2 << " + ";
	n1 = a.img * b.real;
	n2 = a.real * b.img;
	cout << n1 + n2 << "i" << endl;
}

void ComplexNumber::divide()
{
	cout << "the division is : ";
	int n1 = a.real * b.real;
	int n2 = a.img * b.img;
	int n3 = (b.real * b.real) + (b.img * b.img);
	cout << (n1 + n2) / n3 << " + ";
	n1 = a.img * b.real;
	n2 = a.real * b.img;
	cout << (n1 - n2) / n3 << " i " << endl;

}

void ComplexNumber::setA()
{
	cout << "enter real for A";
	cin >> a.real;
	cout << endl;
	cout << " enter imaginary for a";
	cin >> a.img;
	cout << endl;

	
}

void ComplexNumber::setB()
{
	cout << "enter real for b";
	cin >> b.real;
	cout << endl;
	cout << " enter imaginary for b";
	cin >> b.img;
	cout << endl;

}