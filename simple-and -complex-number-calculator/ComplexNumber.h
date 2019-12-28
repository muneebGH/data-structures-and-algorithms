#include"calculator.h"
#include"ComplexNum.h"
class ComplexNumber :public calculator
{
private:
	ComplexNum a;
	ComplexNum b;
public:
	void add();
	void subtract();
	void multiply();
	void divide();
	void setA();
	void setB();
};