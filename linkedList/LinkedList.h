#include<iostream>
#include<string>
using namespace std;
template<typename T>
struct node
{
	T value;
	node<T> * next;
};

template<typename T>
class linkedList
{
private:
	node<T> * head;
	node<T> * tail;
	int non;
public:

	linkedList()
	{
		head = nullptr;
		tail = nullptr;
		non = 0;
	}


	linkedList(linkedList<T> & ref)
	{
		if (this->head)
		{
			this->~linkedList();
		}

		node<T> * temp = ref.head;
		while (temp != nullptr)
		{
			this->insertAtTail(temp->value);
			temp = temp->next;
		}
		non = ref.non;
	}

	void insertAtHead(T val)
	{
		node<T> * newNode = new node<T>;
		newNode->value = val;
		if (isEmpty())
		{
			newNode->next = nullptr;
			head = newNode;
			tail = newNode;
		}
		else
		{
			newNode->next = head;
			head = newNode;
		}
		non++;
	}


	void insertAtTail(T val)
	{
		node<T> * newNode = new node<T>;
		newNode->value = val;
		if (isEmpty())
		{
			newNode->next = nullptr;
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->next = newNode;
			newNode->next = nullptr;
			tail = newNode;
		}
		non++;
	}



	void insert(T val)
	{
		insertAtTail(val);
		
	}


	void insertBefore(T before, T val)
	{
		if (isEmpty())
		{
			return;
		}
		node<T> * newNode = new node<T>;
		newNode->value = val;
		node<T> * temp = head;
		while (temp->next->value != before)
		{
			temp = temp->next;
			if (temp->next == nullptr)
			{
				return;
			}
		}
		newNode->next = temp->next;
		temp->next = newNode;
		non++;
	}


	void insertAfter(T after, T val)
	{
		node<T> * target = search(after);
		if (target == nullptr)
		{
			return;
		}

		node<T> * newNode = new node<T>;
		newNode->value = val;
		newNode->next = target->next;
		if (!target->next)
		{
			tail = newNode;
		}
		target->next = newNode;
		non++;
	}


	T deleteBefore(T val)
	{
		if (isEmpty())
		{
			return  NULL;
		}
		T value;

		node<T> * temp = head;
		if (temp->next->value == val)
		{
			value = head->value;
			head = head->next;
			delete temp;
			non--;
			return value;

		}
		while (temp->next->next->value != val)
		{
			temp = temp->next;
			if (temp == nullptr)
			{
				return NULL;
			}
		}
		value = temp->next->value;
		node<T> * toDelete = temp->next;
		temp->next = temp->next->next;
		delete toDelete;
		non--;
		return value;


	}

	T deleteAfter(T val)
	{
		if (isEmpty() || tail->value == val)
		{
			return NULL;
		}

		node<T> * temp = head;
		while (temp->value != val)
		{
			temp = temp->next;
			if (temp == nullptr)
			{
				return NULL;
			}
		}
		T value;
		if (temp->next == tail)
		{
			value = tail->value;
			delete tail;
			temp->next = nullptr;
			non--;
			return value;
		}

		node<T> * toDelete = temp->next;
		value = toDelete->value;
		temp->next = temp->next->next;
		delete toDelete;
		non--;
		return value;

	}

	T deleteAtTail()
	{
		if (!isEmpty())
		{
			if (head == tail)
			{
				T value = head->value;
				head = tail = nullptr;
				non--;
				return value;
			}

			node<T> * temp = head;
			while (temp->next != tail)
			{
				temp = temp->next;
			}

			T value = tail->value;
			delete tail;
			temp->next = nullptr;
			tail = temp;
			non--;
			return value;

		}
		else
		{
			return NULL;
		}
	}



	void deleteNodeByValue(T val)
	{
		node<T>* temp = head;
		node<T> * temp2 = nullptr;
		while (temp != nullptr)
		{
			if (temp->value == val)
			{
				if (temp == head)
				{
					head = head->next;
					delete temp;
					non--;
					return;
				}
				else
				{
					temp2->next = temp->next;
					delete temp;
					non--;
					return;
				}
			}

			temp2 = temp;
			temp = temp->next;
		}
	}


