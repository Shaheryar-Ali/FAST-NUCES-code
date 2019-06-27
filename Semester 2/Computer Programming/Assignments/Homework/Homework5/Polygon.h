#include "Shape.h"

#ifndef POLYGON_H
#define POLYGON_H

class polygon: public Shape
{
	public:
		polygon();
		polygon(int);
		virtual void draw();
		virtual void redraw();
		polygon operator =(Shape);
};

#endif POLYGON_H