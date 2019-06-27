#ifndef POINT_H
#define POINT_H
#include <iostream>
using namespace std;
class Point{
private:
	int x; 
	int y;
public:
	Point(int = 0, int = 0);
	void setPoint(int, int);
	void GetPoint(int&, int&);
 virtual   void print();
};
#endif POINT_H
