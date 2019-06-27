#include "linked list.h"
#include "block.h"
#include <string>

using namespace std;

#ifndef FILE_H
#define FILE_H

struct block_l
{
	block data;
	block_l* next;

};
class file: block
{
	private:
		file();
		string name;
		int size;
		block_l *headb;

};

#endif FILE_H