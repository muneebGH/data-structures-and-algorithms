#include<iostream>
using namespace std;
template<typename T>
class Stack
{
private:
	T * array;
	int size;
	int sp;
public:
	
	Stack()
	{

		array = nullptr;
		size = 0;
		sp = 0;
	}


	Stack(int s)
	{

		size = s;
		array = new T[size];
		sp = 0;
	}


	Stack(Stack & ref)
	{

		if (this->array)
		{
			this->~Stack();
		}
		size = ref.size;
		sp = 0;
		array = new T[size];
		for (int i = 0; i < size; i++)
		{
			array[i] = ref.array[i];
		}

	}


	void push(T element)
	{

		if (sp < size)
		{
			array[sp] = element;
			sp++;
		}
		else
		{

			resize(size + 1);
			array[sp] = element;
			sp++;
		}
	}


	T pop()
	{

		sp--;
		return array[sp];
	}



	void resize(int newSize)
	{
		Stack<T> temp(*this);
		
		this->~Stack();
		array= new T [newSize];
		int range = 0;
		if (size > newSize)
		{
			range = newSize;
			sp = newSize - 1;
		}
		else
		{
			range = size;
		}
		
		for (int i = 0; i <range; i++)
		{
			this->array[i] = temp.array[i];
		}

		size = newSize;
	}

	

	void print()
	{

		cout << "____" << endl;
		for (int i = 0; i < sp; i++)
		{
			cout << "| " << array[i] << " |" << endl;
		}
	}



	int showSP()
	{
		return sp;
	}


	
	bool isEmpty()
	{
		return sp == 0;
	}


	bool isFull()
	{
		return sp == size;
	}


	~Stack()
	{

		if (array)
		{
			delete[] array;

		}
		array = nullptr;
	}
};