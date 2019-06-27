//Threads

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

//Question1 above

#include<iostream>
#include<unistd.h>
#include <string.h>
#include<stdlib.h>
 
using namespace std;
 
 
 void* Average(void* param){
 
  int* a=(int*) param;
  int* sum=new int;*sum=0;
  for(int i=1;i<=a[0];i++){
  *sum=*sum+a[i];
  }
  *sum=((*sum)/a[0]);
  pthread_exit( (void*) sum );
 
}
 
void* Min(void* param){
 int* a=(int*) param;
  int* min=new int;*min=a[1];
  for(int i=1;i<=a[0];i++){
 if(*min>a[i])
 {
*min=a[i];
 }
  }
  
  pthread_exit( (void*) min );
 
}
 
void* Max(void* param){
 
int* a=(int*) param;
  int* min=new int;*min=a[1];
  for(int i=1;i<=a[0];i++){
 if(*min<a[i])
 {
*min=a[i];
 }
  }
  
  pthread_exit( (void*) min );
}
 
int main(int argc, char* arg[]){
 
pthread_t id1,id2,id3;
  
  int * arr=new int[argc];
  
    arr[0] =   argc-1;
  
  for(int i=1; i<=argc-1;i++){
          arr[i]=atoi(arg[i]);
  }
   
  if (pthread_create(&id1, NULL, &Average,(void*)arr )==-1)
  {
      cout<<"Thread Creation Failed!"<<endl;
      return 1;
  }
  int *ptr;
  pthread_join(id1, (void**) &ptr);
  cout <<  "Average :" << *ptr << endl;
  
  if (pthread_create(&id2, NULL, &Min, (void*)arr)==-1)
  {
      cout<<"Thread Creation Failed!"<<endl;
      return 1;
  }
  
   pthread_join(id2, (void**) &ptr);
  cout <<  "Min :" << *ptr << endl;
  
  if (pthread_create(&id3, NULL, &Max, (void*)arr)==-1)
  {
      cout<<"Thread Creation Failed!"<<endl;
      return 1;
  }
  
   pthread_join(id3, (void**) &ptr);
  cout <<  "Max :" << *ptr << endl;
  
  
  
 
}
 
  //Q2 above