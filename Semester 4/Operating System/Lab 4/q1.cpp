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
	int pipe1[2], pipe2[2];
	char buf;

	if(pipe(pipe1) == -1)
	{
		perror("pipe1");
		exit(EXIT_FAILURE);
	}

	if(pipe(pipe2) == -1)
	{
		perror("pipe2");
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
		close(pipe1[1]);
		close(pipe2[0]);

		while(read(pipe1[0], &buf, 1)>0)
		{
			if(buf >= 'a' && buf <= 'z')
				buf = buf - 32;
			else if(buf >= 'A' && buf <= 'Z')
				buf = buf + 32;
			write(pipe2[1], &buf, 1);			
		}
		
		close(pipe1[0]);
		close(pipe2[1]);
		exit(EXIT_SUCCESS);
	}
	else
	{
		close(pipe1[0]);
		write(pipe1[1], argv[1], strlen(argv[1]));
		close(pipe1[1]);
		wait(NULL);
		close(pipe2[1]);
		while(read(pipe2[0], &buf, 1)>0)
		{
			write(1, &buf, 1);			
		}	
		close(pipe2[0]);
		cout << endl;
		exit(EXIT_SUCCESS);
	}
	
}