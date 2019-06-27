#include<iostream>
#include"Shape.h"
#include"Circle.h"

using namespace std;

Shape::Shape()
{
	no_of_points = 0;
	color = 1;
	shapes = 'n';
	arr = nullptr;

}

void Shape::draw()
{

}

char Shape::retshapes()
{
	return shapes;
}

int Shape::retno_of_points()
{
	return no_of_points;
}

int Shape::retcolor()
{
	return color;
}

void Shape::setshapes(char s)
{
	shapes = s;
}

void Shape::setno_of_points(int s)
{
	no_of_points = s;
}

void Shape::setcolor(int s)
{
	color = s;
}

void Shape::redraw()
{

}
/*
bool contain()
{
	return false;
}

*/