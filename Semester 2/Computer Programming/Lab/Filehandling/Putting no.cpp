#include<iostream>
#include<fstream>

using namespace std;

void main()
{
	ofstream writeno;
	writeno.open("Sample.txt");
	for(int i = 0; i < 10; i++)
	{
		writeno<<i+1<<endl;
		cout<<i;
	}
}