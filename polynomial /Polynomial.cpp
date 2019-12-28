#include"Polynomial.h"
#include<iostream>
using namespace std;
Polynomial::Polynomial()
{
	TArray = nullptr;
	noOfElements = 0;
}

Polynomial::Polynomial(int n)
{
	noOfElements = 0;
	TArray = new Term[n];
}

Polynomial::Polynomial(const Polynomial & ref)
{
	noOfElements = ref.noOfElements;
	TArray = new Term[noOfElements];
	for (int i = 0; i < noOfElements; i++)
	{
		TArray[i] = ref.TArray[i];
	}

}

void Polynomial::insert(Term t)
{
	TArray[noOfElements] = t;
	noOfElements += 1;
}

void Polynomial::display()
{
	for (int i = 0; i < noOfElements; i++)
	{
		Term t = TArray[i];
		cout << t.cof << "^" << t.exp << " ";
	}
}

void Polynomial::operator=(const Polynomial ref)
{
	this->~Polynomial();

	noOfElements = ref.noOfElements;
	TArray = new Term[noOfElements];
	for (int i = 0; i < noOfElements; i++)
	{
		TArray[i] = ref.TArray[i];
	}
	
}

Polynomial::~Polynomial()
{
	delete[] TArray;
	TArray = NULL;
}


void Polynomial::sorting()
{
	for (int i = 0; i < noOfElements-1; i++)
	{
		int j = i;
		Term T1 = TArray[j];
		Term T2 = TArray[j + 1];
		while (T1.exp>T2.exp)
		{
			Term temp = TArray[j];
			TArray[j] = TArray[j + 1];
			TArray[j + 1] = temp;
			if (j > 0)
			{
				j--;

				 T1 = TArray[j];
				 T2 = TArray[j + 1];

			}
			else
			{
				break;
			}
		}
	}
}