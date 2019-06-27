#include <string>
#include <iostream>
#include "Ship.h"

using namespace std;

#ifndef CRUISESHIP_H
#define CRUISESHIP_H

class CruiseShip : public Ship
{
	private:
		int capacity;
	public:
		CruiseShip();
		void SetCapacity(int n);
		int GetCapacity();
		void print();
};



#endif CRUISESHIP_H