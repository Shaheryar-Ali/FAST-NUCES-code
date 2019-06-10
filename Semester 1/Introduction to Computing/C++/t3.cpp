#include<iostream>
#include <stdlib.h>

using namespace std;

int main()
{
	int total, coin5_a, coin2_a, coin1_a, coin5, coin2, coin1;

	cout << "Enter Total amount: ";
	cin >>total;
	cout << "Enter number of 5 coins available: ";
	cin >>coin5_a;
	cout << "Enter number of 2 coins available: ";
	cin >>coin2_a;
	cout << "Enter number of 1 coins available: ";
	cin >>coin1_a;

	coin5 = 0;
	coin2 = 0;
	coin1 = 0;

	while(total >= 5 && coin5_a >0)
	{
		total = total - 5;
		coin5_a--;
		coin5++;
	}
	while(total >= 2 && coin2_a >0)
	{
		total = total - 2;
		coin2_a--;
		coin2++;
	}
	while(total >= 1 && coin1_a >0)
	{
		total = total - 1;
		coin1_a--;
		coin1++;
	}

	if(total != 0)
		cout << "The combination does not exists";
	else
	{
		cout << "No. of 5 coins:" << coin5 <<endl;
		cout << "No. of 2 coins:" << coin2 <<endl;
		cout << "No. of 1 coins:" << coin1 <<endl; 
	}

	cout << endl;
	return 0;
}
