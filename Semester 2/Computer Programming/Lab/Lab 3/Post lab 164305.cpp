#include<iostream>
#include<conio.h>
using namespace std;

int size = 1;
int condition(int *arr, int cur_size, int entry);
int* addentry(int *arr, int cur_size, int *max_size, int entry);
int* delentry(int *arr, int cur_size, int *max_size, int entry);
void display(int *arr, int cur_size, int max_size);


void main()
{
	int current_size = 0, path, ent;
	int *table = new int [size];
	char repeat;


	do
	{
		system("cls");
		cout<<"Enter a no. =";
		cin>>ent;
		path = condition(table, current_size, ent);
		if (path == 1)
		{
			table = addentry(table,current_size, &size, ent);
			current_size++;
		}
		else if(path == 2)
		{
			table = delentry(table,current_size, &size, ent);
			current_size--;
		}
		else
			cout<<"unexpected path";
		cout<<"Current Array\n\n";
		display(table, current_size, size);
		cout<<endl;
		cout<<"Press y to enter again / Press any other key to continue\n";
		repeat = _getch();
	}while(repeat == 'y');


}




int condition(int *arr, int cur_size, int entry)
{
	int cond, match = 0;
	for (int i = 0; i < cur_size && match == 0; i++)
	{
		if( arr[i] == entry)
		{
			match = 1;
			cond = 2;					//Condition 2 represents deletion
		}
	} 

	if(match == 0)
		cond = 1;						//Represents addition is required
	return cond;
}

int* addentry(int *arr, int cur_size, int *max_size, int entry)
{
	int temp,test = 1;			
	if(cur_size + 1 > *max_size)
		*max_size = *max_size * 2;
	int *arr2 = new int [*max_size];
	for(int i = 0; i <cur_size; i++)
		arr2[i] = arr[i];
	arr2[cur_size] = entry;
	for(int j = 0; j < cur_size && test; j++)				//This part is for sorting
	{
		test = 0;											//Test 0 represents no swapping has take  place
		for(int k = 0; k < cur_size; k++)
		{
			if(arr2[k] > arr2[k+1])
			{
				temp = arr2[k];
				arr2[k] = arr2[k+1];
				arr2[k+1] = temp;
				test = 1;
				break;
			}
		}
	}
	delete[]arr;
	return arr2;
}

int* delentry(int *arr, int cur_size, int *max_size, int entry)
{
	int index = 0;
	if(cur_size - 1 <= *max_size/2)
		*max_size = *max_size/2;
	int *arr1 = new int [*max_size];
	while(index < cur_size)
	{
		if(arr[index] == entry)
			break;
		else
		{
			index++;
			if(index > cur_size)
				cout<<"Error in delentry or the size of arrays being passed";
		}
	}
	for(int i = 0; i < cur_size- 1; i++)
		{
			if(i<index)
				arr1[i] = arr[i];
			else
				arr1[i] = arr[i + 1];
		}
	delete []arr;
	return arr1;
}

void display(int *arr, int cur_size, int max_size)
{
	for(int i = 0; i < max_size; i++)
	{
		if (i < cur_size)
			cout<<arr[i]<<endl;
		else
			cout<<"Null"<<endl;
	}
}