#include "Shape.h"

#ifndef OPEN_SHAPE_H
#define OPEN_SHAPE_H

class Open_shape: public Shape
{
	//virtual void contain() = 0;
	virtual void draw() = 0;
	void changeColor(int col);
	virtual void redraw() = 0;
};

#endif OPEN_SHAPE_H