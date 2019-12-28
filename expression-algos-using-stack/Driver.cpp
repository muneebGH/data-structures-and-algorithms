#include<iostream>
#include"CString.h"
#include"Stack.h"
using namespace std;

#define paranthesisOpening 40
#define paranthesisClosing 41
#define sqBracketsOpening 91
#define sqBracketsClosing 93
#define bracesOpening 123
#define bracesClosing 125
#define plus 43
#define multiplication  42
#define minus 45
#define divide 47

bool isBalanced(CString exp);
CString infixToPostfix(CString exp);
bool PrecedenceOky(Stack<char> & ref, char ch);

int postfixEvaluator(CString postfix);



int main()
{
	int choice=0;
	back1:
	

	
	cout << "press 1 to convert an algabraic infix expression to postfix\n";
	cout << "press 2 to check if infix expression is balanced or not\n";
	cout << "press 3 to evaluate a postfix expression\n";
	cin >> choice;
	if (choice == 1)
	{
		cin.ignore();
		cout << "enter an expression without spaces\n";
		CString exp;
		exp.input();
		infixToPostfix(exp).display();
	}
	else if (choice == 2)
	{
		CString exp;

		cin.ignore();
		cout << "enter expression \n";
		exp.input();
		bool check = isBalanced(exp);
		check ? cout << "is balanced\n" : cout << "isnt balanced\n";

	}
	else if (choice == 3)
	{
		CString exp;

		cin.ignore();
		cout << "enter an expression(the spaces should only between operands : no where else\n";
		exp.input();
		cout << postfixEvaluator(exp);
	}
	else
	{
		cout << "wrong choice :\n";
		goto back1;
	}
	char ch;
	cout << "press y to go back again";
	cin >> ch;

	if (ch =='y')
	{
		goto back1;
	}
	system("pause"); 
	return 0;
}

bool isBalanced(CString exp)
{
	Stack<char> s(exp.getLength());


	int range = exp.getLength();
	for (int i = 0; i < range; i++)
	{
		char ch = exp.at(i);
		if (ch == paranthesisOpening || ch == sqBracketsOpening || ch == bracesOpening)
		{
			s.push(ch);
		}
		else if(ch==paranthesisClosing)
		{
		
			if (s.pop()!= paranthesisOpening)
			{
				return false;
			}
		}
		else if (ch == bracesClosing)
		{
			if (s.pop() != bracesOpening)
			{
				return false;
			}
		}
		else if (ch == sqBracketsClosing)
		{
			if (s.pop() != sqBracketsOpening)
			{
				return false;
			}
		}
		else
		{

		}


	}

	if (!s.isEmpty())
	{
		return false;
	}


	return true;
}



CString infixToPostfix(CString exp)
{
	if (!isBalanced(exp))
	{
		EXIT_FAILURE;
	}

	Stack<char> s(exp.getLength());
	exp.makeLower();
	CString postfix = exp;
	int postfixIndex = 0;
	int range = exp.getLength();
	bool bracketOccurence = false;
	for (int i = 0; i < range; i++)
	{
		if (exp.at(i) >= 97 && exp.at(i) <= 122)
		{
			if (postfixIndex!= 0)
			{
				if (postfix.at(postfixIndex - 1) != plus && postfix.at(postfixIndex - 1) != minus && postfix.at(postfixIndex - 1) != multiplication && postfix.at(postfixIndex - 1) != divide)
				{
					postfix.insert(postfixIndex, " ");
					postfixIndex++;
				}
			}
			postfix.at(postfixIndex) = exp.at(i);
			postfixIndex++;
		}
		else if ((exp.at(i) == plus || exp.at(i) == minus || exp.at(i) == multiplication || exp.at(i) == divide)&& (!bracketOccurence))
		{
			if (!s.isEmpty() && PrecedenceOky(s,exp.at(i)))
			{

				postfix.at(postfixIndex) = s.pop();
				postfixIndex++;
			}
			s.push(exp.at(i));
		}
		else if ((exp.at(i) == plus || exp.at(i) == minus || exp.at(i) == multiplication || exp.at(i) == divide) && (bracketOccurence))
		{
			s.push(exp.at(i));
		}
		else if (exp.at(i) == bracesOpening || exp.at(i) == sqBracketsOpening || exp.at(i) == paranthesisOpening)
		{
			s.push(exp.at(i));
			bracketOccurence = true;
		}
		else if (exp.at(i) == paranthesisClosing || exp.at(i) ==bracesClosing || exp.at(i) == sqBracketsClosing)
		{
			char symbol;
			bracketOccurence = false;
			if (exp.at(i) == paranthesisClosing)
			{
				symbol = paranthesisOpening;
			}
			else if (exp.at(i) == bracesClosing)
			{
				symbol = bracesOpening;
			}
			else
			{
				symbol = sqBracketsOpening;
			}

			char stackSymbol;
			stackSymbol = s.pop();
			while (stackSymbol != symbol)
			{
				postfix.at(postfixIndex) = stackSymbol;
				postfixIndex++;
				stackSymbol = s.pop();
			}
		}
		else
		{

		}
	}


	s.print();
	while (!s.isEmpty())
	{
		postfix.at(postfixIndex) = s.pop();
		postfixIndex++;
	}

	if (postfixIndex != range)
	{

		postfix[postfixIndex] = '\0';
	}
	return postfix;

}





bool PrecedenceOky(Stack<char> & ref, char ch)
{
	char stackElement = ref.pop();
	ref.push(stackElement);
	if ((ch == plus || ch == minus) && (stackElement == plus || stackElement == minus))
	{
		return true;
	}
	if ((ch == multiplication || ch == divide) && (stackElement == multiplication || stackElement == divide))
	{
		return true;
	}

	if ((ch == plus || ch == minus) && (stackElement == multiplication || stackElement == divide))
	{
		return true;
	}

	return false;
}




int postfixEvaluator(CString postfix)

{
	Stack<int> s;
	CString check(postfix);
	
	while (postfix.getLength() != 0)
	{
		char op;
		if (postfix.at(0) != plus && postfix.at(0) != minus && postfix.at(0) != multiplication && postfix.at(0) != divide)
		{


			CString exp(postfix.tokenize("+-*/"));
			int expLength = exp.getLength();
			op = check.at(exp.getLength());
			check.remove(0, expLength+1);

			while (exp.find(" ") != -1)
			{
				s.push(exp.tokenize(" ").toInteger());
			}
			s.push(exp.toInteger());
		}
		else
		{
			op = postfix.at(0);
			postfix.remove(0);
		}


		if (op ==plus)
		{
			s.push(s.pop() + s.pop());
		}
		else if (op == minus)
		{
			s.push(s.pop() - s.pop());
		}
		else if (op == multiplication)
		{
			s.push(s.pop()*s.pop());
		}
		else if(op==divide)
		{
			s.push(s.pop() / s.pop());
		}
		else
		{

		}
	}

	return s.pop();

}
