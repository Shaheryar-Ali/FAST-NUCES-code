#include<iostream>
using namespace std;
void RowWiseInput( int *row, int size);
void AddColumns(int *&col, int size);
void RowWisePrint(int **arr, int size);


void main()
{
	int n,size;
	int **triangle;
	cout<<"Enter the no. of rows";
	cin>>n;
	triangle = new int *[n];
	for(int x = 0; x < n; x++)
	{
		size = x + 1;
		AddColumns(triangle[x],size);
		RowWiseInput(triangle[x],x);
	}
	RowWisePrint(triangle, n);
}




void RowWiseInput( int *row, int size)
{
	int temp;
	for(int i = 0; i <=size; i++)
	{
	cout<<"Enter a no.";
		cin>>temp;
		row[i] = temp;
	}
}

void AddColumns(int *&col, int size)
{
	col = new int [size];
}

void RowWisePrint(int **arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cout<<arr[i][j]<<" ";
		}
		cout<< endl;
	}
}
