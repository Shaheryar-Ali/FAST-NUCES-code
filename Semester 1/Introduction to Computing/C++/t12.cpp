#include <iostream>

using namespace std;

int main()
{
	int x, num, temp;
	
	cout << "Enter a number: ";
	cin >> num;

	x = 1;

	while(x <= num)
	{
		x = x * 10;

	}

	x = x/10;

	while(x > 0)
	{
		temp = num / x;
		cout << temp << endl;
		num = num - temp * x;
		x = x/10;
	}
	return 0;
}
