#include"Point.h"

#ifndef CIRCLE_H
#define CIRCLE_H

class Circle:public Point
{
protected:
	float radius;
public:
	Circle();
virtual	double area();
virtual	void print();

};

#endif CIRCLE_H