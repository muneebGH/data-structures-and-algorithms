#include<iostream>
#include<cmath>
#include<stack>
#include<queue>
using namespace std;
template<class T>
class BinaryTree
{
private:
	int range;
	int hight;
	T * data;
	bool * status;
public:
	BinaryTree(int h)
	{
		int hight =h;
		range = pow(2, h) - 1;

		data = new T[range];
		status = new bool[range];
		for (int i = 0; i < range; i++)
		{
			status[i] = false;
		}

	
	}

	void setRoot(T val)
	{
		data[0] = val;
		status[0] = true;
	}

	void setLeftChild(T parent, T val)
	{
		int i;
		for (i = 0; i < range; i++)
		{
			if (status[i])
			{

				if (data[i] == parent)
				{
					break;
				}
			}
		}

		if (i == range)
		{
			return;
		}

		int lindex = 2 * i;
		lindex++;
		data[lindex] = val;
		status[lindex] = true;
	}

	void setRightChild(T parent, T val)
	{
		int i;
		for (i = 0; i < range; i++)
		{
			if (status[i])
			{

				if (data[i] == parent)
				{
					break;
				}
			}
		}

		if (i == range)
		{
			return;
		}

		int lindex = 2 * i;
		lindex++;
		lindex++;
		data[lindex] = val;
		status[lindex] = true;
	}

	int getParent(int node)
	{
		int p = (node - 1) / 2;
		p=(int)floor(p);

		return p;
	}

	int getLeftChild(int par)
	{
		par = par * 2;
		par++;
		return par;
	}

	int getRightChild(int par)
	{

		par = par * 2;
		par++;
		par++;
		return par;
	}

	void remove(T node)
	{
		int i=-1;
		for (i = 0; i < range; i++)
		{
			if (status[i])
			{
				if (data[i] == node)
				{
					break;
				}
			}
		}
		if (i == range)
		{
			return;
		}

		queue<int> q;
		q.push(i);
		int var;
		bool iterator = true;
		while (!q.empty())
		{
			var = q.front();
			q.pop();
			if (var < range)
			{

				status[var] = false;
			}

			if (iterator)
			{


				int child = getLeftChild(var);
				if (child < range)
				{
					q.push(child);
				}
				else
				{
					iterator = false;
				}
				child = getRightChild(var);
				if (child < range)
				{

					q.push(child);
				}
			}
		}

	}


	void levelOrder()
	{
		T root = 0;
		queue<T> q;
		q.push(root);
		bool iterator = true;
		while (!q.empty())
		{
			root = q.front();
			q.pop();
			if (status[root])
			{
				cout << data[root] << " ";

			}

			if (iterator)
			{
				int child = getLeftChild(root);
				if (child < range)
				{
					q.push(child);
				}
				else
				{
					iterator = false;
				}

				child = getRightChild(root);
				if (child < range)
				{
					q.push(child);
				}

			}

		}
	}

	void preOrder()
	{
		preOrderH(0);
	}

	void preOrderH(int i)
	{
		if (i >= range)
		{
			return;
		}

		if (status[i])
		{
			cout << data[i] << " ";
		}
		preOrderH(getLeftChild(i));
		preOrderH(getRightChild(i));
	}

	void inOrder()
	{
		inOrderH(0);
	}

	void inOrderH(int i)
	{
		if (i >= range)
		{
			return;
		}

		preOrderH(getLeftChild(i));

		if (status[i])
		{
			cout << data[i] << " ";
		}
		preOrderH(getRightChild(i));
	}



	void postOrder()
	{
		postOrderH(0);
	}

	void postOrderH(int i)
	{
		if (i >= range)
		{
			return;
		}

		preOrderH(getLeftChild(i));

		preOrderH(getRightChild(i));

		if (status[i])
		{
			cout << data[i] << " ";
		}
	}

	bool isPerfectTree()
	{
		for (int i = 0; i < range; i++)
		{
			if (!status[i])
			{
				return false;

			}
		}
	}


	void isComplete()
	{
		int hight1 = pow(2, hight - 1) - 1;
		for (int i = 0; i < hight1; i++)
		{
			if (status[i] == false)
			{
				return false;
			}
		}

		int hight2 = range - hight1;
		for (int i = hight2; i < range; i++)
		{
			if (status[i] == false)
			{
				return true;
			}
		}
	}


	void displayAncestors(T node)
	{
		int index = -1;
		for (int i = 0; i < range; i++)
		{
			if (status[i])
			{
				if (data[i] == node)
				{
					index = i;
					break;
				}
			}
		}

		if (index = -1)
		{
			return;
		}

		levelOrderH(index);

	}
};