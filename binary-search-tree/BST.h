
#include<iostream>
#include<stack>
#include<queue>
#include<vector>
using namespace std;

template<class T>
class BST;

template<class T>
class TNode
{
	friend BST<T>;
private:
	T data;
	TNode * left;
	TNode * right;
public:
	TNode(T val, TNode * l = nullptr, TNode * r = nullptr)
	{
		data = val;
		left = l;
		right = r;
	}

	TNode & operator = (TNode & ref)
	{
		data = ref.data;
		left = ref.left;
		right = ref.right;
		return *this;
	}

	bool operator == (TNode & ref)
	{
		return (data == ref.data) && (left == ref.left) && (right == ref.right);
	}


	bool isLeaf()
	{
		return (left == nullptr) && (right == nullptr);
	}


	friend ostream & operator <<(ostream & forNothing, TNode<T> & ref);
	

};

template<typename T>
ostream & operator <<(ostream & forNothing, TNode<T> & ref)
{
	cout << ref->data;
}



template<class T>
class BST
{
private:
	TNode<T> * root;
public:
	BST(T val)
	{
		root = new TNode<T>(val);

	}

	BST()
	{
		root = nullptr;
	}

	BST(BST<T> & ref)
	{
		root = new TNode<T>(ref.root->data);

		TNode<T> * temp = ref.root;

		TNode<T> * temp2 = root;
		queue<TNode<T> *> q;

		queue<TNode<T> *> q2;
		q2.push(temp2);

		q.push(temp);
		while (!q.empty())
		{
			temp = q.front();
			temp2 = q2.front();
			q2.pop();
			q.pop();


			if (temp->left)
			{
				setLeftChild(temp2, temp->left->data);
				q.push(temp->left);
				q2.push(temp2->left);

			}

			if (temp->right)
			{

				setRightChild(temp2, temp->right->data);
				q.push(temp->right);
				q2.push(temp2->right);
			}

		}

	}

	void setRoot(T val)
	{
		TNode<T> * temp = new TNode<T>(val);
		root = temp;
	}


	void setLeftChild(TNode<T> * node, T val)
	{
		if (!node)
		{
			return;
		}
		TNode<T> * temp = new TNode<T>(val);
		node->left = temp;

	}

	void setRightChild(TNode<T> * node, T val)
	{
		if (!node)
		{
			return;
		}
		TNode<T> * temp = new TNode<T>(val);
		node->right = temp;

	}

	TNode<T> * getLeftChild(TNode<T> * node)
	{
		if (node)
		{
			return node->left;
		}
		return NULL;
	}


	TNode<T> * getRightChild(TNode<T> * node)
	{
		if (node)
		{
			return node->right;
		}
		return NULL;
	}




	void insert(T val)
	{
		if (!root)
		{
			setRoot(val);
			return;
		}

		TNode<T> * prev = root;
		TNode<T> * temp = root;
		while (temp)
		{
			prev = temp;
			if (val < temp->data)
			{
				temp = temp->left;
			}
			else
			{
				temp = temp->right;
			}

		}

		if (val>prev->data)
		{
			setRightChild(prev, val);
		}
		else
		{
			setLeftChild(prev, val);
		}
	}


	void print()
	{

	}


	TNode<T> * search(T val)
	{
		TNode<T> * temp = root;
		if (val == root->data)
		{
			return root;
		}

		while (temp)
		{
			if (temp->data == val)
			{
				return temp;
			}
			else if (val < temp->data)
			{
				temp = temp->left;
			}
			else
			{
				temp = temp->right;
			}
		}

		return NULL;
	}



