#include <iostream>
#include "Matrix.h"
#include <string.h>
#include <fstream>
#include <time.h>

using namespace std;

Matrix::Matrix()
{
	row = 0;
	col = 0;
	mat = nullptr;
};


Matrix::Matrix(string str)
{
	ifstream matr(str);
	char comastr;
	int input;
	
	matr>>row;
	matr>>col;
	mat = new int *[row];
	for(int i = 0; i < row; i++)
	{
		mat[i] = new int [col];
		for (int j = 0; j < col; j++)
		{
			matr>>input;
			mat[i][j] = input;
			matr>> comastr;
		}
	}
	matr.close();
}

Matrix::Matrix(int n, int m)
{
	srand(time(0));
	row = n;
	col = m;
	mat = new int *[row];
	for(int i = 0; i < row; i++)
	{
		mat[i] = new int [col];
		for (int j = 0; j < col; j++)
		{
			mat[i][j] = rand() % 10;
		}
	}
}

Matrix Matrix::operator+(const Matrix &a)
{
	Matrix ne;
	if(a.row != row || a.col != col)
	{
		cout<<"Matrix can not be added\n";
		ne.row = 0;
		ne.col = 0;
		ne.mat = nullptr;
	}
	else
	{  
		ne.row = a.row;
		ne.col = a.col;
		ne.mat = new int *[row];
		for(int i = 0; i < row; i++)
		{
			ne.mat[i] = new int [col];
			for (int j = 0; j < col; j++)
			{
				ne.mat[i][j] = mat[i][j] + a.mat[i][j];
			}
		}	
	} 
	return ne;
}

Matrix Matrix::operator - (const Matrix &a)
{
	Matrix ne;
	if(a.row != row || a.col != col)
	{
		cout<<"Matrix can not be subtracted\n";
		ne.row = 0;
		ne.col = 0;
		ne.mat = nullptr;
	}
	else
	{  
		ne.row = a.row;
		ne.col = a.col;
		ne.mat = new int *[row];
		for(int i = 0; i < row; i++)
		{
			ne.mat[i] = new int [col];
			for (int j = 0; j < col; j++)
			{
				ne.mat[i][j] = mat[i][j] - a.mat[i][j];
			}
		}	
	} 
	return ne;
}


bool Matrix:: operator ==(const Matrix &a)
{

	bool check = true;
	if(a.row != row || a.col != col)
	{
		cout<<"Matrix have different dimensions\n";
		check = false;
	}
	else
	{
		for(int i = 0; i < row && check == true; i++)
		{
			for (int j = 0; j < col; j++)
			{
				if( mat[i][j] != a.mat[i][j])
				{
					check = false;
					break;
				}
			}
		}
	}
	return check;

}

Matrix Matrix::operator*(const Matrix &a)
{
	Matrix ne;
	if (col != a.row)
	{
		cout<<"Incompetible for multiplication\n";
		ne.row = 0;
		ne.col = 0;
		ne.mat = nullptr;
	}
	else
	{

		ne.row = row;
		ne.col = a.col;
		ne.mat = new int *[ne.row];
		for( int i = 0; i < ne.row; i++)
		{
			ne.mat[i] = new int [ne.col];
			for(int j = 0; j < ne.col ; j++)
			{
				ne.mat[i][j] = 0;
				for(int k = 0; k < col; k++)						//col is column no. of first matrix
				{
					ne.mat[i][j] = ne.mat[i][j] + (mat[i][k]*a.mat[k][j]);
				}
			}
		}
	}
	return ne;
}

void Matrix::transpose()
{
	Matrix trans;
	trans.row = col;
	trans.col = row;
	trans.mat = new int *[trans.row];
	for(int i = 0; i < trans.row; i++)
	{
		trans.mat[i] = new int [trans.col];
		for(int j = 0; j < trans.col; j++)
		{
			trans.mat[i][j] = mat[j][i];
		}
	}
	row = trans.row;
	col = trans.col;
	mat = trans.mat;
}

Matrix Matrix:: operator -()
{
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
		{
			mat[i][j] = mat[i][j] * -1;
		}
	}
	return *this;
}

Matrix Matrix:: operator +=(int a)
{
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
		{
			mat[i][j] = mat[i][j] + 5;
		}
	}
	return *this;
}

Matrix Matrix:: operator *=(int a)
{
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
		{
			mat[i][j] = mat[i][j] * 5;
		}
	}
	return *this;
}

int Matrix::getNumRows()
{
	return row;
}

int Matrix::getNumCols()
{
	return col;
}

int * Matrix::operator[](int a)
{
	return mat[a];
}
