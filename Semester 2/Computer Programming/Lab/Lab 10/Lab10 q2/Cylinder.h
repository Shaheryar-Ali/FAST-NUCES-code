#include"Circle.h"
#ifndef CYLINDER_H
#define CYLINDER_H

class Cylinder :public Circle
{
	protected:
		float height;
	public:
		Cylinder();
		double Volume();
		double area();
		void print();
};

#endif CYLINDER_H