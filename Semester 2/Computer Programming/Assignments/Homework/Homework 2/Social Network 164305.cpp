#include<iostream>
#include<fstream>
#include<conio.h>
using namespace std;

struct account
{
	int person;
	int friend_no;
	int *friend_list;
};
void display(account *disp,int size);
int menudisp(void);
account *addperson(account *list,int *size);
account *makefriend(account *list,int size);
account *unfriend(account *list, int size);
account *deleteacc(account *list, int *size);
void mutual(account *comp, int p1, int p2,int size);
void findfriend(account *list, int size);
void update(account *file, int size);
int decifer(account *file, int size, int n);


void main()
{
	ifstream Read("FriendInfo.txt");		//For reading from file
	int size;								//No. of people on social media
	account *frien;							//For storing friends record
	int index, temp_pers;					//For storing the current person and how many friends they have
	int templist[100];						//A temporary list for storing all friends
	char comastore;							//for storing coma during reading
	int menu, n1, n2,n7a,n7b;

	Read>>size;
	frien = new account[size];
	
	for(int i = 0; i < size; i++)									//Reading function
	{
		index = 0;
		Read>>temp_pers;
		Read>>comastore;
		while(comastore!=';')
		{
			Read>>templist[index];
			index++;
			Read>>comastore;
		}
		frien[i].person = temp_pers;
		frien[i].friend_no = index;
		frien[i].friend_list = new int [index];
		for(int j = 0; j < index; j++)
		{
			frien[i].friend_list[j] = templist[j];					//end of reading and printing

		}
	}


	do
	{
		system("cls");
		display(frien,size);
		menu = menudisp();
		switch(menu)
		{
		case 1:
			frien = addperson(frien,&size);
			break;
		case 2:
			frien = makefriend(frien,size);
			break;
		case 3:
			frien = unfriend(frien,size);
			break;
		case 4:
			frien = deleteacc(frien,&size);
			break;
		case 5:
			{
				system("cls");
				cout<<"Enter your ID :";
				cin>>n1;
				n1 = decifer(frien,size,n1);
				if(n1<0)
					break;
				cout<<"\nYour friends are ";
				for(int j = 0; j < frien[n1].friend_no; j++)
				{
						cout<<frien[n1].friend_list[j]<<", ";
				}
				_getch();
			}
			break;
		case 6:
			{
				system("cls");
				cout<<"Enter your ID :";
				cin>>n1;
				n1 = decifer(frien,size,n1);
				if(n1<0)
					break;
				cout<<"\nYour friends are ";
				for(int j = 0; j < frien[n1].friend_no; j++)
				{
						cout<<frien[n1].friend_list[j]<<", ";
				}
				cout<<endl<<endl;
				for(int x = 0; x < frien[n1].friend_no; x++)
				{
					n2 = frien[n1].friend_list[x];
					cout<<"Person "<<n2<<" friends are ";
					for(int y = 0; y < frien[n2].friend_no; y++)
					{
							cout<<frien[n2].friend_list[y]<<", ";
					}
					cout<<endl;
				}
				_getch();
			}
			break;
		case 7:
			cout<<"Enter your ID : ";
			cin>>n7a;
			cout<<"Enter whose mutual friend you want to find: ";
			cin>>n7b;
			mutual(frien,n7a,n7b,size);
			_getch();
			break;
		case 8:
			findfriend(frien,size);
			_getch();
			break;
		case 9:
			update(frien,size);
		}

	}while(menu != 0);

	Read.close();
	_getch();
}


void display(account *disp, int size)
{
	for(int i = 0; i < size; i++)
	{
		cout<<disp[i].person<<"*->";							
		for(int j = 0; j < disp[i].friend_no; j++)
			{
				if(j<disp[i].friend_no-1)
					cout<<disp[i].friend_list[j]<<",";
				else
					cout<<disp[i].friend_list[j];
			}
		cout<<endl;
	}

}


int menudisp(void)
{
	int n;
	cout<<endl;
	cout<<"Press '1' to add new user\n";
	cout<<"Press '2' to make friends\n";
	cout<<"Press '3' to unfriend\n";
	cout<<"Press '4' to Remove User\n";
	cout<<"Press '5' to Print Friends of User\n";
	cout<<"Press '6' to Print Friends of Friends\n";
	cout<<"Press '7' to Print Mutual friends of two users\n";
	cout<<"Press '8' to know likely friends\n";
	cout<<"Press '9' to save all updated data\n";
	cout<<"Press '0' to exit\n";
	do{
	cin>>n;
	if(n>9)
		cout<<"Invalid Input: please enter again\n";
	}while(n>9);
	return n;
}

