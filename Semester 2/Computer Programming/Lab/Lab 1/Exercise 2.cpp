#include <iostream>
using namespace std;
void main()
{
	int a[10], forw = -1, rev = 10,temp;

	for (int x = 0; x < 10; x++)
	{
		cout<<"Enter a no."<<endl;
		cin>> a[x];
	}



	for ( int i = forw + 1; i  < 10; i++)
	{
		if ( a[i]%2 == 1)
		{
			forw = i;
			break;
		}
	}
	for ( int j = rev - 1; j > 0; j--)
	{
		if ( a[j]%2 == 1)
		{
			rev = j;
			break;
		}
	}
	temp = a[forw];
	a[forw] = a[rev];
	a[rev] = temp;
	cout<<endl;
	for (int x = 0; x < 10; x++)
	{
		cout<< a[x] << " ";
	}
	cout<<endl;
}