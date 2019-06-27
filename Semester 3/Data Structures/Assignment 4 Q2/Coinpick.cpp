#include <iostream>

using namespace std;

void coinpick(int coins, bool turn);

void main()
{
	int c;							//Stores coin
	bool player1 = true;			//True when its player 1 turn, false when player 2s
	cout << "Enter the no. of coins you want to enter = ";
	cin >> c;
	cout << endl;
	coinpick(c, player1);
}

void coinpick(int coins, bool turn)
{
	if (coins == 0)
	{
		if (!turn)						//It means player1 picked the last coin in previous turn
			cout << "Player 1 wins\n";
		else
			cout << "Player 2 wins\n";
	}
	else
	{
		if (turn)		//checks if its player 1 turn
			cout << "Player 1 ";
		else
			cout << "Player 2 ";


		if (coins >= 4 && (coins - 4) % 3 == 0)								//Checks if coins are greater than 4 and if we pick 4 coins then remainder is multiple of 3
		{
			cout << "picks 4 coins leaving " << coins - 4 << "coins.\n";
			coinpick(coins - 4, !turn);										//!turn Indicates change of turn
		}
		else if (coins >= 2 && (coins - 2) % 3 == 0)						//Checks if coins are greater than 2 and if we pick 2 coins then remainder is multiple of 3
		{
			cout << "picks 2 coins leaving " << coins - 2 << "coins.\n";
			coinpick(coins - 2, !turn);										//!turn Indicates change of turn
		}
		else
		{
			cout << "picks 1 coins leaving " << coins - 1 << "coins.\n";
			coinpick(coins - 1, !turn);
		}
	}
}