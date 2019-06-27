
#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

void boundary(int x, int *len, int *wid);									//For determining boundary of Rectangle
void rectangle(int P, int l, int b, int *arr, int point, bool kill);		//For Displaying rectangle
void Display(int address,int *arr, int point, bool kill);					//For Setting color and space
int* reduce(int *arr, int point, int *size);
int* Increment(int* arr, int *size, int increase,int num);

void main()
{
	srand(time(0));
	int n, breadth , length, k;
	bool Death = FALSE;														//Becomes true when your time of death is near
	int Pointer;															//Stores address of current element
	int p, r;																	//Decides when new people will join. r decides when people die
	int counter = 0, killed = 0;							//Counter counts how many times its executed, killed determines how many are killed
	int q;														//No. of newbies joining
	do
	{
	cout<<"Enter the no. of prisoners ";
	cin>>n;
	if(n<= 0)
		cout<<"The input must be a positive integer\n";
	}while(n<=0);
	k = n;
	int *array_1 = new int [k];
	for(int fill = 0; fill < k; fill++)
	{
		array_1[fill] = fill + 1;
	}

	Pointer = rand() % k;
	r = rand () % k + k;
	p = rand() % 3 + 5;

	while (k != 1)
	{
		system("cls");
		Pointer++;
		if (Pointer >= k)
			Pointer = 0;
		counter++;
		if (counter == r)
			Death = TRUE;
		
		boundary(k,&length,&breadth);
		rectangle(k,length,breadth,array_1 ,Pointer, Death );
		Sleep(500);

		if (Death)
		{
			Death = FALSE;
			killed++;
			r = r + rand() % k + 1;
			array_1 = reduce(array_1,Pointer,&k);
		}

		if (counter % p == 0 && killed < 7)
		{
			q = rand() % 5;
			if( n+q < 100)								//A constraint to restrict number to keep it rectangle and so that it doesnt take too long 
			{
			array_1 = Increment(array_1,&k,q,n);
			n= n+ q;
			}
		}
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cout<< "\nThe winner is "<<array_1[0] <<endl;
}

void boundary(int x, int *len, int *wid)
{
	int bound,rem;
	bound = x/2;
	rem = x % 2;
	if (bound % 2 == 0)
	{
		*len = bound/2 + rem;
		*wid = bound/2;
	}
	else 
	{
		*len = bound / 2 + 1;
		*wid = bound/2 + rem;
	}
}

void rectangle(int P, int l, int b, int *arr, int point, bool kill)
{
	for( int x = 0; x <= b; x++)
	{
		for(int y = 0; y <= l; y++)
		{
			if( x == 0)
			{
				Display(y,arr,point, kill);
			}

			else if ( x != 0 && x != b)
			{
				if( y == 0)
				{
					Display(P - x,arr,point, kill);
				}
				else if( y == l)
				{
					Display(l+x,arr,point, kill);
				}
				else
					cout<< "   ";
			}
			else if( x == b)
			{
				if(P % 2 != 0 && y == l)
					cout<<" ";			//For odd number
				else
					Display(P - (b+y),arr,point, kill);
			}
		}
		cout<<endl;
	}
}

void Display(int address, int *arr, int point, bool kill)
{
	if ( address == point && kill)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		cout<<arr[address];
	}
	else if (address == point)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
		cout<<arr[address];
	}
	else
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		cout<<arr[address];
	}

	if( arr[address] / 10 == 0)
		cout<<" ";
	cout<<" ";
}

int* reduce(int *arr, int point, int *size)
{
	int *arra = new int [*size - 1];
	for (int i = 0 ; i < point ; i++)
	{
		arra[i] = arr [i];
	}
	for (int i = point; i < *size  ; i++)
		arra[i] = arr [i + 1];
	*size = *size - 1;
	delete []arr;
	return arra;
}

int* Increment(int* arr, int *size, int increase,int num)
{
	int* new_ar = new int [*size + increase];
	int j = 0;
	for( j; j < *size; j++)
	{
		new_ar[j] = arr[j];
	}
	for (int i = 0; i < increase; i++)
	{
		new_ar[*size + i] = num + 1 + i;
	}
	*size = *size + increase;
	delete[]arr;
	return new_ar;
}