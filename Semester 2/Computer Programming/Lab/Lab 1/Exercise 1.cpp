#include <iostream>
using namespace std;
void main ()
{
	int a[6], flag = 1,temp;

	for (int x = 0; x < 6; x++)
	{
		cout<<"Enter a no."<<endl;
		cin>> a[x];
	}
	for( int i = 0; i < (6 - 1) && flag; i++)
	{
		flag = 0;
	for( int y = 0; y < (6-1); y++)
	{
		if ( a[y+1] < a[y])
		{
			temp = a[y];
			a[y] = a[y+1];
			a[y+1] = temp;
			flag = 1;
		}
	}
	}
	
	for (int x = 0; x < 6; x++)
	{
		cout<< a[x]<< "  ";
	}
}