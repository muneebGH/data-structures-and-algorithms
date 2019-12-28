#include<iostream>
#include<string>
using namespace std;

void task1(int num);

bool task2(int num);
bool task2p2(int num, int num1, int temp);

bool task3(int num);
bool task3p2(int num, int val);

void task4(int num);

int task6(int a, int b);

int task7(string ref);
int task7pb(string ref, int i);

int task8(int n);
int task8pb(int num, int n, int helper);

bool task5(string s, string subString);
bool task5p2(string s, string subString, bool started, int sIndex, int subSIndex);

int task9(int n, int count = 0);

void task10(char * str, char from, char to);
void task10pb(char * str, char from, char to, int i);

int main()
{
	back:
	int choice;
	cout << "enter task no to test\n";
	cin >> choice;
	if (choice == 1)
	{
		cout << "enter number\n";
		int num;
		cin >> num;
		task1(num);

	}
	else if (choice == 2)
	{
		cout << "enter number\n";
		int num;
		cin >> num;
		if (task2(num))
		{
			cout << "is palindrome";
		}
		else
		{
			cout << "isnt palindrome\n";
		}
	}
	else if (choice == 3)
	{

		cout << "enter number\n";
		int num;
		cin >> num;
		if (task3(num))
		{
			cout << "is prime";

		}
		else
		{
			cout << "isnt prime\n";
		}
	}
	else if (choice == 4)
	{

		cout << "enter number\n";
		int num;
		cin >> num;
		if (num < 0)
		{
			cout << "inalid no";
		}
		else if (num == 0)
		{
			cout << "0";
		}
		else
		{

			task4(num);
		}

	}
	else if (choice == 5)
	{
		string s, sub;
		cin.ignore();
		cout << "enter string";
		getline(cin, s);
		cout << "enter substring";
		getline(cin, sub);
		if (task5(s, sub))
		{
			cout << "yes";
		}
		else
		{
			cout << "no";
		}
	}
	else if (choice == 6)
	{
		cout << "enter number 1";
		int a;
		cin >> a;
		int b;
		cout << "enter number 2";
		cin >> b;
		if (a == 0 || b == 0)
		{
			cout << "0";

		}
		else
		{

			cout << task6(a, b);
		}
	}
	else if (choice == 7)
	{
		cin.ignore();
		string s;
		cout << "enter string\n";
		getline(cin, s);
		cout<<task7(s);
	}
	else if (choice == 8)
	{
		int num;
		cout << "enter term number\n";
		cin >> num;
		if (num < 1)
		{
			cout << "invalid term";
		}
		else
		{

			cout << task8(num);
		}
	}
	else if (choice == 9)
	{
		int num;
		cout << "enter number\n";	
		cin >> num;
		if (num < 0)
		{
			cout << "invalid input";
		}
		else
		{

			cout << task9(num);
		}

	}
	else if (choice == 10)
	{
		char arr[100];
		char from;
		char to;
		cin.ignore();
		cout << "enter char array" << endl;
		cin.getline(arr, 100);
		cout << "enter from";
		cin >> from;
		cout << "enter 2";
		cin >> to;
		task10(arr, from, to);
		cout << arr;
	}
	else
	{

	}
	cout << endl;
	goto back;
	system("pause");
	return 0;
}



void task1(int num)
{
	if (num == 0)
	{
		return;
	}
	task1(num / 10);

	cout << num % 10 << endl;
}




bool task3(int num)
{

	return task3p2(num, 2);
}


bool task3p2(int num, int val)
{
	if (num<= 1)
	{
		cout << "invalid";
		abort();
	}
	if (val == 9)
	{
		if (num%val == 0 && num!=val)
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	if (task3p2(num, val + 1))
	{

		if (num%val == 0 && num != val)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	else
	{
		return false;
	}
}


void task4(int num)
{
	if (num < 2)
	{
		cout << "1";
		return;
	}

	task4(num / 2);
	cout << num % 2;
}


int task6(int a, int b)
{
	if (a > b)
	{
		int temp = a;
		a = b;
		b = temp;
	}
	if (b%a == 0)
	{
		return a;
	}
	int a2= a;
	a = b % a;
	b = b - (b%a2);
	return task6(a, b);
	
}



int task7(string ref)
{
	return task7pb(ref,0);

}

int task7pb(string ref, int i)

{
	if (ref[i] == '\0')
	{
		return i;
	}

	return task7pb(ref, i + 1);
}



int task8(int n)
{
	return task8pb(0, n, 1);
}


int task8pb(int num,int n,int helper)
{
	if (n == 1)
	{
		return num;
	}

	return task8pb(num + helper, n - 1, helper + 1);
}



void task10(char * str,char from,char to)
{
	task10pb(str, from, to, 0);
}


void task10pb(char * str, char from, char to, int i)
{
	if (str[i] == '\0')
	{
		return;
	}

	if (str[i] == from)
	{
		str[i] = to;
	}
	task10pb(str, from, to, i + 1);
}


bool task5(string s, string subString)
{
	return task5p2(s, subString, false, 0, 0);
}

bool task5p2(string s,string subString,bool started,int sIndex,int subSIndex)
{
	if(s[sIndex]=='\0' && subSIndex!=subString.length())
	{ 
		return false;
	}
	else if (subSIndex == subString.length())
	{
		return true;
	}

	if (s[sIndex] != subString[subSIndex])
	{
		started = false;
		subSIndex = 0;
	}
	else if (s[sIndex] == subString[subSIndex])
	{
		started = true;
		subSIndex=subSIndex + 1;
	}

	return task5p2(s, subString, started, sIndex + 1, subSIndex);

}

bool task2(int num)
{
	return task2p2(num, 0, num);
}

bool task2p2(int num, int take, int num2)
{
	int temp;
	if (num == 0)
	{
		if (num2 == take)
		{
			return true;
		}
		else
		{
			return false;
		}
		
	}
	temp = num % 10;
	num = num / 10;
	take= take * 10 +temp;
	return task2p2(num,take,num2);
}


int task9(int n,int count)
{
	if (n == 0)
	{
		return 0;
	}
	int temp = 0;
	if ((n % 10) % 2 == 0)
	{
		temp = (n % 10)*(int)pow(10, count);
		count = count + 1;
	}
	return temp+task9(n / 10, count);
}
