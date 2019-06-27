#include "Polygon.h"

#ifndef TRIANGLE_H
#define TRIANGLE_H

class triangle: public polygon
{
	public:
		triangle(int);
		void draw();
		void redraw();
		triangle operator =(Shape);
};

#endif TRIANGLE_H