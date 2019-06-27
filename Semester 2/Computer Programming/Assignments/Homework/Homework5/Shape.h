#include <iostream>
#include"GP142.H"
#include<string>
using namespace std;
#ifndef SHAPE_H
#define SHAPE_H

class Shape
{
public:
	char shapes;
	int no_of_points;
	int color;
	GP142_point *arr;
	Shape();
	virtual void draw();
	//virtual void contain() = 0;
	char retshapes();
	int retno_of_points();
	int retcolor();
	void setshapes(char);
	void setno_of_points(int);
	void setcolor(int);
	virtual void redraw();
//virtual bool contain();
	int radius;
	string text;
};




class Fill:public Shape
{
	public:
		Fill(int n)
		{
			color = n;
			no_of_points = 1;
			shapes = 'F';
		}
		void fill_c(int x, int y, int col, int pixel_c)
		{
			GP142_pixelXY(col, x, y);
			if(pixel_c == GP142_Getcolor(x + 1,y))
				fill_c(x+1,y, col, pixel_c);
			if(pixel_c == GP142_Getcolor(x - 1,y))
				fill_c(x-1,y, col, pixel_c);
			if(pixel_c == GP142_Getcolor(x,y + 1))
				fill_c(x,y+1, col, pixel_c);
			if(pixel_c == GP142_Getcolor(x + 1,y - 1))
				fill_c(x,y-1, col, pixel_c);
		}
		void Bucketfill()
		{
				int col_r;
				bool mous;
				char kb;
				arr = new GP142_point [1];

					do
					{
						mous = false;
						switch(GP142_await_event( &arr[0].x, &arr[0].y, &kb))
						{
							case GP142_MOUSE:
								if(arr[0].x<-220)
									break;
								mous = true;
								break;
							default:
								break;
						}
					}while(!mous);
					col_r=GP142_Getcolor(arr[0].x, arr[0].y);
					fill_c(arr[0].x, arr[0].y, color,col_r);
		}
};




#endif SHAPE_H
