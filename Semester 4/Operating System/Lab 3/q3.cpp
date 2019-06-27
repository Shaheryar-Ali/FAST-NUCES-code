#include <sys/types.h>
#include <iostream>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>

using namespace std;

int main(int argc, char* argv[])
{
	pid_t pid;
	pid = fork();
	
	if(pid < 0)
		exit(EXIT_FAILURE);
	else if(pid == 0)
	{
		execlp("/bin/cp" , "cp", "-T","q2.cpp", "q22.cpp" , NULL);
		exit(EXIT_SUCCESS);
	}
		
	else

	wait(NULL);
	return 0;
}