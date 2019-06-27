#include "Shape.h"

#ifndef CIRCLE_H
#define CIRCLE_H

class Circle: public Shape
{
	public:
	Circle(int);
	void draw();
	int retradius();
	void redraw();
	Circle operator =(Shape);
	bool contain(int x, int y);
};

#endif CIRCLE_H