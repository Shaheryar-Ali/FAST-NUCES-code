#include <sys/types.h>
#include <iostream>
#include <sys/wait.h>
#include <stdlib.h>

using namespace std;

int main(int argc, char* arg[])
{
pid_t pid1;
pid1 = fork();

if(pid1 < 0)
{
	cout <<"Fork Error 1";
	return 0;
}
else if(pid1 == 0)
{	int sum = 0;
	for(int i = 1; i < argc; i++)
		sum = sum + atoi(arg[i]);
	cout << "Sum=" << sum << endl; 
	return 0;
}
else
{	
	pid_t pid2;
	pid2 = fork();

	if(pid2 < 0)
	{
		cout <<"Fork Error 2";
		return 0;
	}
	else if(pid2 == 0)
	{	int sum = 0, avg;
		for(int i = 1; i < argc; i++)
			sum = sum + atoi(arg[i]);
		avg = sum/ (argc - 1);
		cout << "Average=" << avg <<endl;
		return 0;
	}
	else
	{
		pid_t pid3;
		pid3 = fork();

		if(pid3 < 0)
		{
			cout <<"Fork Error 3";
			return 0;
		}
		else if(pid3 == 0)
		{	int max = atoi(arg[1]);
			for(int i = 1; i < argc; i++)
				if(atoi(arg[i]) > max)
					max = atoi(arg[i]);
			
			cout << "Maximum=" << max << endl; 
			return 0;
		}
	}
	
}
	wait(NULL);
	wait(NULL);
	wait(NULL);
	return 0;
}