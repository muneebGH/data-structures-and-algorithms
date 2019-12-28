#include"DoubleLinkedList.h"
int main()
{

	DList<int> d(1);
	d.print();
	cout << "inserting at head" << endl;
	d.insertAtHead(0);
	d.print();
	cout << "inserting at tail" << endl;
	d.insertAtTail(2);
	d.print();
	cout << "inserting some elements wese he at tail" << endl;
	for (int i = 0; i < 5; i++)
	{
		d.insertAtTail(i + 3);
	}
	d.print();
	cout << "deleting at head" << endl;
	d.deleteAtHead();
	d.print();
	cout << "deleting at tail" << endl;
	d.deleteAtTail();
	d.print();
	cout << "geting 3rd node" << endl;
	d.getNode(3)->printNode();
	cout << "searching 3 and printing" << endl;
	d.search(3)->printNode();
	cout << "inserting after 3" << endl;
	d.insertAfter(3, 4);
	d.print();
	cout << "deleting after 3" << endl;
	d.deleteAfter(3);
	d.print();
	cout << "getting length" << endl;
	cout << d.getLength()<<endl;
	//cout << "checking copy constructor " << endl;

	//DList<int> d2(d);
	//d2.print();


	system("pause");
	return 0;

}