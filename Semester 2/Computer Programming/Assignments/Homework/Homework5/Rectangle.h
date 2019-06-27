#include "Polygon.h"

#ifndef RECTANGLE_H
#define RECTANGLE_H

class rectangle: public polygon
{
	public:
		rectangle(int);
		void draw();
		void redraw();
		rectangle operator =(Shape);
};

#endif RECTANGLE_H