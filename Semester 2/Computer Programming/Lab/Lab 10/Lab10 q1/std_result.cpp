#include<iostream>
#include<string>
#include"std_info.h"
#include"std_result.h"

void std_result::input_marks()
{
	input_info();
	cout << "Enter marks of subject 1 : ";
	cin >> sub1;
	cout << "Enter marks of subject 2 : ";
	cin >> sub2;
	cout << "Enter marks of subject 3 : ";
	cin >> sub3;
	total = sub1 + sub2 + sub3;
	average = total / 3;
}

void std_result::print_result()
{
	print_info();
	cout << "Marks of subject 1 : " << sub1 <<endl;
	cout << "Marks of subject 2 : " << sub2 << endl;
	cout << "Marks of subject 3 : " << sub3 << endl;
	cout << "Average : " << average << endl;
	cout << "Total : " << total << endl;

}