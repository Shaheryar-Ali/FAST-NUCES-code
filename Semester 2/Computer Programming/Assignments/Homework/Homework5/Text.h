#include"Shape.h"
#include<string>

#ifndef TEXT_H
#define TEXT_H

class Text:public Shape
{

	public:
		Text(int);
		void draw();
		void redraw();
		Text operator =(Shape);
};

#endif TEXT_H