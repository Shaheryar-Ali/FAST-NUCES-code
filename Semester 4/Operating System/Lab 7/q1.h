 #include <iostream> 
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include<stdio.h>
 
using namespace std;
 
 
void* fibonacci(void* m);
 
 
int main(int argc, char* argv[])
{
 
 
	for(int i = 1; i < argc; i++)
	{
		pthread_t tid;
		int par = atoi(argv[i]);
 
		if (pthread_create(&tid, NULL, &fibonacci, &par)==-1)
		  {
		      cout<<"Thread Creation Failed!"<<endl;
		      return 1;
		  }
		int *arr;
		pthread_join(tid, (void**) &arr);
		cout << "Thread " << i << ": "; 
		for(int i=0;arr[i]!=-1;i++)
  		cout << arr[i] << " ";
  		cout << endl;
	}
	return 0;
}
 
void* fibonacci(void* m)
{
	int n = *(int*) m;
	int size;
	int *arr2;
 
	if( n > 0)
	{
		int *arr;
		arr = new int [n*2];
		arr[0] = 0;
		arr[1] = 1;
		size = 2;
		while(arr[size-1] <= n)
		{
        		arr[size] = arr[size-1] + arr[size-2];
        		size++;
		}
		arr[size] = -1;
		size++;
 
		arr2 = new int [size];
 
		for(int i = 0; i < size; i++)
		{
			arr2[i] = arr[i];
			cout << ", " <<arr2[i];
		
		}
		cout << endl;
		delete []arr;
		
	}
	pthread_exit( (void*) arr2);
 
}