account *addperson(account *list,int *size)
{
	account *list2 = new account[*size + 1];
	for(int i = 0; i<*size; i++)
	{
		list2[i].person = list[i].person;
		list2[i].friend_no = list[i].friend_no;
		list2[i].friend_list = new int [list[i].friend_no];
		for(int j =0; j < list[i].friend_no;j++)
		{
			list2[i].friend_list[j] = list[i].friend_list[j];
		}
	}
	list2[*size].person = list2[*size - 1].person + 1;
	list2[*size].friend_no = 0;
	list2[*size].friend_list = new int [list2[*size].friend_no];

	*size = *size + 1;

	delete[]list;
	return list2;
}

account *makefriend(account *list,int size)
{
	account *list2 = new account[size];
	int p1, p2;
	bool already_friend = false;
	cout<<"Enter your person id, that is your person no. = ";
	do
	{
		cin>>p1;
		if(p1 < 0)
			cout<<" Invalid input, Enter again: ";
	}while(p1<0);													//For making sure person is actually available
	cout<<"Enter who u want to be friend with : ";
	do
	{
		cin>>p2;
		if(p2 < 0 || p2 == p1)
			cout<<" Invalid input, Enter again: ";
	}while(p2<0 || p2 == p1);

	for(int i = 0; i<size; i++)
	{
		list2[i].person = list[i].person;
		if(list2[i].person == p1 || list2[i].person == p2)
		{
			for(int k=0; k < list[i].friend_no; k++)						//For making sure peeps are not already friend
			{
				if (list[i].friend_list[k] == p1|| list[i].friend_list[k] == p2)
				{
					already_friend = true;
					system("cls");
					cout<<"You are already friend with the person, How closer do u want to get\n";
					_getch();
				}
			}
			if(!already_friend)											//This part is actually responsible for making friends, such a nice person
			{
				list2[i].friend_no = list[i].friend_no + 1;
				list2[i].friend_list = new int [list2[i].friend_no];
				for(int j =0; j < list[i].friend_no;j++)
				{
					list2[i].friend_list[j] = list[i].friend_list[j];
				}
				if(list2[i].person == p1)
					list2[i].friend_list[list[i].friend_no] = p2;
				else if(list2[i].person == p2)
					list2[i].friend_list[list[i].friend_no] = p1;
			}
			else
			{
				list2[i].friend_no = list[i].friend_no;
				list2[i].friend_list = new int [list[i].friend_no];
				for(int j =0; j < list[i].friend_no;j++)
				{
					list2[i].friend_list[j] = list[i].friend_list[j];
				}

			}
		}
		else
		{
			list2[i].friend_no = list[i].friend_no;
			list2[i].friend_list = new int [list[i].friend_no];
			for(int j =0; j < list[i].friend_no;j++)
			{
				list2[i].friend_list[j] = list[i].friend_list[j];
			}
		}
	}
	delete []list;
	return list2;
}

account *unfriend(account *list, int size)
{
	account *list2 = new account[size];
	int p1, p2;
	bool not_friend = true;
	int x;
	int match;
	cout<<"Enter your person id, that is your person no. = ";
	do
	{
		cin>>p1;
		if(p1 < 0)
			cout<<" Invalid input, Enter again: ";
	}while(p1<0);													//For making sure person is actually available
	
	cout<<"Enter who u want to unfriend : ";
	do
	{
		cin>>p2;
		if(p2 < 0 || p2 == p1)
			cout<<" Invalid input, Enter again: ";
	}while(p2<0 || p2 == p1 );

	for(int i = 0; i<size; i++)
	{
		list2[i].person = list[i].person;
		if(list2[i].person == p1 || list2[i].person == p2)
		{

			for(int k=0; k < list[i].friend_no; k++)						//For making sure peeps are not already friend
			{
				if (list[i].friend_list[k] == p1 || list[i].friend_list[k] == p2)
				{
					not_friend = false;
					match = k;
					break;
				}
			}
			if(!not_friend)											//This part is actually responsible for break up.
			{
				x = 0;
				list2[i].friend_no = list[i].friend_no - 1;
				list2[i].friend_list = new int [list2[i].friend_no];
				for(int j =0; j < list2[i].friend_no;j++)
				{
					if( j== match)
						x =1;
					list2[i].friend_list[j] = list[i].friend_list[j+x];
				}

			}
			else
			{
				cout<<"You are not friends already\n";
				_getch();
				list2[i].friend_no = list[i].friend_no;
				list2[i].friend_list = new int [list[i].friend_no];
				for(int j =0; j < list[i].friend_no;j++)
				{
					list2[i].friend_list[j] = list[i].friend_list[j];
				}

			}
		}
		else
		{
			list2[i].friend_no = list[i].friend_no;
			list2[i].friend_list = new int [list[i].friend_no];
			for(int j =0; j < list[i].friend_no;j++)
			{
				list2[i].friend_list[j] = list[i].friend_list[j];
			}
		}
	}
	delete []list;
	return list2;
}

