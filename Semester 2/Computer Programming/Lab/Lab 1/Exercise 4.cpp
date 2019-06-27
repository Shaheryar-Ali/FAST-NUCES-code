#include <iostream>

using namespace std;

void main()
{
	int a[10], largest, large_ad = 0, smallest, small_ad = 0;
	
	for (int x = 0; x < 10; x++)
	{
		cout<<"Enter a no."<<endl;
		cin>> a[x];
	}
	largest = a[0];
	smallest = a[0];

	for (int lar = 1; lar < 10 ; lar ++)
	{
		if ( a[lar] > largest)
		{
			largest = a[lar];
			large_ad = lar;
		}
	}

	for (int sml = 1; sml < 10 ; sml ++)
	{
		if ( a[sml] < smallest)
		{
			smallest = a[sml];
			small_ad = sml;
		}
	}
	cout<< " Largest no. = " << largest << endl;
	cout<< " Address of Largest = " << large_ad << endl;
	cout<< "Smallest no. = " <<smallest <<endl;
	cout<< "Address of Smallest = " <<small_ad <<endl;

}