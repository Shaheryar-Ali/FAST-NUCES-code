#include<iostream>
#include<math.h>

using namespace std;

int main()
{
	int n1, n2, n3;
	char o1, o2;
	int temp, res;

	cout << "Enter a number: ";
	cin >> n1;
	cout << "Enter a number: ";
	cin >> n2;
	cout << "Enter a number: ";
	cin >> n3;
	cout << "Enter operator(+,-,*,/,^): ";
	cin >> o1;
	cout << "Enter operator(+,-,*,/,^): ";
	cin >> o2;

	switch(o1)
	{
		case '+':
			temp = n1 + n2;
			break;
		case '-':
			temp = n1 - n2;
			break;
		case '*':
			temp = n1 * n2;
			break;
		case '/':
			temp = n1 / n2;
			break;
		case '^':
			temp = pow(n1,n2);
			break;
		default:
			cout << "Invalid operation\n";
			return 0;

	}
	switch(o2)
	{
		case '+':
			res = temp + n3;
			break;
		case '-':
			res = temp - n3;
			break;
		case '*':
			res = temp * n3;
			break;
		case '/':
			res = temp / n3;
			break;
		case '^':
			res = pow(temp,n3);
			break;
		default:
			cout << "Invalid operation\n";
			return 0;

	}
	
	cout << "Result = " << res;
	cout << endl;
	return 0;

}
