#include "linked list.h"

#ifndef LIST_H
#define LIST_H



class list_it: list
{
	private:
		node* curr;
	public:
		list_it();
		node* operator ++();
		int operator *();
		bool operator != (list_it x);
};
#endif LIST_H