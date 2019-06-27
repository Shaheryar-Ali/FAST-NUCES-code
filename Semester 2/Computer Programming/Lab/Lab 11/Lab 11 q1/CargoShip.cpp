#include <string>
#include <iostream>
#include"CargoShip.h"

using namespace std;

CargoShip::CargoShip()
{
	capacity = 0;
}

void CargoShip::SetCapacity(int n)
{
	capacity = n;
}

int CargoShip::GetCapacity()
{
	return capacity;
}

void CargoShip::print()
{
	cout << "Ship Name: " << name << endl;
	cout << "Capacity in Tonnage : " << capacity << endl;
}