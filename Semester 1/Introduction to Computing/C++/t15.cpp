#include<iostream>
#include<stdlib.h>

using namespace std;

int main(int argc, char *argv[])
{
	if(argc == 2)
	{
		int n;
		n = atoi(argv[1]);
		
		for(int i = 1; i <=10;i++)
		{
			cout << i << " x " << n << " = " << i*n<<endl;

		}	

	}
	cout << endl;
	return 0;
}
