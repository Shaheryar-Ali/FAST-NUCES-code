#include <iostream>
#include "Text.h"
#include <string>

Text::Text(int col)
{
		color = col;
		no_of_points = 1;
		shapes = 'T';
}

void Text::draw()
{   char tex[40];
	GP142_point temp;
	bool mous;
	char kb = '\0';
	int size = 0;
	arr = new GP142_point [1];
	do
	{
		mous = false;													//Body for inputting center
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

	do
	{
	switch(GP142_await_event(&temp.x, &temp.y, &kb))
	{
		case GP142_KBD:
			if(kb == '\r')
				break;
			GP142_printfXY(color, arr[0].x + size*15,arr[0].y, 15, "%c", kb);
			tex[size] = kb;
			size = size + 1;
			break;
		default:
			kb = '\r';
			break;
	}
	}while(kb != '\r');
	tex[size] = '\0';
	text = tex;
}

void Text::redraw()
{
	for(unsigned int i = 0; i < text.size(); i++)
	{
		GP142_printfXY(color, arr[0].x + i*15,arr[0].y, 15, "%c", text[i]);
	}

}

Text Text::operator = (Shape s)
{
	color = s.color;
	no_of_points = s.no_of_points;
	shapes = s.shapes;
	arr = new GP142_point [no_of_points];
	for(int i = 0; i < no_of_points; i++)
	{
		arr[i] = s.arr[i];
	}
	text = s.text;
	return *this;
}