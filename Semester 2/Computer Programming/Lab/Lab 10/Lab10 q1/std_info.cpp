#include<iostream>
#include<string>
#include"std_info.h"

void std_info::input_info()
{
	cout << "Enter reg no. = ";
	cin >> reg_no;
	cout << "Enter Name : ";
	cin >> name;
	cout << "Enter Address : ";
	cin >> address;
}

void std_info::print_info()
{
	cout << "Reg no. : " << reg_no << endl;
	cout << "Enter Name : " << name <<endl;
	cout << "Enter Address : " << address <<endl;
}