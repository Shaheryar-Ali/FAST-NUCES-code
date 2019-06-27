#include<iostream>
#include"Circle.h"
#include"Point.h"

using namespace std;

Circle::Circle()
{
	cout << "Enter radius : ";
	cin >> radius;
}

double Circle::area()
{
	return 3.14*radius*radius;
}

void Circle::print()
{
	cout << "Radius : " << radius <<endl;
	cout << "Area : " << 3.14*radius*radius << endl << endl;
}

