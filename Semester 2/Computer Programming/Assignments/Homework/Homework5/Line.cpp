#include <iostream>
#include "Line.h"

Line::Line(int col)
{
		color = col;
		no_of_points = 2;
		shapes = 'l';
}

void Line::draw()
{
	bool mous;
	char kb;
	arr = new GP142_point [2];
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
	GP142_lineP(color,arr[0],arr[1],2);
}

void Line::redraw()
{
	GP142_lineP(color,arr[0],arr[1],2);
}

Line Line::operator = (Shape s)
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