#include<iostream>
#include<string>
#include<stdio.h>

using namespace std;

int main()
{
	string text;
	int j;

	cout << "Enter a String: ";
	getline(std::cin, text);

	for(int i = 0; text[i] != NULL; i++)
	{
		if(text[i] == ' ')
		{
			j= i;
			for(j; text[j+1] != NULL; j++)
			{
				text[j] = text[j+1];
			}
			text[j] = NULL;
			
		} 

	}	
	cout << text << endl;
	return 0;
}
