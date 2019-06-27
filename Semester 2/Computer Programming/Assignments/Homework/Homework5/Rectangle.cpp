#include <iostream>
#include "Rectangle.h"


rectangle::rectangle(int col)
{
		color = col;
		no_of_points = 2;
		shapes = 'r';
}

void rectangle::draw()
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
	GP142_lineXY(color,arr[0].x,arr[0].y,arr[1].x,arr[0].y,2);
	GP142_lineXY(color,arr[1].x,arr[0].y,arr[1].x,arr[1].y,2);
	GP142_lineXY(color,arr[1].x,arr[1].y,arr[0].x,arr[1].y,2);
	GP142_lineXY(color,arr[0].x,arr[1].y,arr[0].x,arr[0].y,2);
}

void rectangle::redraw()
{
	GP142_lineXY(color,arr[0].x,arr[0].y,arr[1].x,arr[0].y,2);
	GP142_lineXY(color,arr[1].x,arr[0].y,arr[1].x,arr[1].y,2);
	GP142_lineXY(color,arr[1].x,arr[1].y,arr[0].x,arr[1].y,2);
	GP142_lineXY(color,arr[0].x,arr[1].y,arr[0].x,arr[0].y,2);
}

rectangle rectangle::operator = (Shape s)
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