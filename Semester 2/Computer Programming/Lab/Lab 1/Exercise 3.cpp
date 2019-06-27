#include <iostream>
using namespace std;

void print_pyramid(int n);

void main()
{
	int row;
	cout << "Enter the no. of rows = ";
	cin >> row;
	print_pyramid(row);
	
}

void print_pyramid(int n)
{
	for (int i = 1; i <= n ; i++)
	{
		for (int space = 1; space <= (n-i); space++)
			cout<<" ";
		for (int star = 1; star <= 2 * i; star++)
			cout<<"*";
		cout<<endl;
	}
}