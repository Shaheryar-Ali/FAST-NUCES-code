#include"Point.h"
#include<iostream>

using namespace std;

Point::Point(int a, int b)
{
	x = a;
	y = b;
}

void Point::setPoint(int a, int b)
{
	x = a;
	y = b;
}

void Point::GetPoint(int &a, int &b)
{
	a = x;
	b = y;
}

void Point::print()
{
	cout << "\nx_point : " << x << endl;
	cout << "y_point : " << y << endl <<endl;
}