#include <string>
#include <iostream>

using namespace std;

#ifndef SHIP_H
#define SHIP_H

class Ship
{
	protected:
		string name;
		string year;
	public:
		Ship();
		void SetName(string n);
		void SetYear(string y);
		string GetName();
		string GetYear();
		virtual void print();
};


#endif SHIP_H