#include<iostream>
#include<string>
#include<stdio.h>

using namespace std;

int main()
{
	string text;
	int count = 0;
	char check;

	cout << "Enter a String: ";
	getline(std::cin, text);

	cout << "Enter the letter you want to check: ";
	cin >> check;

	for(int i = 0; text[i] != NULL; i++)
	{
		if(text[i] == check)
			count++;

	}

	cout << check << " repeats " << count << " times." << endl;
	return 0;
}
