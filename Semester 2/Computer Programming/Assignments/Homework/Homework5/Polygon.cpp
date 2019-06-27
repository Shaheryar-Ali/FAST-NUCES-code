#include<iostream>
#include"GP142.H"
#include"Polygon.h"

using namespace std;

polygon::polygon()
{

}

polygon::polygon(int col)
{
	color = col;
	shapes = 'p';				//p represents polygon
}

void polygon::draw()
{
	no_of_points = 0;
	GP142_point ars[100];
	char kb;
	bool stop = false;
	while(!stop)
	{
		GP142_await_event(&ars[no_of_points].x, &ars[no_of_points].y, &kb);
		if(GetAsyncKeyState(VK_RBUTTON))
		{
			stop = true;
			break;
		}
		else if(ars[no_of_points].x<-220)
		{
			//For ignoring this point
		}
		else if(GetAsyncKeyState(VK_LBUTTON))
		{
			if(no_of_points>0)
				GP142_lineP(color, ars[no_of_points - 1], ars[no_of_points],2);
				no_of_points = no_of_points + 1;
		}

	}

	GP142_lineP(color, ars[no_of_points -  1], ars[0], 2);

	arr = new GP142_point[no_of_points];
	for(int i = 0; i < no_of_points; i++)
	{
		arr[i] = ars[i];
	}

}

void polygon::redraw()
{
	for(int i = 1; i < no_of_points; i++)
	{
		GP142_lineP(color, arr[i - 1],arr[i], 2); 
	}
	GP142_lineP(color, arr[no_of_points -  1], arr[0], 2);
}

polygon polygon::operator = (Shape s)
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