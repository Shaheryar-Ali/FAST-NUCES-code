#include <iostream>
#include "Board.h"

using namespace std;

void PrintQ(Board queen);
int NQueen(Board queen, int size, int row, int col);			//returns column of last row

void main()
{
	int d;				//d is for input
	int y = 0;					//y is row 
	int c = 1;
	int top = 1;				//for storing current column of top queen in row 1
	int cmpl;

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
		do 
		{
			cmpl = NQueen(q, d, y, c);
			cout << endl << endl;
		} while (cmpl > 0);				//cmpl becomes true when all combinations become true
	}
}

int NQueen(Board queen, int size, int row, int col)
{
	int found = 0;					//Will become one when a proper place is found
	int x,y;							//Here y for printing variable
	int ret;						//Value of last column

	if (row >= size)
	{
		queen.refill(ret);
		return ret;					//In case 1 combination is found
	}
	else
	{
		if (!queen.check(col))		//passing column. This condition checks if we can place queen or not. It returns false if we can place queen there
		{
			queen.Push(col);
			col = 1;
			ret = NQueen(queen, size, row + 1, col);
			found = 1;
		}
		else if (col < size)
		{
			ret = NQueen(queen, size, row, col + 1);
		}
		else							//Runs in case no appropriate location for queen was found
		{
			queen.Pop(col);				//In case its already row one, col wont be modified
			if (queen.IsEmpty())		//In case we are modifying queen ot of row 1
			{
				queen.Top(col);
				if (col >= size)			//Indicates that queen is already in last column so no condition is further possible							
					return -1;
			}
			else
			{
				row = queen.getrow();
				ret = NQueen(queen, size, row, col + 1);		//Even if col exceeds it really doesnt matter as we will keep popping it
			}
		}

	}
	if (queen.IsEmpty())
	{
		queen.refill(y);
		x = queen.getrow();
		PrintQ(queen);
	}
	return ret;
}

void PrintQ(Board queen)
{



}