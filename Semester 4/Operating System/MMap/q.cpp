#include <sys/mman.h> 
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <sys/types.h>
#include <errno.h>
#include <string.h>
#include <semaphore.h>
#include <pthread.h>
 
 
using namespace std;
 
int count = 0;
char *addr;
char *sub;
int length;
pthread_mutex_t lock;
 
 
void *countA(void *)
{
	int siz = strlen(sub);
	for (int i = 0; i < length/2; i++)
	{
			for(int j = 0; j < siz; j++)
			{
				if(addr[i+j] != sub[j])
					break;
				else if(j == siz-1)
				{
					pthread_mutex_lock(&lock);
					count++;
					pthread_mutex_unlock(&lock);					
				}
			}
 
	}	
}
 
void *countB(void *)
{
	int siz = strlen(sub);
	for (int i = length/2; i < length; i++)
	{
			for(int j = 0; j < siz; j++)
			{
				if(addr[i+j] != sub[j])
					break;
				else if(j == siz-1)
				{
					pthread_mutex_lock(&lock);
					count++;
					pthread_mutex_unlock(&lock);
				}
 
			}
 
	}	
}
 
 
 
 
 
int main(int argc, char *argv[])
{
	int fd;
	struct stat sb;
	sub = argv[2];
 
	pthread_t id1, id2;
 
	if (argc != 3) 
	{
		cout << " file offset [length]\n";
		exit(EXIT_FAILURE);
	}
 
 
	fd = open(argv[1], O_RDONLY);
 
	if (fd == -1)
	{
		cout << "Failed to open file \n";
		exit(EXIT_FAILURE);
	}
 
	if (fstat(fd, &sb))           /* To obtain file size */
	{
		cout << "Failed to get file size";
		exit(EXIT_FAILURE);
	}
 
	length = sb.st_size;
 
	addr = (char*) mmap(NULL, getpagesize() , PROT_READ, MAP_PRIVATE, fd, 0);
	
	if (addr == MAP_FAILED)
	{
		cout << "Failed to map memory\n";
		exit(EXIT_FAILURE);
	}
 
	pthread_create(&id1, NULL, &countA, NULL);
  	pthread_create(&id2, NULL, &countB, NULL);
 
	 pthread_join(id1, NULL);
	 pthread_join(id2, NULL);
		
	cout << "No. of times the string appears = " << count<< endl;
 
 
           exit(EXIT_SUCCESS);
} /* main */