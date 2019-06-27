#include<iostream>
#include<conio.h>

using namespace std;

struct node
{
	int neu;
	int den;
	node *next;
};								//The node we will use throughout program

void Fares(node * heads, node *tails, int level);						//Main function that makes fractions
void increment(node * heads, node *tails, int *level);					//Increments the level by 1
void decrement(node *heads, node *tails, int *level);					//Decrements the level by 1
void Printlist(node *head);												//For printing list in each loop.


void main()
{
	node head, tail;							
	int n, m;															//Basically level
	int menu;
	cout<<"Enter the level = ";
	cin>>n;
	while(n < 1)														//To prevent negative things
	{
		cout<<"level should be positive no., enter again\n";
		cin>>n;
	}

	Fares(&head,&tail,n);												//The real deal										
	do
	{
		system("cls");													//clear screen during each loop
		Printlist(&head);												//printing list in each loop
		cout<<endl;
		cout<<"Press '1' to increase the level\n";						//Next 4 lines are menu
		cout<<"Press '2' to decrease the level\n";
		cout<<"Press '3' to change the level\n";
		cout<<"Press '4' to exit\n";
		cin>>menu;														//Recieves menu input
		switch(menu)
		{
		case 1:
			increment(&head,&tail,&n);
			break;
		case 2:
			if(n - 1 < 1)												//Prevents reduction 
			{
				cout<<"Cant reduce further";
				_getch();
			}
			else
			{
				decrement(&head,&tail,&n);
			}
			break;
		case 3:
			cout<<"Enter desired level = ";
			cin>>m;
			while(m < 1)												//Prevents negative values
			{
				cout<<"level should be positive no., enter again\n";
				cin>>m;
			}
			Fares(&head,&tail,m);
			n = m;
			break;
		case 4:
			break;
		default:
			cout<<"Wrong input, press any key to continue";
			_getch();
			break;
		}
	}while(menu != 4);
}

void Fares(node * heads, node * tails, int level)
{
	node *curr, *nex;									//Stores the current node which is reading and next
	for(int i = 1; i <= level; i++)
	{
		if( i == 1)										//Sets first level, basically storing head and tail
		{
			heads->neu = 0;
			heads->den = 1;
			tails->neu = 1;
			tails->den = 1;
			heads->next = tails;
			tails->next = nullptr;
		}
		else
		{
			curr = heads;
			nex = heads->next;
			while( curr->next != nullptr)
			{
				if(curr->den + nex->den <= level)
				{
					node *mid = new node;									//The new node to add in between
					mid->neu = curr->neu + nex ->neu;						//For deciding numerator or mid term
					mid->den = curr->den + nex->den;						//For denominstor of new term, mostly equal to level
					curr->next = mid;										//Makes the new term next term
					mid->next = nex;										//connects the new term with previous next term, thus putting it inbetween
				}
				curr = nex;													//switches current to next
				nex = nex -> next;											//switches next to node after next
			}
		}

	}
}

void Printlist(node *head)
{
	cout<<"( ";
	if (head != nullptr)
	{
		node *curr = head;
		while(curr!=nullptr)
		{
			cout<<curr->neu<<"/"<<curr->den;
			curr = curr -> next;
			if( curr!= nullptr)												//To avoid comma after last term
				cout<<", ";
		}
	}
	cout<<" )"<<endl;
}

void increment(node * heads, node *tails, int *level)
{
	node *curr, *nex;
	*level = *level + 1;
	curr = heads;
	nex = heads->next;
	while( curr->next != nullptr)											//Loop condition
	{
		if(curr->den + nex->den <= *level)									//Basically same task as Fares function
		{
			node *mid = new node;
			mid->neu = curr->neu + nex ->neu;
			mid->den = curr->den + nex->den;
			curr->next = mid;
			mid->next = nex;
		}
	curr = nex;
	nex = nex -> next;
	}
}

void decrement(node *heads, node *tails, int *level)
{
	node *curr = heads, *nex;												//Same task 
	*level = *level - 1;
	while(curr -> next != nullptr)
	{
		nex = curr -> next; 
		if(nex->den <= *level)
		{
			curr = curr -> next;
		}
		else
		{
			curr -> next = nex ->next;
		}

	}
}