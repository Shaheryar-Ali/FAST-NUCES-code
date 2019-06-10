#include <iostream>

using namespace std;

int main()
{
	int n;
	cout << "Enter a number less than 100: ";
	cin >> n;
	
	if(n < 100)
	{
		if(n/10 == 1)
		{
			if(n%10 == 0)
				cout << "Ten";
			else if(n%10 == 1)
				cout << "Eleven";
			else if(n%10 == 2)
				cout << "Twelve";
			else if(n%10 == 3)
				cout << "Thirteen";
			else if(n%10 == 4)
				cout << "Fourteen";
			else if(n%10 == 5)
				cout << "Fifteen";
			else if(n%10 == 6)
				cout << "Sixteen";
			else if(n%10 == 7)
				cout << "Seventeen";
			else if(n%10 == 8)
				cout << "Eigtheen";
			else if(n%10 == 9)
				cout << "Nineteen";
		}
		else
		{
			if(n/10 == 2)
				cout << "Twenty ";
			else if(n/10 == 3)
				cout << "Thirty ";
			else if(n/10 == 4)
				cout << "Forty ";
			else if(n/10 == 5)
				cout << "Fifty ";
			else if(n/10 == 6)
				cout << "Sixty ";
			else if(n/10 == 7)
				cout << "Seventy ";
			else if(n/10 == 8)
				cout << "Eighty ";
			else if(n/10 == 9)
				cout << "Ninety ";

			if(n%10 == 0 && n/10 == 0)
				cout << "Zero";
			else if(n%10 == 1)
				cout << "One";
			else if(n%10 == 2)
				cout << "Two";
			else if(n%10 == 3)
				cout << "Three";
			else if(n%10 == 4)
				cout << "Four";
			else if(n%10 == 5)
				cout << "Five";
			else if(n%10 == 6)
				cout << "Six";
			else if(n%10 == 7)
				cout << "Seven";
			else if(n%10 == 8)
				cout << "Eigth";
			else if(n%10 == 9)
				cout << "Nine";
		}
	
	}
	else
	{
		cout << "Invalid input";
	}
	return 0;
}
