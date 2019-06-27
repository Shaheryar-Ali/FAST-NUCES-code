#include<iostream>
#include"Circle.h"
#include"Point.h"
#include"Cylinder.h"
#include<conio.h>

using namespace std;

void main()
{
	int x, y;
	Point a;
	a.setPoint(2, 3);
	a.GetPoint(x, y);
	cout << "\n Returned values x and y " << x <<" "<< y <<endl;
	a.print();
	_getch();

	Circle b;
	float area = b.area();
	cout << "Returned Area = " << area <<endl;
	b.print();
	_getch();

	Cylinder c;
	float vol, sur;
	vol = c.Volume();
	sur = c.area();
	cout << "Returned Volume = " << vol << endl;
	cout << "Returned Surface Area = " << sur << endl << endl;
	c.print();
}