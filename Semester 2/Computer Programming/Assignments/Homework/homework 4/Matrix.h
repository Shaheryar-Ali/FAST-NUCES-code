#include <string.h>

using namespace std;

#ifndef MATRIX_H
#define MATRIX_H


class Matrix
{
	private:
		int row;
		int col;
		int **mat;
		
	public:
		Matrix();
		Matrix(string str);
		Matrix(int n, int m);
		Matrix operator + (const Matrix &a);
		Matrix operator - (const Matrix &a);
		bool operator == (const Matrix &a);
		Matrix operator * (const Matrix &a);
		void transpose();
		Matrix operator - ();
		Matrix operator +=(int);
		Matrix operator *=(int);
		int getNumRows();
		int getNumCols();
		int * operator [](int a);
};




#endif MATRIX_H