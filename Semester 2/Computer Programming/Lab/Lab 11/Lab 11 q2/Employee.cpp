#include <iostream>
#include "Employee.h"

using namespace std;

Employee::Employee(char nam[], char a[], char nic[], int cel, int empn, float pay) : Person(nam,a,nic,cel)
{
	Emp_no = empn;
	basic_pay = pay;
	house_rent = pay * 45 / 100;
	medical_allow = pay * 5 / 100;
	conveyance_allow = pay * 10 / 100;
	net_pay = basic_pay + house_rent + medical_allow + conveyance_allow;

}