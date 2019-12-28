
#include<iostream>
using namespace std;
template <typename T>
class Stack
{
private:
	T * data;
	int sp;
	int size;
public:


	Stack()
	{
		sp = 0;
		size = 100;
		data = new T[size];
	}



	Stack(int s)
	{
		if (s <= 0)
		{
			cout << "size isnt valid\n";
			abort();
		}
		size = s;
		data = new T[size];
		sp = 0;
	}


	Stack(Stack & ref)
	{
		if (this == ref || !ref.data)
		{
			return;
		}
		this->~Stack();
		size = ref.size;
		data = new T[size];
		sp = ref.sp;
		for (int i = 0; i < sp; i++)
		{
			data[i] = ref.data[i];
		}
		
	}

	void push(T element)
	{
		if (!isFull())
		{
			data[sp] = element;
			sp++;
		}
		else
		{
			cout << "stack is full\n";
			abort();
		}
	}



	T pop()
	{
		if (!isEmpty())
		{
			sp--;
			return data[sp];
		}
		else
		{
			cout << "stack is empty \n";
			abort();
		}
	}



	T & top()
	{
		if (!isEmpty())
		{
			return data[sp - 1];
		}
		else
		{
			cout << "stack is empty\n";
			abort();
		}

	}



	bool isEmpty()
	{
		return sp == 0 ?true:false;
	}



	bool isFull()
	{
		return sp == size ? true : false;
	}


	Stack & operator = (Stack & ref)
	{

		if (!(this->data == ref.data || !ref.data))
		{
			this->~Stack();
			size = ref.size;
			data = new T[size];
			sp = ref.sp;
			for (int i = 0; i < sp; i++)
			{
				data[i] = ref.data[i];
			}

		}
		

		return *this;
	}


	~Stack()
	{
		if (this->data)
		{
			delete[] data;
		}

	}


};

template <typename T>

class SpecialStack:public Stack<T>
{
private:
	Stack<T> min;
public:
	SpecialStack()
	{
		
	}

	SpecialStack(int s):min(s)
	{

	}

	SpecialStack(SpecialStack & ref):min(ref.min)
	{

	}

	void push(T element)
	{
		Stack<T>::push(element);
		if (min.isEmpty())
		{
			min.push(element);
		}
		else
		{
			int temp = min.pop();
			min.push(temp);
			if (element < temp)
			{
				min.push(element);
			}
			else
			{
				min.push(temp);
			}
		}
	}

	T pop()
	{
		min.pop();
		return Stack<T>::pop();
	}


	T getMin()
	{
		T toReturn;
		toReturn = min.pop();
		min.push(toReturn);
		return toReturn;

	}

	SpecialStack & operator = (SpecialStack & ref)
	{
		Stack<T>::operator=(ref);
		min = ref.min;
	}

	~SpecialStack()
	{
		min.~Stack();
		
	}
};
