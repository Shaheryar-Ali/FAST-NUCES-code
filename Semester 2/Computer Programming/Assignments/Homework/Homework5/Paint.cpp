#include<iostream>
#include<fstream>
#include<stdio.h>
#include"GP142.h"
#include"GP142LIB.H"
#include"Shape.h"
#include "Open_shape.h"
#include "Circle.h"
#include "Polygon.h"
#include "curve.h"
#include "Line.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Text.h"
#include<Windows.h>


#pragma comment(linker, "/STACK:429496720")

using namespace std;


void interfac(int col, char shap);
void set_col(int *col,int x,int y);
void shape_sel(int x, int y, char *shap);
Shape canvas(int col, char shapes);
Shape* extend( Shape *a,int * size);
Shape* contract( Shape *a, int cur, int *size);
void save(int size, Shape *store);
bool start();
Shape* loading(int* size);


void main()
{	
	
	Shape *allShapes;				//Array of shapes	
	bool quit = false;								//Quit
	int mouse_x, mouse_y;							//Returns co ordinates of mouse click
	char key;
	int size = 1, entry = 0;
	bool load;
	int color = 1;
	char shapes = 'n';								//'n' represents none

	allShapes = new Shape [size];
	GP142_open();									//Opens Graphic window
	
	load=start();

	GP142_clear();
	interfac(color, shapes);						//Displays menu
	if(load)
	{
		allShapes=loading(&size);
		entry = size - 1;
	}

	while(!quit)
	{
		switch(GP142_await_event(&mouse_x,&mouse_y, &key))
		{
			case GP142_QUIT:
				quit = true;
				break;
			case GP142_MOUSE:
				{
					set_col(&color,mouse_x,mouse_y);
					shapes = 'n';
					shape_sel(mouse_x, mouse_y, &shapes);
					
					interfac(color, shapes);
					if (shapes != 'n' && shapes != 's')
					{
						allShapes[entry] = canvas(color,shapes);
						entry = entry + 1;
						if(entry >= size)
							allShapes = extend(allShapes, &size);
					}
					else if(shapes == 's')
					{
						save(entry, allShapes);
						Sleep(250);
						shapes = 'n';
						interfac(color,shapes);
					}
				}
				break;
			default:
				break;
		}
	}
	
	GP142_close();

	delete []allShapes;				//Readd this after creating load function
}

