#include <iostream>
#include "Set.h"
#include "Queue.h"

using namespace std;

void main()
{
	int n;
	cout << "Enter the number of elements you want in set = ";
	cin >> n;
	cout << "\nAll Subsets are:\n";
	Set s;
	for (int i = 0; i < n; i++)
	{
		s.add(i + 1);
	}
	s.allSubset(n);
}
