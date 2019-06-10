#include<iostream>

using namespace std;

const int size = 5;

int main()
{
	int a[size];

	for(int j = 0; j < size; j++)
	{
		cout << "Enter a number: ";
		cin >> a[j];
	}
	int siz = size - 1;
	int temp;
	for(int i = 0; i <= siz; i++)
	{
		temp = a[i];
		a[i] = a[siz];
		a[siz] = temp;
		siz--;
	}

	for(int k = 0; k < size; k++)
	  cout << a[k] << endl;

}
