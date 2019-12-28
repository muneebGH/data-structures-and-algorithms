#include"Term.h"
class Polynomial
{
private:
	Term * TArray;
	int noOfElements;
public:
	Polynomial();
	Polynomial(int n);
	Polynomial(const Polynomial & ref);
	void insert(Term t);
	void sorting();
	void display();
	void operator=(const Polynomial ref);
	~Polynomial();
};