void interfac(int col, char shap)
{
	GP142_rectangleXY(22, -300, 250, -210, -250,0);

	GP142_rectangleXY(0, -280, 220, -260, 200,0);
	GP142_rectangleXY(1, -250, 220, -230, 200,0);

	GP142_rectangleXY(2, -280, 190, -260, 170,0);
	GP142_rectangleXY(3, -250, 190, -230, 170,0);

	GP142_rectangleXY(4, -280, 160, -260, 140,0);
	GP142_rectangleXY(5, -250, 160, -230, 140,0);

	GP142_rectangleXY(6, -280, 130, -260, 110,0);
	GP142_rectangleXY(7, -250, 130, -230, 110,0);

	GP142_rectangleXY(8, -280, 100, -260, 80,0);
	GP142_rectangleXY(9, -250, 100, -230, 80,0);

	GP142_rectangleXY(13, -280, 70, -260, 50,0);
	GP142_rectangleXY(14, -250, 70, -230, 50,0);

	GP142_rectangleXY(15, -280, 40, -260, 20,0);
	GP142_rectangleXY(19, -250, 40, -230, 20,0);
	
	GP142_rectangleXY(col, -285, 10, -225, -25,0);				//For displaying selected color

	if(shap!='l')
		GP142_rectangleXY(1, -285, -35, -260, -60, 0);			//Makes the non selected line button appear white else gray

	GP142_rectangleXY(0, -285, -35, -260, -60, 1);				//Next 2 lines display line icon
	GP142_lineXY(BLACK, -282, -57, -262, -37, 2);

	if(shap!='a')
		GP142_rectangleXY(1, -250, -35, -225, -60, 0);			//Makes the non selected curve button appear white else gray

	GP142_rectangleXY(0, -250, -35, -225, -60, 1);				//Next 4 lines display curve icon
	GP142_lineXY(0, -245, -40, -235, -40, 2);
	GP142_lineXY(0, -235, -40, -230, -45, 2);
	GP142_lineXY(0, -230, -45, -230, -55, 2);

	if(shap!='p')
		GP142_rectangleXY(1, -285, -70, -260, -95, 0);			//Makes the non selected polygon button appear white else gray

	GP142_rectangleXY(0, -285, -70, -260, -95, 1);				//Next 6 lines display polygon icon
	GP142_lineXY(0, -279, -73, -266, -73, 1);
	GP142_lineXY(0, -279, -73, -283, -82, 1);
	GP142_lineXY(0, -266, -73, -262, -82, 1);
	GP142_lineXY(0, -279, -92, -266, -92, 1);
	GP142_lineXY(0, -283, -82, -279, -92, 1);
	GP142_lineXY(0, -262, -82, -266, -92, 1);

	if(shap!='r')
		GP142_rectangleXY(1, -250, -70, -225, -95, 0);

	GP142_rectangleXY(0, -250, -70, -225, -95, 1);				//For making Rectangle icon
	GP142_rectangleXY(0, -245, -77, -230, -87, 2);

	if(shap!='t')
		GP142_rectangleXY(1, -285, -105, -260, -130, 0);		//For Making triangle icon
	GP142_rectangleXY(0, -285, -105, -260, -130, 1);
	GP142_triangleXY(0, -280, -125, -265, -125, -273, -110, 2);

	if(shap!='c')
		GP142_rectangleXY(1, -250, -105, -225, -130, 0);		//For Making circle icon

	GP142_rectangleXY(0, -250, -105, -225, -130, 1);
	GP142_circleXY(0, -238, -118, 8, 2);

	if(shap!='T')
		GP142_rectangleXY(1, -285, -140, -260, -165, 0);		//For Making text icon
	GP142_rectangleXY(0, -285, -140, -260, -165, 1);
	GP142_printfXY( 0, -278, -165, 20, "%c" , 'A');
	
	if(shap!='F')
		GP142_rectangleXY(1, -250, -140, -225, -165, 0);		
	GP142_rectangleXY(0, -250, -140, -225, -165, 1);
	GP142_printfXY( 0, -245, -165, 20, "%c" , 'F');

	if(shap!='E')
		GP142_rectangleXY(1, -285, -175, -260, -200, 0);		
	GP142_rectangleXY(0, -285, -175, -260, -200, 1);
	GP142_printfXY( 0, -278, -200, 20, "%c" , 'E');


	if(shap!='s')												//For save
		GP142_rectangleXY(1, -250, -175, -225, -200, 0);		
	GP142_rectangleXY(0, -250, -175, -225, -200, 1);
	GP142_printfXY( 0, -245, -200, 20, "%c" , 'S');
	
}

void set_col(int *col, int x, int y)
{
	if(x>=-280 && x <= -260)
	{
		if(220>=y && y >= 200)
			*col = 0;
		else if(190>=y && y >= 170)
			*col = 2;
		else if(160>=y && y >= 140)
			*col = 4;
		else if(130>=y && y >= 110)
			*col = 6;
		else if(100>=y && y >= 80)
			*col = 8;
		else if(70>=y && y >= 50)
			*col = 13;
		else if(40>=y && y >= 10)
			*col = 15;
	}
	else if(x>=-250 && x <= -230)
	{
		if(220>=y && y >= 200)
			*col = 1;
		else if(190>=y && y >= 170)
			*col = 3;
		else if(160>=y && y >= 140)
			*col = 5;
		else if(130>=y && y >= 110)
			*col = 7;
		else if(100>=y && y >= 80)
			*col = 9;
		else if(70>=y && y >= 50)
			*col = 14;
		else if(40>=y && y >= 10)
			*col = 19;
	}
}

void shape_sel(int x, int y, char *shap)
{
	if(x>=-285 && x <= -260)
	{
		if(y>= -60 && y <= -35)
		{
			*shap = 'l';
		}
		else if(y>= -95 && y <= -70)
		{
			*shap = 'p';
		}
		else if(y>= -130 && y <= -105)
		{
			*shap = 't';
		}
		else if(y >= -165 && y <= -140)
		{
			*shap = 'T';
		}

		else if(y >= -200 && y <=-175)
		{
			*shap = 'E';
		}
	}
	else if(x>= -250 && x <= -225)
	{
		if(y>= -60 && y <= -35)
		{
			*shap = 'a';
		}
		else if(y>= -95 && y <= -70)
		{
			*shap = 'r';
		}
		else if(y>= -130 && y <= -105)
		{
			*shap = 'c';					//c represents circle
		}

		else if(y >= -165 && y <= -140)
		{
			*shap = 'F';
		}

		else if(y >= -200 && y <=-175)
		{
			*shap = 's';
		}
	}

	else
		*shap = 'n';
}

