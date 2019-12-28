#ifndef CALCULATOR_H	
#define CALCULATOR_H


class calculator
{
public:
	virtual void add() = 0;
	virtual void subtract() = 0;
	virtual void multiply() = 0;
	virtual void divide() = 0;
	virtual void setA() = 0;
	virtual void setB() = 0;

};

#endif