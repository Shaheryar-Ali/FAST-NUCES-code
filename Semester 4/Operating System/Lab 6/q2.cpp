#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
 # include <iostream>
#include <sys/types.h>
       #include <sys/wait.h>


 using namespace std;
 
 int main()
 {
 
	int pid=fork();
	if(pid==0)
	{
	    int fd1;
	   
	    char * myfifo1 = "/home/oracle/Desktop/myfifo1";
	 
	   
	    mkfifo(myfifo1, 0666);
 
            
		fd1 = open(myfifo1,O_WRONLY);
		dup2(fd1,1);
		execlp("ls","ls",NULL);
			return 0;
		}
		wait(NULL);
	int pid1=fork();
	
	if(pid1==0)
	{
	
		int fd2 = open("/home/oracle/Desktop/myfifo1",O_RDONLY);
		dup2(fd2,0);
		execlp("sort","sort",NULL);
		return 0;
	
	}
	
	wait(NULL);

	return 0;
}
