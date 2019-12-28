#include"AVL.h"
using namespace std;
int main()
{

	AVL<int> t;
	for (int i = 0; i < 8; i++)
	{
		int x = 0;
		cin >> x;
		t.insert(x);
	}
	t.BFS();


	system("pause");
	return 0;
}