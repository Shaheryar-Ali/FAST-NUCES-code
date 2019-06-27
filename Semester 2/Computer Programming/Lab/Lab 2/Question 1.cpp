#include <iostream>
using namespace std;
void main()
{
	int x = 2, y = 8;
	int *p, *q;
	p = &x;
	q = &y;
	cout<< "Address of x = " << &x << ", and value of x = " << x <<endl;
	cout<< "Value of p = " << p << ", and value of *p = " << *p<<endl;
	cout<< "Address of y = " << &y << ", and value of y = " << y<<endl;
	cout<< "Value of q = " << q << ", and value of *q = " << *q<<endl;
	cout << "Address of p = " <<&p<<endl;
	cout << "Address of q = " <<&q<<endl;
}