	void deleteNode(T val)
	{
		
		TNode<T> * temp = root;
		TNode<T> * prev = temp;
		while (temp->data != val)
		{
			prev = temp;
			if (val < temp->data)
			{
				temp = temp->left;
			}
			else
			{
				temp = temp->right;
			}

		}



		//find degree
		int degree = 0;
		if (temp->right)
		{
			degree++;
		}

		if (temp->left)
		{
			degree++;
		}

		if (degree == 0)
		{
			//degree zero handle

			if (val < prev->data)
			{
				prev->left = nullptr;
			}
			else
			{
				prev->right = nullptr;
			}

			delete temp;
		}
		else if (degree == 1)
		{
			// degree one handle
			if (val < prev->data)
			{
				//on left handle
				if (temp->left)
				{
					prev->left = temp->left;
				}
				else
				{
					prev->left = temp->right;
				}
			}
			else
			{
				//on right handle
				if (temp->left)
				{
					prev->right = temp->left;
				}
				else
				{
					prev->right= temp->right;
				}
			}
		}
		else
		{
			//degree 2 handle

			//deleteion node se smallest bara element lainy k liye

			TNode<T> * node = getInorderSuccessor(temp);
			if (node->isLeaf())
			{
				//agar leaf hy to wesei data change kardy uska previous to already handle ho chuka hy 
				temp->data = node->data;
				delete node;
			}
			else
			{

				//agar uska koi agay child hy to agar left side py hy to
				// be deleted elemnt to udar kardy warna right py kardy

				if (val < prev->data)
				{
					prev->left = node;
				}
				else
				{
					prev->right = node;
				}
			}
		}
	}



	TNode<T> * getInorderSuccessor(TNode<T> * node)
	{
		//returns inorder successor
		// agar leaf node ho to previous ko khudhi handle kar laita hy
		//agar leaf na ho to wese he insert kar daita hy

		TNode<T> * temp = node;
		TNode<T> * prev = temp;
		if (temp != root)
		{
			//agar root nai hy to right ho ek baar warna root py right hoa to bigs ki taraf jae ga
			//root k liye hmain sbse lowest chahiye hota hy 
			temp = temp->right;
		}

		while (temp)
		{
			//previous or current(temp) element ko find karny k liye 
			if (temp->isLeaf())
			{
				break;
			}
			prev = temp;
	
		
			if (temp->left)
			{
				temp = temp->left;
			}
			else
			{
				break;
			}
		}

		if (temp->isLeaf())
		{
			if (prev->left->data == temp->data)
			{
				prev->left = nullptr;

			}
			else
			{
				prev->right = nullptr;
			}
			
		}

		return temp;

	}


	TNode<T> * getMin()
	{
		TNode<T> * temp = root;
		while (!temp->isLeaf())
		{
			if (temp->left)
			{
				temp = temp->left;
			}
			else
			{
				temp = temp->right;
			}
		}

		return temp;
	}



	TNode<T> * getMax()
	{
		TNode<T> * temp = root;
		while (!temp->isLeaf())
		{
			if (temp->right)
			{
				temp = temp->right;
			}
			else
			{
				temp = temp->left;
			}
		}

		return temp;
	}


	void BFS()
	{
		TNode<T> * temp = root;
		queue<TNode<T> *> q;
		q.push(temp);
		while (!q.empty())
		{
			temp = q.front();
			q.pop();

			if (temp)
			{
				cout << temp->data << " ";
			}

			if (temp->left)
			{
				q.push(temp->left);
			}

			if (temp->right)
			{
				q.push(temp->right);
			}

		}
	}



	void RinOrder()
	{
		RinOrderH(root);
	}


	void RinOrderH(TNode<T> * temp)
	{
		if (temp == nullptr)
		{
			return;
		}

		RinOrderH(temp->left);
		cout << temp->data << " ";
		RinOrderH(temp->right);

	}



	void RpreOrder()
	{
		RpreOrderH(root);
	}



	void RpreOrderH(TNode<T> * temp)
	{
		if (temp == nullptr)
		{
			return;
		}

		cout << temp->data << " ";
		RpreOrderH(temp->left);
		RpreOrderH(temp->right);

	}




	void RpostOrder()
	{
		RpostOrderH(root);
	}

	void RpostOrderH(TNode<T> * temp)
	{
		if (temp == nullptr)
		{
			return;
		}

		RpostOrderH(temp->left);
		RpostOrderH(temp->right);
		cout << temp->data << " ";

	}




	void preOrder()
	{
		TNode<T> * temp = root;
		stack<TNode<T> *> s;
		s.push(temp);
		while (!s.isEmpty())
		{
			temp = s.top();
			s.pop();
			cout << temp->data << " ";

			if (temp->right)
			{
				s.push(temp->right);

			}

			if (temp->left)
			{
				s.push(temp->left);
			}

		}

	}


	void inOrder()
	{

		stack<TNode<T> *> s;
		TNode<T> * current = root;
		while (current != nullptr || !s.isEmpty())
		{
			while (current != nullptr)
			{
				s.push(current);
				current = current->left;
			}

			current = s.top();
			s.pop();
			cout << current->data << " ";
			current = current->right;
		}

	}


