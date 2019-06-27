#include<iostream>
#include"Point.h"
#include"Circle.h"
#include"Cylinder.h"

using namespace std;

Cylinder::Cylinder()
{
	cout << "Enter Height : ";
	cin >> height;
}

double Cylinder::Volume()
{
	return 3.14*radius*radius*height;
}

double Cylinder::area()
{
	return (2 * (3.14*radius*radius) + 2 * (3.14*radius*height));
}

void Cylinder::print()
{
	cout << "\nRadius : " << radius;
	cout << "\nHeight : " << height;
	cout << "\nVolume : " << 3.14*radius*radius*height;
	cout << "\nSurface Area : " << (2 * (3.14*radius*radius) + 2 * (3.14*radius*height)) << endl;


}