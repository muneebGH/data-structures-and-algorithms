#include<iostream>
#include<string>
using namespace std;
class Mint
{
private:
	string data;
public:
	Mint()
	{

	}


	Mint(const string & ref)
	{
		data = ref;
	}



	const void display()
	{
		cout << data;
	}

	
	void swap(Mint & ref)
	{
		string temp = ref.data;
		ref.data = data;
		data = temp;
	}



	const void display()
	{
		cout << data;
	}

	void swap()
	{


	}
	
};