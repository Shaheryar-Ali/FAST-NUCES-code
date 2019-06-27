#include <iostream>
#include <stdlib.h>

using namespace std;

int main(int argc, char* arg[])
{
for (int i = 1; i < argc  ; i++)
{
	for (int j = 1;  j < argc-i; j++)
	{
		if(atoi(arg[j]) > atoi(arg[j+1]))
		{
			char* temp;
			temp = arg[j+1];
			arg[j+1] = arg[j];
			arg[j] = temp;  
		}
	
	}  


}

for (int i = 1; i < argc; i++)
{
	cout << arg[i];

}

return 0;
}