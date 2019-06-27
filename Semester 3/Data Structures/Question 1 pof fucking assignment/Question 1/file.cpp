#include <iostream>
#include <string.h>
#include "file.h"


using namespace std;

file ::file()
{
	cout << "Enter a file name";
	cin >> name;
	cout << "Enter size";
	cin >> size;
};


