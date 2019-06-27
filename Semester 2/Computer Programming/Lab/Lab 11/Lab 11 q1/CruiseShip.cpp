#include <string>
#include <iostream>
#include"CruiseShip.h"

using namespace std;

CruiseShip::CruiseShip()
{
	capacity = 0;
}

void CruiseShip::SetCapacity(int n)
{
	capacity = n;
}

int CruiseShip::GetCapacity()
{
	return capacity;
}

void CruiseShip::print()
{
	cout << "Ship Name: " << name << endl;
	cout << "Capacity : " << capacity << endl;
}

