#include<iostream>
#include<string>
#include<fstream>

using namespace std;

void main()
{
	char a[10][30];
	ofstream name;
	name.open("Names.txt");
	if(name.is_open())
	{
		for(int i = 0; i <10; i++)
		{
			cout<<"Enter a name ";
			gets(a[i]);
			name<<a[i]<<endl;
		}
	}
	else
		cout<<"Failed to read";
}