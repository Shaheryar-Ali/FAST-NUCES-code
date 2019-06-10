#include <iostream>

using namespace std;

int main()
{
	int arr[10], max, min, sum, avg, order;
	int temp;
	
	for(int i = 0; i < 10; i++)
	{
		cout << "Enter a number: ";
		cin >> arr[i];
	}

	max = arr[0];
	
	for(int j = 1; j < 10; j++)
	{
		if(arr[j] > max)
			max = arr[j];
	}

	min = arr[0];

	for(int j = 1; j < 10; j++)
	{
		if(arr[j] < min)
			min = arr[j];
	}

	sum = arr[0];

	for(int j = 1; j < 10; j++)
	{
		sum = sum + arr[j];
	}
	
	avg = sum / 10;

	order = 1; // represents asc order


	for(int j = 1; j < 10; j++)
	{
		if(arr[j-1] > arr[j])
		{
			order = 0;
			break;			
		}
	}
	 
	if(order == 0)
	{
		order = 2;
		for(int j = 1; j < 10; j++)
		{
			if(arr[j-1] < arr[j])
			{
				order = 0;
				break;			
			}
		}
	}

	cout << "Maximum= " << max << endl;
	cout << "Minimum= " << min << endl;
	cout << "Sum= " << sum << endl;
	cout << "Average= " << avg << endl;

	if(order == 0)
		cout << "It is neither ascending or descending" << endl << endl;
	else if(order == 1)
		cout << "It is ascending" << endl << endl;
	else
		cout << "It is descending" << endl << endl;

	return 0;
}
