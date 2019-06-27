#include <iostream>
#include <string>
#include "Faculty.h"

using namespace std;

Faculty::Faculty(char nam[], char a[], char nic[], int cel, int empn, float pay, char desig[], char dep[], char cors[]) : Employee (nam,a,nic,cel,empn,pay)
{
	designation = desig;
	department = dep;
	course = cors;
}

