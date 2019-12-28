#include"Tree.h"
int main()
{
	Tree<int> t(1);
	
	for (int i = 0; i < 4; i++)
	{
		t.AutoInsert(i + 2);
	}
	cout << "bfs :";
	t.BFS();
	cout << "pre order :";
	t.preOrder();
	cout << endl;
	cout << "in order";
	t.inOrder();
	cout << "post order ";
	t.postOrder();
	//t.RpostOrder();
	cout << endl;
	//t.postOrder();
	t.deleteNode(t.search(2));

	Tree<int> t2(t);
	t2.BFS();
	t.BFS();
	/*Tree<char> t;
	t.toTreeExpression("xy/pq/+ab*-");
	t.BFS();
*/




	system("pause");;
	return 0;
}


