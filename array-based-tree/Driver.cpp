#include"ArrayTree.h"
int main()
{

	BinaryTree<int> t(2);
	t.setRoot(1);
	t.setLeftChild(1, 2);
	t.setRightChild(1, 3);
	t.levelOrder();
	//t.remove(1);
	t.levelOrder();
	t.postOrder();
	cout << endl;
	t.inOrder();
	cout << endl;
	t.preOrder();


	system("pause");
		return 0; 
}