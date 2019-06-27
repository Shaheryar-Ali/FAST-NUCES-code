#include "Open_shape.h"

#ifndef CURVE_H
#define CURVE_H

class curve: public Open_shape
{
	public:
		curve(int);
		void draw();
		void redraw();
		curve operator =(Shape);
};

#endif CURVE_H