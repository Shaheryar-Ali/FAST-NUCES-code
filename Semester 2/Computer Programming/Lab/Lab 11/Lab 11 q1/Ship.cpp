#include<iostream>
#include<string>
#include"Ship.h"

using namespace std;

Ship::Ship()
{
	name = "xxx";
	year = "1900";
}

void Ship::SetName(string n)
{
	name = n;
}

void Ship::SetYear(string y)
{
	year = y;
}

string Ship::GetName()
{
	return name;
}

string Ship::GetYear()
{
	return year;
}

void Ship::print()
{
	cout << "Ship Name: " << name << endl;
	cout << "Manufacture Year: " << year << endl;
}