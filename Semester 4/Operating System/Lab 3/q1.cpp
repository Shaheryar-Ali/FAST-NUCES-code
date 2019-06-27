#include <sys/types.h>
#include <iostream>
#include <sys/wait.h>

using namespace std;

int main()
{
pid_t pid;
pid = fork();

if(pid < 0)
{
	cout <<"Fork Error";
	return 0;
}
else if(pid == 0)
{
	for(int i = 0; i < 100; i++)
		cout<<"I am child \t";
	return 0;
}
else
{
	for(int i = 0; i < 100; i++)
		cout<<"I am parent \t";
		
	wait(NULL);
	return 0;
}

}