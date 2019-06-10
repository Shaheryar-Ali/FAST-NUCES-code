#include<iostream>

using namespace std;

int main()
{
	int a[100], siz, temp, count, check;
	
	do
	{
		cout << "Enter the number of numbers you want to enter in the array, less than 100";
		cin >>siz; 
	}while(siz < 1 || siz >100);

	for(int i = 0; i < siz; i++)
	{	
		int test = 0;
		do
		{
			cout << "Enter a number, between 0 and 50 and not divisible by 4: ";
			cin >> temp;
			if (temp < 0 || temp > 50 || temp % 4 == 0)
				cout << "Invalid Entry\n ";
			else
				test = 1;
		}while(test == 0);
		a[i] = temp;
	}
	
	cout << "Enter a no. you want to check: ";
	cin >> check;
	count = 0;

	for(int j = 0; j < siz; j++)
	{
		if(a[j] == check)
			count++;

	}

	cout << check << " occurs " << count << " times." << endl;

}