account *deleteacc(account *list, int *size)
{
	account *list2 = new account[*size - 1];
	int k, x1 = 0,x2 = 0, match;
	bool matched;

	cout<<"Enter your person id, that is your person no. = ";
	do
	{
		cin>>k;
		if(k < 0)
			cout<<" Invalid input, Enter again: ";
	}while(k<0);
	for(int i = 0; i < *size - 1; i++)
	{
		matched = false;
		x2 = 0;
		match = -1;
		if(list[i].person == list[k].person)
			x1 = 1;
		list2[i].person = list[i+x1].person;

		for(int j = 0; j < list[i+x1].friend_no; j++)
		{
			if(list[i+x1].friend_list[j] == list[k].person)
			{
				matched = true;
				match = j;
			}
		}
		if(matched)
		{
			list2[i].friend_no = list[i+x1].friend_no - 1;
		}
		else
		{
			list2[i].friend_no = list[i+x1].friend_no;
		}
		list2[i].friend_list = new int [list2[i].friend_no];
		for(int l = 0; l < list2[i].friend_no;l++)
		{
			if(l == match)
			{
				x2 = 1;
			}
			list2[i].friend_list[l] = list[i+x1].friend_list[l+x2];
		}
	}			
	*size = *size - 1;
	delete []list;
	return list2;
}

void mutual(account *comp, int p1, int p2,int size)
{
	int n1, n2,temp1,temp2;
	system("cls");
	for(int x = 0; x < size; x++)
	{
		if(comp[x].person == p1)
		{
			n1 = x;
			break;
		}
	}
	for(int y = 0; y < size; y++)
	{
		if(comp[y].person == p2)
		{
			n2 = y;
			break;
		}
	}
	cout<<p1<<" and "<<p2<<" mutual friends are ";
	for(int i = 0; i < comp[n1].friend_no; i++)
	{
		temp1 = comp[n1].friend_list[i];
		for(int j = 0; j < comp[n2].friend_no; j++)
		{
			temp2 = comp[n2].friend_list[j];
			if(temp1 == temp2)
				{
					cout<<temp1<<", ";
				}
		}
	}

}

void findfriend(account *list, int size)
{
	system("cls");
	int n,count,s1,s2,s3;
	int *match = new int [size];
	cout<<"Enter your ID : ";
	cin>>n;
	for(int i = 0; i < size;i++)
	{
		if(list[i].person == n)
		{
			n = i;
			break;
		}
	}
	for(int j = 0; j < size; j++)
	{
		count = 0;
		for(int k= 0; k < list[n].friend_no; k++)
		{
			for(int l = 0; l < list[j].friend_no;l++)
			{
				if(list[n].friend_list[k] == list[j].friend_list[l])
				{
					count++;
				}
			}
		}
		if(j!=n)
		{
			match[j] = count;
		}
		else
		{
			match[j] = - 1;
		}
	}
	s1 = 0;
	for(int f1 = 1; f1 < size; f1++)
	{
		if(match[s1] < match[f1])
			s1 = f1;
	}
	cout<<"\nTop Suggestion : "<<list[s1].person <<", mutual friends ="<<match[s1];
	s2 = 0;
	for(int f2 = 1; f2 < size; f2++)
	{
		if(f2 != s1)
		{
			if(match[s2] < match[f2])
				s2 = f2;
		}
	}
	cout<<"\nSecond Suggestion : "<<list[s2].person <<", mutual friends ="<<match[s2];
	s3 = 0;
	for(int f3 = 1; f3 < size; f3++)
	{
		if(f3 != s1 && f3 != s2)
		{
			if(match[s3] < match[f3])
				s3 = f3;
		}
	}
	cout<<"\nThird Suggestion : "<<list[s3].person <<", mutual friends ="<<match[s3];
}

void update(account *file, int size)
{
	ofstream edit("FriendInfo.txt");
	edit<<size<<endl;
	for(int i = 0; i < size; i++)
	{
		edit<<file[i].person;
		if(file[i].friend_no == 0)
		{
			edit<<";"<<endl;
		}
		else
			edit<<",";
		for(int j = 0; j < file[i].friend_no ; j++)
		{
			edit<<file[i].friend_list[j];
			if(j == file[i].friend_no - 1)
				edit<<";"<<endl;
			else
				edit<<",";
		}

	}
	edit.close();
}

int decifer(account *file, int size, int n)
{
	int ans;
	bool n_found = true;
	for(int i = 0; i < size; i++)
	{
		if(file[i].person == n)
		{
			 ans = i;
			 n_found = false;
			 break;
		}
	}
	if(n_found)
	{
		cout<<"User not found";
		ans = -1;
		_getch();
	}
	return ans;

} 