#include<iostream>
using namespace std;

template<typename T>
class Queue
{
private:
	T * data;
	int size;
	int back;
	int front;
	int noe;
public:	
	
	Queue(int s = 10)
	{
		size = s < 0 ? 0 : s;
		data = new T[size];
		back = 0;
		front = 0;
		noe = 0;
	}


	Queue(Queue<T> & ref)
	{
		if (this->data)
		{/*
			delete [] data;
			data = nullptr;*/
		}
		if (ref.size == 0)
		{
			return;
		}
		size = ref.size;
		data = new T[size];
		for (int i = ref.front; i < ref.back; i++)
		{
			data[i] = ref.data[i];
		}
		back = ref.back;
		front = ref.front;
		noe = ref.noe;

	}
	void enqueue(T element)
	{
		if (!isFull())
		{
			
			data[back++] = element;
			noe++;
			back = back == size ? 0 : back;
		}
		else
		{/*
			reSize(size + 10);
			data[back++] = element;*/
		}
	}


	T dequeue()
	{
		if (!isEmpty())
		{
			front = front == size ? 0 : front;
			noe--;
			return data[front++];
			
		}
	}



	bool isEmpty()
	{
		return noe == 0;
	}



	bool isFull()
	{/*
		if ((back == size && front == 0) || (back == front - 1))
		{
			return true;
		}

		return false;*/

		return noe == size;
	}
	
/*
	void reSize(int newSize)
	{
		T * temp = new T[newSize];
		int range = newSize < size ? newSize : size;
		for (int i = 0; i < range; i++)
		{
			T[i] = data[i];
		}
		delete[] data;
		data = new T[newSize];
		
		int counter = 0;
		int i = front;

		int end = back > front ? back : size;
		while (i < end && newSize >0)
		{
			data[i] = temp[i];
			i++;
			newSize--;
			counter++;
		}

		if (back < front)
		{
			int j = 0;
			while (j < back && newSize>0)
			{
				data[i] = temp[j];
				i++;
				j++;
				newSize--;
				counter++;
			}
		}

		back = counter;
		front = 0;
	}
*/


	void print()
	{
		int i = 0;
		int j = front;
		while (i < noe)
		{
			cout << data[j++] << " ";
			j = j == size ? 0 : j;
			i++;
		}
	}
};


















