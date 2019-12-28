#include<iostream>
#include<queue>
#include<string>
#include"Stack.h"
using namespace std;

template<class T>
class Tree;

template<class T>
class TNode
{
	friend Tree<T>;
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


};



template <class T>
class Tree
{
private:
	TNode<T> * root;
public:
	Tree(T val)
	{
		root = new TNode<T> (val);

	}

	Tree()
	{
		root = nullptr;
	}

	Tree(Tree<T> & ref)
	{
		root = new TNode<T> (ref.root->data);

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

	TNode<T> * search(T val)
	{

		TNode<T> * temp = root;
		Stack<TNode<T> *> s;
		s.push(temp);
		while (!s.isEmpty())
		{
			temp = s.pop();
			if (temp->data == val)
			{
				return temp;
			}

			if (temp->right)
			{
				s.push(temp->right);

			}

			if (temp->left)
			{
				s.push(temp->left);
			}

		}
		return NULL;

	}

	void deleteNode(TNode<T> * toDel)
	{

		TNode<T> * temp = root;
		Stack<TNode<T> *> s;
		s.push(temp);
		while (!s.isEmpty())
		{
			temp = s.pop();
			
			if (temp->right)
			{
				if (temp->right = toDel)
				{
					
					//properDelete(temp->right);
					temp->right= nullptr;
					break;
				}
				s.push(temp->right);

			}

			if (temp->left)
			{
				if (temp->left = toDel)
				{
				//	properDelete(temp->left);
					temp->left = nullptr;
					break;
				}

				s.push(temp->left);
			}

		}
	}
/*
	void properDelete(TNode<T> * RRNode)
	{

		if (!RRNode)
		{
			cout << "ca";
			return;
		}
		TNode<T> * temp = RRNode;
		queue<TNode<T> *> q;
		q.push(temp);
		while (!q.empty())
		{
			temp = q.front();


			if (temp->left)
			{
				q.push(temp->left);
			}

			if (temp->right)
			{
				q.push(temp->right);
			}

			delete temp;
			q.pop();
			
		}
	}*/
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
	
	void AutoInsert(T val)
	{
		TNode<T> * value = new TNode<T>(val);
		TNode<T> * temp = root;
		queue<TNode<T> *> q;
		q.push(temp);
		while (!q.empty())
		{
			temp = q.front();
			q.pop();
			if (temp->left==nullptr)
			{
				temp->left = value;
				break;
			}
			else
			{
				q.push(temp->left);
			}

			if (temp->right==nullptr)
			{
				temp->right = value;
				break;
			}
			else
			{
				q.push(temp->right);
			}
		}


	}


	void toTreeExpression(string exp)
	{
		Stack<TNode<char> *> s;

		while (exp.length())
		{
			if (!isOperator(exp[0]))
			{
				s.push(newNode(exp[0]));
				exp.erase(0, 1);
			}
			else
			{
				TNode<char> * op = newNode(exp[0]);
				TNode<char> * a = s.pop();
				TNode<char> * b = s.pop();
				op->right = a;
				op->left = b;
				s.push(op);
				exp.erase(0, 1);

			}
		}

		root = s.pop();
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
		Stack<TNode<T> *> s;
		s.push(temp);
		while (!s.isEmpty())
		{
			temp = s.pop();
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

		Stack<TNode<T> *> s;
		TNode<T> * current = root;
		while (current!=nullptr|| !s.isEmpty())
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
		Stack<TNode<T> *> s1;
		Stack<TNode<T> *> s2;
		s1.push(temp);
		while(!s1.isEmpty())
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
			temp = s2.pop();

			cout << temp->data << " ";
		}
	}






	// helpers 

	bool isOperator(char c)
	{
		return ((c == '+') || (c == '-')) || ((c == '*') || (c == '/'));
	}


	TNode<T> * newNode(T val)
	{
		return new TNode<T>(val);
	}

};


