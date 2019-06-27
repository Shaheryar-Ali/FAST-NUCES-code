#include "Set.h"
#include "Queue.h"
#include <iostream>

using namespace std;


Set::Set()
{
	size_of_set = 1;
	array = new int[size_of_set];
	array[0] = 1;
	index = 0;
}

Set::Set(int n)
{
	size_of_set = n;
	array = new int[n];
	index = 0;
}

void Set::add(int x)
{
	if (index == size_of_set)
	{
		array = extend(array);
	}
	array[index] = x;
	index++;
}

void Set::remove()
{
	index--;
}

int Set::getlast()
{
	return array[index - 1];			//since index points to the entry where we add next
}



int* Set::extend(int *arr)
{
	int temp = size_of_set;
	size_of_set = size_of_set * 2;
	int* arr2 = new int[size_of_set];
	for (int i = 0; i < temp; i++)
	{
		arr2[i] = arr[i];
	}
	delete[]arr;
	return arr2;
}


Set Set::operator = (Set& n)
{
	array = new int[n.size_of_set];
	size_of_set = n.size_of_set;
	for (int i = 0; i < n.size_of_set; i++)
	{
		array[i] = n.array[i];
	}
	return *this;
}

void Set::print()
{
	for (int i = 0; i < index; i++)
	{
			if (i == 0)
				cout << "{ " << array[i] << ", ";
			else if (i == index - 1)
				cout << array[i] << " }";
			else
				cout << array[i] << ", ";
	}
	cout << endl;

}

void Set::allSubset(int n)
{
	int power_size = n * n;			//Size of power set
	Set S;
	S.add(1);
	Queue<Set> Q(power_size);
	Q.Enqueue(S);

	while (!Q.IsEmpty())
	{
		Q.Dequeue(S);
		S.print();
		if (S.getlast() < S.size_of_set)
		{
			Set R = S;
			R.remove();
			R.add(S.getlast() + 1);
			Q.Enqueue(R);
			S.add(S.getlast() + 1);
			Q.Enqueue(S);
		}

	}
}

