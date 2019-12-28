#include<iostream>
using namespace std;
template<typename T>
class Sparse
{ 
private:
	int * ith;
	int * jth;
	T * data;
	int rows;
	int cols;
	int noe;
public:
	Sparse(int rows,int cols)
	{
		ith = new int[rows*cols];
		jth = new int[rows*cols];
		data = new T[rows*cols];
		this->rows = rows;
		this->cols = cols;
		noe = 0;
	}

	Sparse(Sparse & ref)
	{
		noe = ref.noe;
		rows = ref.rows;
		cols = ref.cols;
		ith = ref.ith;
		jth = ref.jth;
		for (int i = 0; i < noe; i++)
		{
			data[i] = ref.data[i];
		}
	}

	void setElement(int iParameter, int jParameter, T val)
	{
		if ((val != 0) && (iParameter>=0 && iParameter<rows) && (jParameter>=0 && jParameter<=cols))
		{
			ith[noe] = iParameter;
			jth[noe] = jParameter;
			data[noe] = val;
			noe++;
		}
		else
		{
			return;
		}
	}
	

	T getElement(int iParameter, int jParameter)
	{
		for (int i = 0; i < noe; i++)
		{
			if (ith[i] == iParameter && jth[i] == jParameter)
			{
				return data[i];
			}
		}
		return 0;
	}



	void printMatrix()
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				cout << getElement(i, j);
				cout << " ";
			}
			cout << endl;
		}
	}

	void transpose()
	{
		Sparse<T> transposed(this->cols, this->rows);
		for (int i = 0; i <cols; i++)
		{
			for (int j = 0; j <rows; j++)
			{
				transposed.setElement(i, j, this->getElement(j, i));
			}
		}


		transposed.printMatrix();
	}

	void operator+(Sparse<T> & ref)
	{
		Sparse<T> plused(this->rows, this->cols);
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				if (getElement(i, j) == 0 && ref.getElement(i, j) == 0)
				{
					plused.setElement(i, j, 0);
				}
				else if (getElement(i, j) != 0 && ref.getElement(i, j) == 0)
				{
					plused.setElement(i, j, getElement(i, j));
				}
				else if (getElement(i, j) == 0 && ref.getElement(i, j) != 0)
				{

					plused.setElement(i, j, ref.getElement(i, j));
				}
				else
				{

					plused.setElement(i, j, getElement(i, j)+ref.getElement(i,j));
				}
			}
		}


		plused.printMatrix();
	}

};


















