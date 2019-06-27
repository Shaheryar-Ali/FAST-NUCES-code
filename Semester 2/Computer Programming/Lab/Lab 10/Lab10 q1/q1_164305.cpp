#include<iostream>
#include<string>
#include"std_info.h"
#include"std_result.h"
#include<conio.h>

void main()
{
	std_result a;
	a.input_marks();
	_getch();
	cout << endl << endl;
	a.print_result();

}