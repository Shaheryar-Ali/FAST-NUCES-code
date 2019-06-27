#include <iostream>
#include "Triangle.h"


triangle::triangle(int col)
{
		color = col;
		no_of_points = 3;
		shapes = 't';
}

void triangle::draw()
{
	bool mous;
	char kb;
	arr = new GP142_point [3];
	for(int i = 0; i < no_of_points; i++)
	{
		do
		{
			mous = false;
			switch(GP142_await_event( &arr[i].x, &arr[i].y, &kb))
			{
				case GP142_MOUSE:
					if(arr[i].x<-220)
						break;
					mous = true;
					break;
				default:
					break;
			}
		}while(!mous);
	}
	GP142_lineP(color,arr[0], arr[1], 2);
	GP142_lineP(color,arr[1], arr[2], 2);
	GP142_lineP(color,arr[2], arr[0], 2);
}

void triangle::redraw()
{
	GP142_lineP(color,arr[0],arr[1],2);
	GP142_lineP(color,arr[1],arr[2],2);
	GP142_lineP(color,arr[2],arr[0],2);
}

triangle triangle::operator = (Shape s)
{
	color = s.color;
	no_of_points = s.no_of_points;
	shapes = s.shapes;
	arr = new GP142_point [no_of_points];
	for(int i = 0; i < no_of_points; i++)
	{
		arr[i] = s.arr[i];
	}
	return *this;
}