	void postOrder()
	{

		TNode<T> * temp = root;
		stack<TNode<T> *> s1;
		stack<TNode<T> *> s2;
		s1.push(temp);
		while (!s1.isEmpty())
		{
			temp = s1.top();
			s1.pop();
			s2.push(temp);
			if (temp->left)
			{
				s1.push(temp->left);
			}

			if (temp->right)
			{
				s1.push(temp->right);
			}

		}
		while (!s2.isEmpty())
		{
			temp = s2.top();
			s1.pop();
			cout << temp->data << " ";
		}
	}

	int getHight()
	{
		vector<int> v;
		getHightHelper(root, v, 0);
		int max = v.front();
		for (vector<int>::iterator i = v.begin(); i != v.end(); i++)
		{
			if (*i > max)
			{
				max = *i;
			}
		}
		return max;
	}

	void getHightHelper(TNode<T> * node,vector<int> & ref, int h)
	{
		if (node->isLeaf())
		{
			ref.push_back(h);
			return;
		}

		if (node->left)
		{
			getHightHelper(node->left,ref,h+1);
		}
		if (node->right)
		{
			getHightHelper(node->right, ref, h + 1);
		}

	}

	bool isEqual(BST<T> & T1,BST<T> & T2)
	{

		TNode<T> * temp1 = T1.root;

		TNode<T> * temp2 = T2.root;
		queue<TNode<T> *> q1;
		queue<TNode<T> *> q2;

		q1.push(temp1);

		q2.push(temp2);

		while (!q1.empty() || !q2.empty())
		{

			if ((q1.empty() && !q2.empty()) || (!q1.empty() && q2.empty()))
			{
				return false;
			}


			temp1 = q1.front();
			q1.pop();

			temp2 = q2.front();
			q2.pop();

			if (temp1->data != temp2->data)
			{
				return false;
			}


			if (temp1->left || temp2->left)
			{
				if (temp1->left)
				{

					q1.push(temp1->left);
				}
				else
				{
					return false;
				}



				if (temp2->left)
				{

					q2.push(temp2->left);
				}
				else
				{
					return false;
				}

			}

			if (temp1->right || temp2->right)
			{
				if (temp1->right)
				{

					q1.push(temp1->right);
				}
				else
				{
					return false;
				}



				if (temp2->right)
				{

					q2.push(temp2->right);
				}
				else
				{
					return false;
				}

			}

		}

		return true;
	}

	T findMaxMin(int flag)
	{
		if (flag == 1)
		{
			return getMax()->data;
		}
		else if (flag == 0)
		{
			return getMin()->data;
		}
		else
		{
			cout << "wrong command given : ";
			system("abort");
		}
	}

	int getNodeCount(BST<T> * tree)
	{

		int count=0;
		TNode<T> * temp = tree->root;
		queue<TNode<T> *> q;
		q.push(temp);
		while (!q.empty())
		{
			temp = q.front();
			q.pop();

			if (temp)
			{
				count++;
			}

			if (temp->left)
			{
				q.push(temp->left);
			}

			if (temp->right)
			{
				q.push(temp->right);
			}

		}
		return count;

	}

	bool IS_BST()
	{
		return isBST(root);
	}

	bool isBST(TNode<T> * root)
	{
		
		if (root->isLeaf())
		{
			return true;
		}
		bool left = true;
		bool right=true;
		if (root->left)
		{
			 left=isBST(root->left);
		}
		if (root->right)
		{
			right= isBST(root->right);
		}

		if (left && right)
		{

			if (root->left && root->right)
			{
				if (root->data > root->left->data && root->data < root->right->data)
				{
					return true;
				}
				else
				{
					return false;
				}

			}
			else if (root->left && !root->right)
			{
				if (root->data > root->left->data)
				{
					return true;
				}
				else
				{
					return false;
				}
			}
			else
			{
				if (root->data < root->right->data)
				{
					return true;
				}
				else
				{
					return false;
				}
			}
		}
		else
		{
			return false;
		}

	}

	void destroy(TNode<T> * node)
	{

		if (node->left)
		{
			destroy(node->left);
		}
		if (node->right)
		{
			destroy(node->right);
		}

		delete node;
	}

	~BST()
	{
		destroy(root);
	}
};

