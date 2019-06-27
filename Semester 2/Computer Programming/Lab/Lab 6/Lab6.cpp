#include<iostream>
#include<conio.h>
using namespace std;
struct node
{
    int data;
    node *next;
    node *prev;
};

node *start=NULL, *temp1, *temp2, *temp3, *temp4, *temp5;
int N;

void addnode();
void delnode();
void display();
void listadd (int n);

int main()
{ 
    char ch;
	cout<<"Enter the no. of students you want to add to list = ";
	cin>>N;
	listadd(N);
	cout<<endl<<"No. of students = "<<N<<endl<<endl;
	display();
	cout<<"\n Press any key to display menu\n";
	_getch();
    do
    {
        char i;
		system("cls");
		cout<<"No. of students = "<<N<<endl<<endl;
        cout<<"Press 'a' to add node , 'd' to delete"<<endl;
        cout<<" 'v' for display"<<endl;
        cin>>i;

       switch (i)
       {
       case'a':
		  N++;
          addnode();
          break;
       case'd':
		   N--;
          delnode();
          break;
       case'v' :
          display();
          break;
       default:
          cout<<"Wrong input"<<endl;
          break;
       }
       cout<<"want to process more y/n"<<endl;
       cin>>ch;
     }
     while(ch!='n');
       return 0;
}
void addnode()          //adding node
{
    char r;
    temp1=new node;
	int num;
   
   cout<<"enter int to store"<<endl;
    cin>>temp1->data;
    
	cout<<"press 's' to add in start,'m' for midd , 'e' for end"<<endl;
    cin>>r;
    
	switch (r)
    {
    case's':                 //add startif(start==NULL)
        if(start == NULL)
		{
            start=temp1;
            temp1->next=NULL;
            temp1->prev=NULL;
        }
        else
        {
            temp2=start;
            temp1->next=temp2;
            temp1->prev=NULL;
            start=temp1;
            temp2->prev=temp1;
        }
        break;
    case'e':               //add end
        if(start == NULL)
		{
            start=temp1;
            temp1->next=NULL;
            temp1->prev=NULL;
        }
		else
		{
			temp2 = start;
			while(temp2->next != nullptr)
			{
				temp2 = temp2 -> next;
			}
			temp2->next = temp1;
			temp1->prev = temp2;
			temp1->next = nullptr;

		}
        break;
    case'm':                //add mid
        cout<<"enter node after which you want to enter"<<endl;
        cin>>num;
		if (num > N)
		{
			cout<<"The no. u entered was greater than total entry";
			_getch();
		}
		else
		{
			temp2 = start;
			for( int i = 1; i <= num; i++)
			{
				temp2 = temp2 -> next;
			}

			temp4 = temp2 -> next;
			temp1 ->prev = temp2;
			temp1 ->next = temp4;
			temp2-> next = temp1;
			temp4 -> prev = temp1;
		}
		break;
    }
}
void display()        //displaying
{
   
    temp3=start;
    if(start==NULL)
        cout<<"no node to display"<<endl;
    else
    {
      while(temp3->next!=NULL)
      {
          cout<<"Data stored is "<<temp3->data<<" at "<<temp3<<endl;
         temp3=temp3->next;
      }
      cout<<"Data stored is "<<temp3->data<<" at "<<temp3<<endl;
    }
}
void delnode()           //deleting
{  
    int num;
    char d;
    cout<<"press 's' to delete from start,'m' for midd , 'e' for end"<<endl;
    cin>>d;
   
   switch (d)
    {
      case's':
		  if(start==NULL)
          {
              cout<<"no node to delete"<<endl;
          }
          else
          {
              temp1=start;
              start=start->next;
              start->prev=NULL;
              delete temp1;
          }
        break;
     
	 case'e':
		 if(start==NULL)
          {
              cout<<"no node to delete"<<endl;
          }
          else
          {
              temp1=start;
			  while(temp1->next != nullptr)
				{
					temp1 = temp1 -> next;
				}
				temp1 = temp1 -> prev;
				temp1 -> next = nullptr;
          }
		break;
     
	 case'm':               //delete mid
		if(start==NULL)
          {
              cout<<"no node to delete"<<endl;
          }
		else
		{
			cout<<"enter node after which you want to delete"<<endl;
        cin>>num;
		if (num > N)
		{
			cout<<"The no. u entered was greater than total entry";
			_getch();
		}
		else
		{
			temp2 = start;
			for( int i = 1; i <= num; i++)
			{
				temp2 = temp2 -> next;
			}
			temp3 = temp2 -> prev;
			temp4 = temp2 -> next;
			temp3->next = temp4;
			temp4 -> prev= temp3;
			delete temp2;
		}


		}   
		break;
    }
}

void listadd (int n)
{
	int x;
	for(int i = 1; i <= n; i++)
	{
		if(i == 1)
		{
			start = new node;
			start->prev = nullptr;
			start->next = nullptr;
			cout<<"Enter student ID no. = ";
			cin>>x;
			start->data = x;
			temp5 = start;
		}
		else
		{
			temp4 = new node;
			cout<<"Enter student ID no. = ";
			cin>>x;
			temp4->data = x;
			temp4->next = nullptr;
			temp4->prev = temp5;
			temp5->next = temp4;
			temp5 = temp4;
		}

	}


}


//This code is by 164305
