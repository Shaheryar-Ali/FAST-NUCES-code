#include<iostream>
#include<conio.h>
using namespace std;
void main()
{
	int **seats, row, column;
	int clas;
	char check;
	seats = new int *[13];
	for(int x =0; x < 13; x++)
	{
		seats[x] = new int [6];
		for(int y = 0; y < 6; y++)
		{
			seats[x][y] = 0;
		}
	}

	do
	{
		cout<<"Enter no. for your desired class \n '1' for First Class \n '2' for Business Class \n '3' for Economy class\n";
		cin>> clas;
		if (clas == 1)
		{
			do
			{
				cout<<"Enter row between 1 - 2 =";
				cin>> row;
				cout<<"Enter Column = ";
				cin>>column;
				if( seats[row - 1][column - 1] == 1)
				{
					cout<<"Seat already booked, book again\n";
				}
				else if( row > 2 || column > 6)
				{
					cout<<"Invalid seat, book again\n";
				}
				else
				{
					seats[row - 1][column - 1] = 1;
					break;
				}
			}while( seats[row - 1][column - 1] == 1 || row > 2 || column > 6 );
		}
	
		if (clas == 2)
		{
			do
			{
				cout<<"Enter row between 3 - 7 = ";
				cin>> row;
				cout<<"Enter Column = ";
				cin>>column;
				if( seats[row - 1][column - 1] == 1)
				{
					cout<<"Seat already booked, book again\n";
				}
				else if( row < 3 || row > 7 || column > 6)
				{
					cout<<"Invalid seat, book again\n";
				}
				else
				{
					seats[row - 1][column - 1] = 1;
					break;
				}
			}while( seats[row - 1][column - 1] == 1 ||  row < 3 || row > 7 || column > 6);
		}
			if (clas == 3)
			{
				do
				{
					cout<<"Enter row between 8 - 13 = ";
					cin>> row;
					cout<<"Enter Column = ";
					cin>>column;
					if( seats[row - 1][column - 1] == 1)
					{
						cout<<"Seat already booked, book again\n";
					}
					else if( row < 8 || row > 13 || column > 6)
					{
						cout<<"Invalid seat, book again\n";
					}
					else
					{
						seats[row - 1][column - 1] = 1;
						break;
					}
				}while( seats[row - 1][column - 1] == 1 ||  row < 8 || row > 13 || column > 6);
			}
				cout <<"Press y to input again, press any other key to continue";
				check = getch();
			}while(check == 'y');

	system("cls");
	for(int i = 0; i < 13; i++)
	{
		for( int j = 0; j < 6; j++)
		{
			if(seats[i][j] == 0)
			{
				cout<<"*\t";
			}
			else if(seats[i][j] == 1)
			{
				cout<<"X\t";
			}
		}
		cout<<endl;
	}

}