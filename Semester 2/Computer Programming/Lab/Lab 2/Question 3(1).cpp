#include <iostream>
using namespace std;
void main()
{
	int x = 4, y = 7, z = 9;
	int temp;
	int *p = &x, *q = &y, *r = &z;
	cout<<" x = "<< x<< endl;
	cout<<" y = "<< y<< endl;
	cout<<" z = "<< z<< endl;
	cout<<" p = "<< p<< endl;
	cout<<" q = "<< q<< endl;
	cout<<" r = "<< r<< endl;
	cout<<" *p = "<< *p<< endl;
	cout<<" *q = "<< *q<< endl;
	cout<<" *r = "<< *r<< endl<<endl;
	cout<<"Swapping values"<<endl;
	temp = z;
	z= x;
	x = y;
	y = temp;
	cout<<" x = "<< x<< endl;
	cout<<" y = "<< y<< endl;
	cout<<" z = "<< z<< endl;
	cout<<" p = "<< p<< endl;
	cout<<" q = "<< q<< endl;
	cout<<" r = "<< r<< endl;
	cout<<" *p = "<< *p<< endl;
	cout<<" *q = "<< *q<< endl;
	cout<<" *r = "<< *r<< endl;
}
