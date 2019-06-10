#include<iostream>
#include <stdlib.h>

using namespace std;

int main(int argc, char *argv[])
{
	if(argc!= 2)
		cout << "Inaccurate parameters\n";
	else
	{
		if(atoi(argv[1]) % 7 == 0)
			cout << "Sunday";
		else if(atoi(argv[1]) % 7 == 1)
			cout << "Monday";
		else if(atoi(argv[1]) % 7 == 2)
			cout << "Tuesday";
		else if(atoi(argv[1]) % 7 == 3)
			cout << "Wednday";
		else if(atoi(argv[1]) % 7 == 4)
			cout << "Thursday";
		else if(atoi(argv[1]) % 7 == 5)
			cout << "Friday";
		else if(atoi(argv[1]) % 7 == 6)
			cout << "Saturday";


	}
	cout << endl;
	return 0;

}

