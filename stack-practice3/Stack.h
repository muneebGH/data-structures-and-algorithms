#include"CString.h"
template<typename T>
class Stack
{
private:
	T * array;
	int size;
	
public:
	int sp;
	Stack();
	Stack(int s);
	Stack(Stack & ref);
	void push(T element);
	T pop();
	void resize(int newSize);
	void print();
	int showSP();
	~Stack();
};