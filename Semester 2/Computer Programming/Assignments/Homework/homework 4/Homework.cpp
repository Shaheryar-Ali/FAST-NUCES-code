#include<iostream>
#include "Matrix.h"
#include <string.h>
#include <fstream>
#include <conio.h>
using namespace std;

void printMatrix(Matrix & m) 
{ 
	for(int i=0;i< m.getNumRows();i++)
	{
		for(int j=0;j< m.getNumCols();j++)
		{
			cout<< m[i][j]<<" ";
		}
	cout<<endl;
	} 
}		


int main()
{
	 Matrix m1;										//empty 0x0 matrix     
	 
	 Matrix m2("mat1.txt"),m3("m3.txt");			//read from files

	 Matrix x;
	 x= m2 * m3;
	 printMatrix(x);


	 /*
	 Matrix m5(5,7);


	 m1 = m2+m3;										//add matrices
	
	 Matrix m4=m2-m3;				//subtract matrices

	 if(m1==m4)
	 {         
		 cout<<"m1 and m4 are equal matrices\n";
		 _getch();
	 }     


	 m5=m1*m4;//matrix multiplication (assume compatability)

	 m5.transpose();//convert nxm to mxn matrix  

	 m2=-m2;//negates all elements of m2  

	 m2+=5;//adds 5 to all elements of m2

	 m2*=5;//multiplies 5 to all elements of m2
	// printMatrix(m2);

	*/
	 return 0;
}

