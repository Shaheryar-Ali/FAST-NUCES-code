// C program to implement one side of FIFO
// This side reads first, then reads
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include<cstdlib>
 # include <iostream>
 using namespace std;
 struct Math
 {
   char op;
   int fo;
   int so;
 
 };
int main(int argc,char* argv[])
{
    
 	int fd1;
   
    char * myfifo = "/home/Lab6/myfifo";
 
    
    mkfifo(myfifo, 0666);
     char str1[80];
 while(1){
 	 
        fd1 = open(myfifo,O_WRONLY);
        cin.getline(str,80);
	Math m;
	m.op=str[0];
	m.fo=atoi(str[1]);
	m.so=atoi(str[2]);
        write(fd1, &m, sizeof(struct Math));	
        
        close(fd1);
        
 	int result;
 	  fd1 = open(myfifo,O_RDONLY);
 	  read(fd1,&result,sizeof(result));
 	  close(fd1);
 	    fflush(stdin);  
 	  cout<<"Result= "<<result<<endl;
 	  }
    return 0;
}
