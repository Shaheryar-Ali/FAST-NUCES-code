#include <iostream>

using namespace std;

int main()
{
	int sum, temp, avg, count;
	count = 0;
	sum = 0;

	do
	{
		cout << "Enter a number: ";
		cin >> temp;

		if(temp >= 0)
		{
			sum = sum + temp;
			count++;
		}		
	}while(temp>=0);
	
	if(count != 0)
	{
		avg = sum / count;
		cout << "Average = " << avg << endl;
	}
	
	return 0;
}


