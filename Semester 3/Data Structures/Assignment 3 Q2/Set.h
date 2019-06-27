#pragma once
#include "Queue.h"

class Set
{
	private:
		int size_of_set;
		int *array;
		int index;
	public:
		Set();
		Set(int);
		void add(int x);
		void remove();
		int getlast();
		int *extend(int* a);
		Set operator = (Set &n);
		void print();
		void allSubset(int);
	//	Set(const Set &obj);
};