#include <iostream>
using namespace std;
int* merge(int *arr1, int *arr2, int m, int n);
int* remove(int *newarr, int *size);

void main()
{

	int x,ent,y,siz;
	cout<<"Enter the no. of entry you want to enter in array 1 ";
	cin>>x;
	int *arra1 = new int [x];
	cout<<"Enter the no. of entry you want to enter in array 2 ";
	cin>>y;
	int *arra2 = new int [y];
	int *merged_array = new int [x + y];
	int *final_arr1ay = new int [x+y];
	siz = x+y;
	//int *fsize = &siz;
	for(int i = 0; i < x; i++)
	{
		cout<<" Enter a no. for array 1 ";
		cin>>ent;
		arra1[i] = ent;
	}
	for(int j = 0; j < y; j++)
	{
		cout<<" Enter a no. for array 2 ";
		cin>>ent;
		arra2[j] = ent;
	}
	merged_array = merge (arra1,arra2,x,y);
	final_arr1ay = remove(merged_array, &siz);
	for (int l  = 0 ; l  < siz; l++)
	{
		cout<<final_arr1ay[l]<< " ";
	}



}

int* merge(int *arr1, int *arr2, int m, int n)
{
	int *new_array = new int [m + n];
	for(int l = 0; l < m + n; l++)
	{
		if ( l < m)
		{
			new_array[l] = arr1[l];
		}
		else
		{
			new_array[l] = arr2[l - m];
		}
	}
	return new_array;
}

int* remove(int *newarr, int *size)
{
	int *final_arr1 = new int [*size];
	int test;
	int fail = 0;
	for (int k = 0; k < *size; k++)
	{
		test = 0;
		for (int l = 0; l < k; l++)
		{
			if ( newarr[k] == newarr[l])
			{
				test = 1;
				fail++;
				break;
			}
		}
		if (test == 0)
		{
			final_arr1[ k - fail] = newarr [k];
		}
	}

	*size = *size - fail;

	int *final_arr = new int [*size];
	{
		for(int i = 0; i < *size; i++)
		{
			final_arr[i] = final_arr1[i];
		}

	}

	delete [] final_arr1;
	delete []newarr;
	return final_arr;
}

