#include "list_it.h"

list_it::list_it()
{
	curr = head;
};

node* list_it::operator++()
{
	curr = curr->next;
	return curr;
};

int list_it::operator *()
{
	return curr->data;
};

bool list_it::operator != (list_it x)
{
	if (curr == x.curr)
		return false;
	else
		return true;
};