Shape canvas(int col, char shapes)
{
	if(shapes == 'l')
	{
		Line l(col);
		l.draw();
		GP142_rectangleXY(1, -285, -35, -260, -60, 0);			//Restoring line button
		GP142_rectangleXY(0, -285, -35, -260, -60, 1);				
		GP142_lineXY(BLACK, -282, -57, -262, -37, 2);
		return l;
	}
	else if(shapes == 'a')
	{
		curve a(col);
		a.draw();

		GP142_rectangleXY(1, -250, -35, -225, -60, 0);			//Makes the non selected curve button appear white else gray

		GP142_rectangleXY(0, -250, -35, -225, -60, 1);				//Next 4 lines display curve icon
		GP142_lineXY(0, -245, -40, -235, -40, 2);
		GP142_lineXY(0, -235, -40, -230, -45, 2);
		GP142_lineXY(0, -230, -45, -230, -55, 2);

		return a;
	}
	else if(shapes == 'p')
	{
		polygon p(col);
		p.draw();
		GP142_rectangleXY(1, -285, -70, -260, -95, 0);			//Makes the non selected polygon button appear white else gray

		GP142_rectangleXY(0, -285, -70, -260, -95, 1);				//Next 6 lines display polygon icon
		GP142_lineXY(0, -279, -73, -266, -73, 1);
		GP142_lineXY(0, -279, -73, -283, -82, 1);
		GP142_lineXY(0, -266, -73, -262, -82, 1);
		GP142_lineXY(0, -279, -92, -266, -92, 1);
		GP142_lineXY(0, -283, -82, -279, -92, 1);
		GP142_lineXY(0, -262, -82, -266, -92, 1);

		return p;
	}
	else if(shapes == 'r')
	{
		rectangle r(col);
		r.draw();

		GP142_rectangleXY(1, -250, -70, -225, -95, 0);
		GP142_rectangleXY(0, -250, -70, -225, -95, 1);
		GP142_rectangleXY(0, -245, -77, -230, -87, 2);

		return r;
	}
	else if(shapes == 't')
	{
		triangle t(col);
		t.draw();

		GP142_rectangleXY(1, -285, -105, -260, -130, 0);		//For Making triangle icon
		GP142_rectangleXY(0, -285, -105, -260, -130, 1);
		GP142_triangleXY(0, -280, -125, -265, -125, -273, -110, 2);

		return t;
	}
	else if(shapes == 'c')
	{
		Circle c(col);
		c.draw();

		GP142_rectangleXY(1, -250, -105, -225, -130, 0);		//For Making circle icon
		GP142_rectangleXY(0, -250, -105, -225, -130, 1);
		GP142_circleXY(0, -238, -118, 8, 2);
		return c;
	}
	else if(shapes == 'T')
	{
		Text sent(col);
		sent.draw();
		GP142_rectangleXY(1, -285, -140, -260, -165, 0);		//For Making text icon
		GP142_rectangleXY(0, -285, -140, -260, -165, 1);
		GP142_printfXY( 0, -278, -165, 20, "%c" , 'A');
		return sent;
	}
	else if(shapes == 'F')
	{
		Fill F(col);
		F.Bucketfill();
		GP142_rectangleXY(1, -250, -140, -225, -165, 0);		
		GP142_rectangleXY(0, -250, -140, -225, -165, 1);
		GP142_printfXY( 0, -245, -165, 20, "%c" , 'F');

		return F;
	}
	else
	{
		Shape n;
		return n;
	}
}

Shape* extend(Shape* a, int *size)
{
	Shape *b = new Shape [*size * 2];
	for(int i = 0; i < *size ; i++)
	{
		b[i] = a[i];
	}
	*size = *size * 2;
	delete []a;
	return b;
}

