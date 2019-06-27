//Compile with -pthread


#include <iostream>
using namespace std;
#include <semaphore.h>
#include <pthread.h>

char a;
sem_t sem1;
sem_t sem2;
pthread_mutex_t mymutex; 
int count = 0;


void *Writer(void *)
{
 while (true)
 {
  sem_wait(&sem1);
  cin>>a;
  sem_post(&sem2);
 }

}

void* Reader (void *)
{  
   while (true)
    {
      sem_wait(&sem2);
        cout<<"Data Read: "<<a<<endl;
      sem_post(&sem1);
    }

}




void * thread1(void * x){
	
	while (true)
    {
      pthread_mutex_lock(&mymutex);
        count++;
		cout<<count<<endl;
      pthread_mutex_unlock(&mymutex);
      
    }

}


void * thread2(void * x){
	
	while (true)
    {
      pthread_mutex_lock(&mymutex);
        count--;
		cout<<count<<endl;
      pthread_mutex_unlock(&mymutex);
      
    }

}

int main()
{

   pthread_t id1, id2, id3, id4;
  sem_init(&sem1, 0, 1);
  sem_init(&sem2, 0, 0);
  
  

  pthread_mutex_init( &mymutex, NULL);
  
  pthread_create(&id1, NULL, &Writer, NULL);
  pthread_create(&id2, NULL, &Reader, NULL);
  
  
  pthread_create(&id3, NULL, &thread1, NULL);
  pthread_create(&id4, NULL, &thread2, NULL);
  
  
  pthread_join(id1, NULL);
  pthread_join(id2, NULL);

  
}