#include <iostream>
#include "Person.h"

using namespace std;

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

class Employee : public Person
{
	protected:
		int Emp_no;
		float basic_pay;
		float house_rent;
		float medical_allow;
		float conveyance_allow;
		float net_pay;
	public:
		Employee(char nam[], char a[], char nic[], int cel, int empn, float pay);
};


#endif EMPLOYEE_H
