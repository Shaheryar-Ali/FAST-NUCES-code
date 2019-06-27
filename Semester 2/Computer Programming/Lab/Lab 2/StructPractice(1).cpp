#include<iostream>
using namespace std;

struct Point
{
	short fx;
	short fy;
};

struct Rectangle
{
	short ftop;
	short fleft;
	short fwidth;
	short fheight;
};

int Equal_Points(Point p1, Point p2);
void Add_Point(Point p1, Point p2, Point& res);
Point MidPoint(Point p1, Point p2);
int ZeroRect(Rectangle r);
int Point_In_Rect(Point pt, Rectangle r);

void main()
{
	Point a,b,c,d,e;
	Rectangle r;
	cout<<"Enter x-coordinate of point 1\n";
	cin>>a.fx;
	cout<<"Enter y-coordinate of point 1\n";
	cin>>a.fy;
	cout<<"Enter x-coordinate of point 2\n";
	cin>>b.fx;
	cout<<"Enter y-coordinate of point 2\n";
	cin>>b.fy;

	r.ftop = a.fy;
	r.fleft = a.fx;
	r.fwidth = b.fx - a.fx;
	r.fheight = b.fy - a.fy;
	
	if(Equal_Points(a,b))
		cout<<"Points are equal\n";
	else
		cout<<"Points are not equal\n";
	
	Add_Point(a,b,c);
	cout<<"Sum = ("<<c.fx<<","<<c.fy<<")\n";
	
	d = MidPoint(a,b);
	cout<<"Midpoint = ("<<d.fx<<","<<d.fy<<")\n";
	
	if(ZeroRect(r))
		cout<<"No rectangle\n";

	cout<<"Enter x-coordinate of point 3\n";
	cin>>e.fx;
	cout<<"Enter y-coordinate of point 3\n";
	cin>>e.fy;

	if(Point_In_Rect(e,r))
		cout<<"Points are in rectangle\n";
	else
		cout<<"Points are not in rectangle\n";

}


int Equal_Points(Point p1, Point p2)
{
	if(p1.fx == p2.fx && p1.fy == p2.fy)
		return 1;
	else
		return 0;
}

void Add_Point(Point p1, Point p2, Point& res)
{
	res.fx = p1.fx + p2.fx;
	res.fy = p1.fy + p2.fy;
}

Point MidPoint(Point p1, Point p2)
{
	Point p3;
	p3.fx = (p2.fx+p1.fx)/2;
	p3.fy = (p2.fy+p1.fy)/2;
	return p3;
}

int ZeroRect(Rectangle r)
{
	if(r.fheight == 0 && r.fwidth == 0)
		return 1;
	else
		return false;
}

int Point_In_Rect(Point pt, Rectangle r)
{
	if(r.fwidth>0)
	{
		if(r.fheight>0)
		{
			if((pt.fx>r.fleft && pt.fy > r.ftop) && ( pt.fx<(r.fleft + r.fwidth) && pt.fy < (r.fheight + r.ftop)))
				return 1;
			else
				return 0;
		}
		else if(r.fheight<0)
			{
			if((pt.fx>r.fleft && pt.fy < r.ftop) && ( pt.fx<(r.fleft + r.fwidth) && pt.fy > (r.fheight + r.ftop)))
				return 1;
			else
				return 0;
			}
		else
			return 0;
	}

	else if(r.fwidth<0)
	{
		if(r.fheight>0)
		{
			if((pt.fx<r.fleft && pt.fy > r.ftop) && ( pt.fx>(r.fleft + r.fwidth) && pt.fy < (r.fheight + r.ftop)))
				return 1;
			else
				return 0;
		}
		else if(r.fheight<0)
			{
			if((pt.fx<r.fleft && pt.fy < r.ftop) && ( pt.fx>(r.fleft + r.fwidth) && pt.fy > (r.fheight + r.ftop)))
				return 1;
			else
				return 0;
			}
		else
			return 0;
	}
	else
		return 0;

}