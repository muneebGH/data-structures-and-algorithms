#include<iostream>
using namespace std;
template<class T>
class DList;

template<class T>
class DNode
{
	friend DList<T>;

	T data;
	DNode<T> * next;
	DNode<T> * prev;
public:
	DNode(T val,DNode<T> * n=nullptr,DNode<T> * p=nullptr)
	{
		data = val;
		next = n;
		prev = p;
	}

	void printNode()
	{
		cout << data<<endl;
	}

	DNode<T> & operator = (DNode<T> & ref)
	{
		data = ref.data;
		prev = ref.prev;
		next = ref.next;
		return *this;
	}

};

template<class T>
class DList
{
private:
	DNode<T> * head;
public:
	DList()
	{
		head = nullptr;
	}

	DList(T val)
	{
		head = new DNode<T> (val);
	}

	DList(DList<T> & ref)
	{
		/*
		DNode < T> * temp = ref.head;
		while (temp != nullptr)
		{
			insertAtTail(temp->data);
			temp = temp->next;
		}*/
	}

	void insertAtHead(T val)
	{

		DNode<T> * temp = new DNode<T>(val);
		if (temp == nullptr)
		{
			head = new DNode<T>(val);
			return;
		}
		else
		{

			temp->next = head;
			head->prev = temp;
			head = temp;
		}

	}

	void insertAtTail(T val)
	{
		if (head == nullptr)
		{
			insertAtHead(val);
			return;
		}

		DNode<T> * temp = new DNode<T>(val);


		DNode<T> * checker = head;
		while (checker->next!=nullptr)
		{
			checker = checker->next;
		}
		checker->next = temp;
		temp->prev = checker;
	}


	bool deleteAtHead()
	{
		DNode<T> * toDelete = head;
		head = head->next;
		head->prev = nullptr;
		delete toDelete;
		return true;
	}

	bool deleteAtTail()
	{
		DNode<T> * checker = head;
		while (checker->next!=nullptr)
		{
			checker = checker->next;
		}
		DNode<T> * toDelete = checker;
		checker->prev->next = nullptr;
		delete toDelete;
		return true;

	}

	void print()
	{
		DNode<T> * iterator = head;
		while (iterator != nullptr)
		{
			cout << iterator->data << endl;
			iterator = iterator->next;
		}
	}

	DNode<T> * getNode(int n)
	{
		n--;
		DNode<T> * checker = head;
		while (checker->next!=nullptr && n)
		{
			checker = checker->next;
			n--;
		}

		return checker;
	}

	DNode<T> * search(T key)
	{
		DNode<T> * checker = head;
		while(checker!=nullptr)
		{
			if (checker->data == key)
			{
				return checker;
			}
			checker = checker->next;
		}

		return nullptr;
	}

	bool insertAfter(T key,T val)
	{
		DNode<T> * target = search(key);
		if (target == nullptr)
		{
			return false;
		}
		DNode<T> * temp = new DNode<T>(val);
		temp->next = target->next;
		temp->prev = target;
		target->next = temp;
		temp->next->prev = temp;
		return true;

	}
	
	bool deleteAfter(T key)
	{
		DNode<T> * target = search(key);
		if (target == nullptr)
		{
			return false;
		}

		DNode<T> * toDelete = target->next;
		target->next = target->next->next;
		target->next->prev = target;
		delete toDelete;
		return true;
	}


	int getLength()
	{
		int length = 0;
		DNode<T> * checker = head;
		while(checker!=nullptr)
		{
			checker = checker->next;
			length++;
		}

		return length;
	}


	~DList()
	{
		DNode<T> * temp= head;
		while (head!=nullptr)
		{
			temp = head;
			head = head->next;
			delete temp;
		}

	}
};