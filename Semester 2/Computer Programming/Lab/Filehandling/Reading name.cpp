#include<iostream>
#include<string>
#include<fstream>

using namespace std;

void main()
{
	char c[10][30];
	int i = 0, read[10];
	ifstream rname;
	rname.open("Name.txt");
	if(rname.is_open())
	{
		while(!rname.eof())
		{
			rname>>c[i];
			rname>>read[i];
			cout<<c[i]<< " " << read[i]<<endl;
			i++;
		}
	}
	else
		cout<<"Failed to read";
}