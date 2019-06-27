#include<string>
#include"std_info.h"

using namespace std;

#ifndef STD_RESULT_H
#define STD_RESULT_H

class std_result:public std_info
{

private:
	float sub1;					// Marks of subject1
	float sub2;					//Marks of subject2
	float sub3;					//Marks of Subject 3
	float average;				//AverageMarks(sub1+sub2+sub3)/3 
	float total;				//Total Marks (sub1+sub2+sub3)
public:
	void input_marks(); //Input marks of students 
	void print_result(); //Printing result card

};



#endif STD_RESULT_H