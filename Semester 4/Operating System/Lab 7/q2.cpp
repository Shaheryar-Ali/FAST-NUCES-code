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