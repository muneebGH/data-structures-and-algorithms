#include<iostream>
using namespace std;

class MBList;


class MemoryBlock
{
	friend MBList;

private:
	int length;
	int adress;
	MemoryBlock * next;
	MemoryBlock * prev;
public:
	MemoryBlock(int l, int a, MemoryBlock * n=nullptr, MemoryBlock * p=nullptr)
	{
		length = l;
		adress = a;
		next = n;
		prev = p;
	}


};

class MBList
{
private:
	MemoryBlock * start;
	int listSize;
	int defaultLength;

public:
	MBList(int ls=100,int dl=4)
	{
		listSize = ls;
		defaultLength = dl;
		int tempAdress = 0;
		start = new MemoryBlock(defaultLength, tempAdress);

		MemoryBlock * temp = start;
		for (int i = 0; i < listSize-1; i++)
		{
			tempAdress += 4;
			temp->next= new MemoryBlock(defaultLength, tempAdress);
			temp->next->prev = temp;
			temp = temp->next;
		}
	}

	MemoryBlock * giveMe(int size)
	{
		MemoryBlock * temp = start;
		while (temp->length!=size)
		{
			if (size < temp->length)
			{
				int sAdress = temp->adress;
				int newAdress = sAdress + size;
				\
			}
			temp = temp->next;
			
		}


	}

	void deleteBlock(int adress)
	{
		MemoryBlock * temp = start;
		while (temp->adress!=adress)
		{
			temp = temp->next;
		}

		temp->prev->next = temp->next->next;
		temp->next->prev = temp->prev;
		delete temp;

	}

	void printList()
	{
		MemoryBlock * temp = start;
		for (int i = 0; i < listSize; i++)
		{
			cout << temp->adress << endl;
			temp = temp->next;
		}
	}
};