void save(int size, Shape *store)
{
	ofstream shap("drawing.pb");
	shap<<size<<endl;
	for(int n = 0; n<size; n++)
	{
			shap<<store[n].retshapes()<<endl;
			shap<<store[n].retcolor()<<endl;
			shap<<store[n].retno_of_points()<<endl;
			for(int i = 0; i < store[n].retno_of_points(); i++)
			{
				shap << store[n].arr[i].x << " " << store[n].arr[i].y << " ";  
			}
			shap<<endl;
			if (store[n].retshapes() == 'c')
			{
				shap<<store[n].radius<<endl;
			}
			if (store[n].retshapes() == 'T')
			{
				shap<<store[n].text<<endl;
			}


	}
	shap.close();
}

bool start()
{
	int x, y;
	char kb;
	GP142_rectangleXY(RED, -300, 250, 0, -250, 0);
	GP142_printfXY( BLUE, -280, -50, 175, "%c", 'L');
	GP142_rectangleXY(BLUE, 300, 250, 0, -250, 0);
	GP142_printfXY( RED, 20, -50, 175, "%c",'N');
	GP142_await_event(&x,&y,&kb);
	if(x<0)
		return true;
	else
		return false;


}

Shape* loading(int *size)
{
	Shape *store;
	int temp_col, temp_nop;
	char temp_char;
	ifstream load("drawing.pb");
	load>>*size;
	*size = *size+1;
	store = new Shape [*size];				//To make sure there is space for atleast 1 more input in main
	for(int i = 0; i < *size-1; i++)
	{
		load>>temp_char;
		load>>temp_col;
		if(temp_char == 'l')
		{
			Line l(temp_col);
			load>>temp_nop;
			l.arr = new GP142_point [temp_nop];
			for(int j = 0; j < temp_nop; j++)
			{
				load>>l.arr[j].x;
				load>>l.arr[j].y;
			}
			l.redraw();
			store[i] = l;

		}
		else if(temp_char == 'a')
		{
			curve a(temp_col);
			load>>temp_nop;
			a.arr = new GP142_point [temp_nop];
			a.setno_of_points(temp_nop);
			for(int j = 0; j < temp_nop; j++)
			{
				load>>a.arr[j].x;
				load>>a.arr[j].y;
			}
			a.redraw();
			store[i] = a;
		}
		else if(temp_char == 'p')
		{
			polygon p(temp_col);
			load>>temp_nop;
			p.arr = new GP142_point [temp_nop];
			p.setno_of_points(temp_nop);
			for(int j = 0; j < temp_nop; j++)
			{
				load>>p.arr[j].x;
				load>>p.arr[j].y;
			}
			p.redraw();
			store[i] = p;
		}
		else if(temp_char == 'r')
		{
			rectangle r(temp_col);
			load>>temp_nop;
			r.arr = new GP142_point [temp_nop];
			for(int j = 0; j < temp_nop; j++)
			{
				load>>r.arr[j].x;
				load>>r.arr[j].y;
			}
			r.redraw();
			store[i] = r;
		}
		else if(temp_char == 't')
		{
			triangle t(temp_col);
			load>>temp_nop;
			t.arr = new GP142_point [temp_nop];
			for(int j = 0; j < temp_nop; j++)
			{
				load>>t.arr[j].x;
				load>>t.arr[j].y;
			}
			t.redraw();
			store[i] = t;
		}
		else if(temp_char == 'c')
		{
			Circle c(temp_col);
			load>>temp_nop;
			c.arr = new GP142_point [temp_nop];
			load>>c.arr[0].x;
			load>>c.arr[0].y;
			load>>c.radius;
			c.redraw();
			store[i] = c;
		}
		else if(temp_char == 'T')
		{
			Text t(temp_col);
			load>>temp_nop;
			t.arr = new GP142_point [temp_nop];
			load>>t.arr[0].x;
			load>>t.arr[0].y;
			load>>t.text;
			t.redraw();
			store[i] = t;

		}
		else if(temp_char == 'F')
		{
			int col;
			Fill f(temp_col);
			load>>temp_nop;
			f.arr = new GP142_point [temp_nop];
			load>>f.arr[0].x;
			load>>f.arr[0].y;
			col = GP142_Getcolor(f.arr[0].x,f.arr[0].y); 
			f.fill_c(f.arr[0].x,f.arr[0].y, temp_col, col );
			store[i] = f;
		}
	}
	load.close();
	return store;
}