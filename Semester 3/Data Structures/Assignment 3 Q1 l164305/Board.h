#pragma once

class Board
{
	private:
		int size;
		int row;			//it will actually store one less value for ease of calculation
		int *sol;			//array of solution

	public:
		Board(int n);
		void Push(int n = 1);
		void Pop(int &n);
		void Top(int &n);
		bool IsEmpty();
		bool IsFull();
		bool check(int col);
		int  getrow();
		void refill(int &n);
};