#include<iostream>
#include<stack>
#include<queue>
using namespace std;

template<class T>
class AVL;

template<class T>
class TNode
{
	friend AVL<T>;
private:
	T data;
	int hight;
	TNode * left;
	TNode * right;
public:
	TNode(T val,int h=0, TNode * l = nullptr, TNode * r = nullptr)
	{
		data = val;
		left = l;
		right = r;
		hight = h;
	}

	TNode & operator = (TNode & ref)
	{
		data = ref.data;
		left = ref.left;
		hight = ref.hight;
		right = ref.right;
		return *this;
	}

	bool operator == (TNode & ref)
	{
		return (data == ref.data) && (left == ref.left) && (right == ref.right) && (hight==ref.hight);
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


template<typename T>
class AVL
{
private:
	TNode<T> * root;
public:
	AVL()
	{
		root = nullptr;
	}

	AVL(T val)
	{
		root = new TNode<T>(val);
	}

	void setRoot(T val)
	{
		root = new TNode<T>(val);
	}



	void insert(T val)
	{
		if (!root)
		{
			setRoot(val);
			return;
		}

		insertHelper(root, val);
	}



	int balancingFactor(TNode<T> * node)
	{
		int rightH = 0;
		int LeftH = 0;
		if (node->left)
		{
			LeftH = node->left->hight;
		}
		if (node->right)
		{
			rightH = node->right->hight;
		}

		return LeftH - rightH;
	}

	
	
	void insertHelper(TNode<T> * root, T val)
	{
		
		if (!root)
		{
			return;
		}

		if (val < root->data)
		{
			insertHelper(root->left, val);
		}
		else
		{
			insertHelper(root->right, val);
		}

		if (val > root->data)
		{
			root->right = new TNode<T>(val);
		}
		else
		{
			root->left = new TNode<T>(val);
		}


		rectifyHight(root);

		int bf = balancingFactor(root);
		if (bf < -1 && val>root->right->data)
		{
			RRrotation(root);
		}
		else if (bf < -1 && val < root->right->data)
		{
			RLrotation(root);
		}
		else if (bf > 1 && val < root->left->data)
		{
			LLrotation(root);
		}
		else if (bf > 1 && val > root->left->data)
		{
			LRrotation(root);
		}
		else
		{
			// ja apna kaam kar 
		}


	}

	void rectifyHight(TNode<T> * node)
	{
		int hightR = 0;
		int hightL = 0;
		if (node->left)
		{
			hightL = node->left->hight;
		}
		if (node->right)
		{
			hightR = node->right->hight;
		}

		node->hight = 1 + (hightL > hightR ? hightL : hightR);

	}

	void RRrotation(TNode<T> * node)
	{
		TNode<T> * A = node;
		TNode<T> * P = node->right;
		TNode<T> * B = node->right->right;

		if (P->left)
		{
			A->right = P->left;
		}
		P->left = A;
		
		rectifyHight(A);
		rectifyHight(B);
		rectifyHight(P);
	}



	void LLrotation(TNode<T> * node)
	{
		TNode<T> * B = node;
		TNode<T> * P = node->left;
		TNode<T> * A = node->left->left;
		if (P->right)
		{
			B->left = P->right;
		}
		P->right = B;
		rectifyHight(A);
		rectifyHight(B); 
		rectifyHight(P);

	}

	void RLrotation(TNode<T> * node)
	{
		TNode<T> * A = node;
		TNode<T> * B = node->right;
		TNode<T> * P = node->right->left;
		if (P->left)
		{
			node->right->left = P->left;
		}

		if (P->right)
		{
			node->right = P->right;
		}

		P->right = A;
		P->left = B;

		rectifyHight(A);
		rectifyHight(B);
		rectifyHight(P);


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




	void LRrotation(TNode<T> * node)
	{
		TNode<T> * B = node;
		TNode<T> * P = node->left;
		TNode<T> * A = node->left->right;
		if (P->left)
		{
			node->left = P->left;
		}

		P->left = node;
		rectifyHight(A);
		rectifyHight(B);
		rectifyHight(P);

	}



};
