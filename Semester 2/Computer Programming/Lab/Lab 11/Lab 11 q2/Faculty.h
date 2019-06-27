#include<iostream>
#include<string>
#include"Employee.h"

using namespace std;

#ifndef FACULTY_H
#define FACULTY_H

class Faculty : public Employee
{
	protected:
		string designation;
		string department;
		string course;
	public:
		Faculty(char nam[], char a[], char nic[], int cel, int empn, float pay, char desig[], char dep[], char cors[]);
};


#endif FACULTY_H