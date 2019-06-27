#include<string>

using namespace std;

#ifndef STD_INFO_H
#define STD_INFO_H

class std_info{
protected:
	int reg_no;							//To store registration# of student 
	string name;						// To store name of student
	string address;						// To store address of student
public:
	void input_info();					//Function to input info 
	void print_info ();					//Function to print info
};


#endif STD_INFO_H