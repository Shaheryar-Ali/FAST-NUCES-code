#include <iostream>
#include "Board.h"

using namespace std;

Board::Board(int n)
{
	size = n;			//nxn size of array
	row = 0;			//current row
	sol = new int[n];	//array for storing column

}

void Board::Push(int n)
{
	if(!IsFull())
	{
		sol[row] = n;
		row++;
	}
}

bool Board::IsFull()
{
	if (row == size)
		return true;
	else
		return false;
}

bool Board::check(int col)
{
	for (int prev_rows = row - 1; prev_rows >= 0; --prev_rows)			//prev_rows stands for rows before current rows.
	{
		if (col == sol[prev_rows] || sol[prev_rows] == col + (row - prev_rows) || sol[prev_rows] == col - (row - prev_rows))
			return true;
	}
	return false;							//In case its not found
}

void Board::Pop(int &n)
{
	if(!IsEmpty())
	{
		--row;
		n = sol[row];
	}
}

bool Board::IsEmpty()
{
	if (row == 0)
		return true;
	else
		return false;
}

int Board::getrow()
{
	return row;
}

void Board::Top(int &d)
{
	d = sol[0];
}

void Board::refill(int &n)
{
	row = size - 1;
	n = sol[row];
}

