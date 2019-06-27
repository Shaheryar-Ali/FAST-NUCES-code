#include <iostream>
#include "Circle.h"
#include "GP142.H"
#include <math.h>

Circle::Circle(int col)
{
		color = col;
		no_of_points = 1;
		shapes = 'c';
}

void Circle::draw()
{
	double x2, y2;
	GP142_point temp;
	bool mous;
	char kb;
	arr = new GP142_point [1];
	do
	{
		mous = false;													//Body for inputting center
		switch(GP142_await_event( &arr[0].x, &arr[0].y, &kb))
		{
			case GP142_MOUSE:
				if(arr[0].x<-210)
					break;
				mous = true;
				break;
			default:
				break;
		}
	}while(!mous);


	do
	{
		mous = false;												//for point determining radius
		switch(GP142_await_event( &temp.x, &temp.y, &kb))
		{
			case GP142_MOUSE:
				if(temp.x<-220)
					break;
				mous = true;
				break;
			default:
				break;
		}
		x2 = (temp.x - arr[0].x) * (temp.x - arr[0].x);
		y2 = (temp.y - arr[0].y) * (temp.y - arr[0].y);
		radius = sqrt(x2+y2);
		if(arr[0].x - radius < -210)
			mous = false;
	}while(!mous);
	GP142_circleP(color, arr[0], radius, 2);			//Modified circle function
}

int Circle::retradius()
{
	return radius;
}

void Circle::redraw()
{
	GP142_circleP(color, arr[0], radius, 2);
}

Circle Circle::operator = (Shape s)
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
	radius = s.radius;
}

bool Circle::contain(int x, int y)
{
	int dist;
	double x2, y2;
	x2 = (x-arr[0].x) * (x-arr[0].x);
	y2 = (y-arr[0].y) * (y-arr[0].y);
	dist = sqrt(x2+y2);
	if(dist<radius)
		return true;
	else
		return false;
}