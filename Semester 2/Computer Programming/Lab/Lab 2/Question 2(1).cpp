#include <iostream>
using namespace std;
void main()
{
	int x, y, sum;
	int *xPtr, *yPtr, *sumPtr;
	xPtr = &x;
	yPtr = &y;
	sumPtr = &sum;
	cout << "Enter two numbers = ";
	cin>> *xPtr >> *yPtr;
	*sumPtr = *xPtr + *yPtr;
	cout << " Sum = "<< *sumPtr<<endl;
}
