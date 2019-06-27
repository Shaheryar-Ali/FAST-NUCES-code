#include <string>
#include <iostream>
#include "Ship.h"

using namespace std;

#ifndef CARGOSHIP_H
#define CARGOSHIP_H

class CargoShip : public Ship
{
private:
	int capacity;
public:
	CargoShip();
	void SetCapacity(int n);
	int GetCapacity();
	void print();
};



#endif CARGOSHIP_H