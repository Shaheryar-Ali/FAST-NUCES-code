#include<iostream>


#ifndef date
#define date


using namespace std;

class Date
{
private:
	int Day;
	int Month;
	int Year;

public:
	Date();
	void Input();
	void Print();
	void IndpendanceDay();
	int getday();
	int getmonth();
	int getyear();
	void setday(int);
	void setmonth(int);
	void setyear(int);

};



#endif date