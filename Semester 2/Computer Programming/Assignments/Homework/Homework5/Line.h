#include "Open_shape.h"

#ifndef LINE_H
#define LINE_H

class Line: public Open_shape
{
public:
	Line(int);
	void draw();
	void redraw();
	Line operator =(Shape);
};

#endif LINE_H