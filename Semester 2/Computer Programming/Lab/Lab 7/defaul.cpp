#include<iostream>
#include"date.h"

using namespace std;


Date::Date()
{
	cout << "Default Constructor Called\n";
	Day = 1;
	Month = 1;
	Year = 1926;
}

void Date::Input()
{
	cout << "Overloaded Function called\n";
	cout << "Enter day";
	cin >> Day;
	cout << " Enter month";
	cin >> Month;
	cout << "Enter Year";
	cin >> Year;

}

void Date::Print()
{
	if (Day == 14 && Month == 8)
		cout << " Independence Day : ";
	cout << Day << "/" << Month << "/" << Year;
}


void Date::IndpendanceDay()
{
	Day = 14;
	Month = 8;
	Year = 2016;
}

int Date::getday()
{
	return Day;
}

int Date::getmonth()
{
	return Month;
}

int Date::getyear()
{
	return Year;
}

void Date::setday(int x)
{
	Day = x;
}

void Date::setmonth(int x)
{
	Month = x;
}

void Date::setyear(int x)
{
	Year = x;
}