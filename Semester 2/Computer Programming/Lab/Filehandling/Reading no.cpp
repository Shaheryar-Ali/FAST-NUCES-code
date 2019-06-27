#include<iostream>
#include<fstream>

using namespace std;

void main()
{
	int a[10], i;
	ifstream readno;
	readno.open("Sample.txt");
	if (readno.is_open())
	{
		i = 0;
	while(!readno.eof())
	{

		readno>>a[i];
		cout<<a[i]<<endl;
				i++;
	}
	}
	else
		cout<<"Error opening";
	for(int i = 0; i <10 ; i++)
		cout<<a[i]<<endl;
}