#include"LinkedList.h"
using namespace std;
int main()
{

	linkedList<int> l;
	l.insert(1);
	l.showList();
	//bool again = false;
	//do
	//{
	//	linkedList<int> mainL;
	//	int count;
	//	cout << "enter no of elements u want to enter :";
	//	cin >> count;
	//	int num;
	//	for (int i = 0; i < count; i++)
	//	{
	//		cout << "enter element no " << i + 1 << " :";
	//		cin >> num;
	//		mainL.insert(num);
	//	}

	//	int choice;
	//	do
	//	{
	//		cout << "choose the function u want to perform\n";
	//		cout << "1: Sorted insert\n";
	//		cout << "2: remove by pos\n";
	//		cout << "3: Sort List\n";
	//		cout << "4: front back split\n";
	//		cout << "5: Alternating splits\n";
	//		cout << "6: del binary sequence\n";
	//		cin >> choice;
	//	}
	//	while (choice<1 || choice>6);
	//	
	//	if (choice == 1)
	//	{
	//		cout << "before :\n";
	//		mainL.showList();
	//		node<int> newNode;
	//		cout << "enter number :";
	//		cin >> num; newNode.value=num;
	//		mainL.sortedInsert(&newNode);
	//		cout << "after :\n";
	//		mainL.showList();
	//	}
	//	else if (choice == 2)
	//	{
	//		cout << "before :\n";
	//		mainL.showList();
	//		cout << "enter position";
	//		cin >> num;
	//		mainL.remove(num);
	//		cout << "after :\n";
	//		mainL.showList();
	//	}
	//	else if (choice == 3)
	//	{
	//		mainL.sort();
	//		mainL.showList();
	//	}
	//	else if (choice == 4)
	//	{
	//		linkedList<int> front;
	//		linkedList<int> back;

	//		mainL.frontBackSplit(mainL, front, back);
	//		if (mainL.getSize() >= 2)
	//		{
	//			cout << "front :\n";
	//			front.showList();
	//			cout << "back :\n";
	//			back.showList();
	//		}

	//	}
	//	else if (choice == 5)
	//	{

	//		linkedList<int> head1;
	//		linkedList<int> head2;
	//		mainL.alternatingSplit(mainL, head1, head2);
	//		if (mainL.getSize() >= 2)
	//		{

	//			cout << "head 1 :\n";
	//			head1.showList();
	//			cout << "head 2 :\n";
	//			head2.showList();
	//		}
	//	}
	//	else
	//	{
	//		string s;
	//		cout << "enter string :";
	//		cin.ignore();
	//		getline(cin, s);
	//		cout << "before :\n";
	//		mainL.showList();
	//		mainL.delBinarySequence(s);
	//		cout << "after :\n";
	//		mainL.showList();
	//	}

	//	char ch=0;
	//	cin.get(ch);
	//	if (ch)
	//	{
	//		again = true;
	//	}

	//}
	//while (again);

	system("pause");

	return 0;
}