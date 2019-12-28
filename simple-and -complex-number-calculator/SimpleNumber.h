#include"calculator.h"

class SimpleNumber:public calculator
{
private:
	int a;
	int b;
public:
	void add();
	void subtract();
	void divide();
	void multiply();
	void setA();
	void setB();
};