	node<T> * search(T val)
	{
		node<T> * temp = head;
		while (temp != nullptr)
		{
			if (temp->value == val)
			{
				return temp;
			}
			temp = temp->next;
		}

		temp = nullptr;
		return temp;
	}


	bool isEmpty()
	{
		return head == nullptr;
	}


	void showList()
	{
		cout << "LIST START :\n";
		node<T> * ptr = head;
		while (ptr != nullptr)
		{
			cout << ptr->value << endl;
			ptr = ptr->next;
		}


		cout << "LIST END\n";


	}


	~linkedList()
	{
		node<T> * temp = head;
		while (temp != nullptr)
		{

			temp = temp->next;
			delete head;
			head = temp;
		}

	}




	//lab functions

	int getSize()
	{
		return non;
	}



	void remove(int pos)
	{
		if (pos<0 || pos>non-1)
		{
			cout << "invalid position\n";
			return;
		}

		node<T> * temp = head;
		if (pos == 0)
		{
			temp = head->next;
			delete head;
			head = temp;
			non--;
			return;

		}

		for (int i = 0; i < pos - 1; i++)
		{
			temp = temp->next;
		}

		node<T> * toDelete = temp->next;
		if (temp->next->next)
		{

			temp->next = temp->next->next;
		}
		else
		{

			temp->next = nullptr;
		}
		if (pos == non - 1)
		{
			tail = temp;
		}
		delete toDelete;
		non--;
	}


	void sortedInsert(node<T> * n)
	{

		T val = n->value;
		node<T> * temp = head;
		while (val > temp->value)
		{
			temp = temp->next;

			if (temp == nullptr)
			{
				insertAtTail(n->value);
				non++;
				return;
			}
		}

		insertBefore(temp->value, n->value);
		non++;
		return;

	}


	void sort()
	{

		linkedList<T> sorted;
		int initialNon = non;
		for (int i = 0; i < initialNon; i++)
		{
			node<T> * temp = head;
			T min=temp->value;
			for (int j = 0; j < non-1; j++)
			{
				if (temp->next->value <min)
				{
					min = temp->next->value;
				}
				temp = temp->next;
			}

			deleteNodeByValue(min);
			sorted.insert(min);
		}

		*this = sorted;
		
	}

	
	linkedList & operator=(linkedList<T> & ref)
	{

		if (this->head)
		{
			this->~linkedList();
		}

		node<T> * temp = ref.head;
		while (temp != nullptr)
		{
			this->insertAtTail(temp->value);
			temp = temp->next;
		}
		non = ref.non;
		return *this;
	}


	void frontBackSplit(linkedList<T> & l, linkedList<T> & frontRef, linkedList<T> & backRef)
	{
		int size = l.getSize();
		if (size < 2)
		{
			cout << "size is less than 2 : cannot be splited\n";
			
			return;
		}
		int fSize = size / 2;
		int bSize = size / 2;
		if (size % 2 != 0)
		{
			fSize++;
		}

		node<T> * temp = head;
		for (int i = 0; i < fSize; i++)
		{
			frontRef.insert(temp->value);
			temp = temp->next;
		}
		for (int i = 0; i < bSize; i++)
		{
			backRef.insert(temp->value);
			temp = temp->next;
		}
	}



	void alternatingSplit(linkedList<T> & l, linkedList<T> & head1, linkedList<T> & head2)
	{
		int size = l.getSize();
		if (size < 2)
		{
			cout << "size is less than 2 : cannot be splited\n";

			return;
		}
		node<T> * temp = head;
		for (int i = 0; i < size; i++)
		{
			if (i == 0 || i % 2 == 0)
			{

				head1.insert(temp->value);
			}
			else
			{
				head2.insert(temp->value);
			}
			temp = temp->next;

		}
	}


	bool delBinarySequence(string ref)
	{
		node<T> * temp = head;
		int length = ref.length();
		int i = 0;
		while (temp != nullptr && i<length)
		{

			if (ref.at(i) == '1')
			{
				T val = temp->value;

				temp = temp->next;
				this->deleteNodeByValue(val);
			}
			else
			{

				temp = temp->next;
			}

			i++;
		}

		return true;
	}
};