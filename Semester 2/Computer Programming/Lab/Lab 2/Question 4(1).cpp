#include <iostream>
using namespace std;
void main()
{
	int x = 7, y = 13, z = 11;
	int *temp;
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
	cout<<"Swapping Pointers"<<endl;
	temp = r;
	r = p;
	p= q;
	q = temp;
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