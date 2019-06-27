#include "linked list.h"

#ifndef BLOCK_H
#define BLOCK_H

class block: list
{
	public:
		node* start_sect;
		node* end_sect;
		block(node * a, node* b);
		block();
};

#endif BLOCK_H