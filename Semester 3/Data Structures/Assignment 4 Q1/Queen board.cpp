#include <iostream>
#include "Board.h"

#pragma comment(linker, "/STACK:429496720")

using namespace std;

void NQueen(Board queen, int row, int col);			//returns column of last row
void Print_queen(Board queen);


void main()
{
	int d;				//d is for input
	int y = 0;					//y is row 
	int c = 1;

	cout << "Enter the no. of rows in chess board = ";
	cin >> d;
	if (d < 4)					//To save resources by not running code in case of no output
	{
		if (d == 1)
			cout << "( 1 , 1 )";
		else
			cout << "No combination exists";
	}
	else
	{
		cout << "The available combinations are \n\n";
		Board q(d);				//Makes the board
		NQueen(q, y, c);
	}
}

void NQueen(Board queen, int row, int col)
{
	int y;							//Here y for printing variable

	if (queen.IsFull())
	{
		Print_queen(queen);
		queen.Pop(y);
		NQueen(queen, queen.getrow(), y+ 1);
	}
	else
	{
		if(col > queen.getsize())							//Runs in case no appropriate location for queen was found
		{
			queen.Pop(col);				//In case its already row one, col wont be modified
			if (queen.IsEmpty())		//In case we are modifying queen ot of row 1
			{
				queen.Top(col);
				if (col >= queen.getsize())			//Indicates that queen is already in last column so no condition is further possible							
					return;
			}
				row = queen.getrow();
				NQueen(queen, row, col + 1);		//Even if col exceeds it really doesnt matter as we will keep popping it
		}

		else if (!queen.check(col))		//passing column. This condition checks if we can place queen or not. It returns false if we can place queen there
		{
			queen.Push(col);
			col = 1;
			NQueen(queen, row + 1, col);
		}
		else
		{
			NQueen(queen, row, col + 1);
		}
		

	}
}


void Print_queen(Board queen)
{
	int y;
	while (!queen.IsEmpty())
	{
		cout << "( " << queen.getrow();
		queen.Pop(y);
		cout << " , " << y << " )";
	}
	cout << endl << endl;
}