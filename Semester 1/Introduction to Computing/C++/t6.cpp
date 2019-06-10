#include<iostream>

using namespace std;

int sum(int a, int b);
int difference(int a, int b);
int multiply(int a, int b);
int divide(int a, int b);
int remainder(int a, int b);


int main()
{
	int num1, num2, res;
	char op;

	cout << "Enter the symbol of operation you want to perform: \n Add(+), Subtract(-), Multiply(x), Divide(/), Modulus(%)\n";
	cin >> op;

	cout << "Enter number: "; 	
	cin>> num1;

	cout << "Enter number: "; 	
	cin>> num2;


	switch(op)
	{
		case '+':
			res = sum(num1,num2);
			break;
		case '-':
			res = difference(num1,num2);
			break;
		case 'x':
			res = multiply(num1,num2);
			break;
		case '/':
			res = divide(num1,num2);
			break;
		case '%':
			res = remainder(num1,num2);
			break;
		default:
			cout << "Invalid operation";
			return 0;
	}

	cout << num1 << op << num2 << "=" << res << endl;
	return 0;
}


int sum(int a, int b)
{
	return a+b;
}

int difference(int a, int b)
{
	return a-b;
}

int multiply(int a, int b)
{
	return a*b;
}

int divide(int a, int b)
{
	return a/b;
}

int remainder(int a, int b)
{
	return a%b;
}


