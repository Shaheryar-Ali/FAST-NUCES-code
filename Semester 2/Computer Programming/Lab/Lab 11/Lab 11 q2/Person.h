#include<iostream>
#include<string>

using namespace std;

#ifndef PERSON_H
#define PERSON_H

class Person
{
	protected:
		string name;
		string address;
		string nic_no;
		int cel_no;
	public:
		Person(char nam[], char a[], char nic[], int cel);

};


#endif PERSON_H