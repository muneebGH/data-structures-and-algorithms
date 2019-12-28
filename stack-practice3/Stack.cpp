#include"Stack.h"
template <typename T>
Stack<T>::Stack()
{
	array = nullptr;
	size = 0;
	sp = 0;
}


template<typename T>
Stack<T>::Stack(int s)
{
	size = s;
	array = new T [size];
	sp = 0;
}

template<typename T>
Stack<T>::Stack(Stack & ref)
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

template<typename T>
void Stack<T>::push(T element)
{
	
	
	if (sp < size)
	{
		array[sp] = element;
		sp++;
	}
	else
	{
		
		resize(size+1);
		array[sp] = element;
		sp++;
	}
}



template<typename T>
T Stack<T>::pop()
{
	sp--;
	return array[sp];
}

template<typename T>
void Stack<T>::resize(int newSize)
{
	Stack<T> temp(*this);
	this->~Stack();
	size = newSize;
	array = new T [size];
	int range = temp.size < newSize ? temp.size : newSize;
	sp = range - 1;
	for (int i = 0; i < range; i++)
	{
		array[i] = temp.array[i];
	}

}

template<typename T>
void Stack<T>::print()
{
	cout << "____" << endl;
	for (int i = 0; i < sp; i++)
	{
		cout << "| " << array[i] << " |" << endl;
	}
}


template<typename T>
Stack<T>::~Stack()
{
	if (array)
	{
		delete[] array;
		
	}
	array = nullptr;
}


template<typename T>
int Stack<T>::showSP()
{
	return sp;
}


