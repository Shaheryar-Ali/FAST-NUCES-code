#include <sys/types.h>
#include <iostream>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <string>
#include <string.h>
#include <stdio.h>
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{
	pid_t pid1;
	int pipe1[2];
	char buf;

	if(pipe(pipe1) == -1)
	{
		perror("pipe1");
		exit(EXIT_FAILURE);
	}

	pid1=fork();	

	if(pid1 < 0)
	{
		perror("fork1");
		exit(EXIT_FAILURE);
	}
	else if(pid1 == 0)
	{
		ofstream writef;
		writef.open(argv[2]);
		
		if(!writef.is_open())
		{
			cout << "Error writing";
			exit(EXIT_FAILURE);			
		}

		close(pipe1[1]);
		
		while(read(pipe1[0], &buf, 1)>0)
		{
			writef << buf;	
			write(1,&buf,1);	
		}	

		
		close(pipe1[0]);
		writef.close();
		exit(EXIT_SUCCESS);
	}
	else
	{
		close(pipe1[0]);

		ifstream readf;
		readf.open(argv[1]);
		if(readf.is_open())
			while(!readf.eof())
			{
				readf >> buf;
				write (pipe1[1], &buf, 1);
			}
		readf.close();
		close(pipe1[1]);
		wait(NULL);
		return 0;
	}
	
}