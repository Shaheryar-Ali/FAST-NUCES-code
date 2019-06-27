#include<iostream>
#include<pthread.h>
#include <semaphore.h>

using namespace std;

const int N=100;
sem_t sem1;
sem_t sem2;
char buff[N];

void* writer(void* );
void* reader(void* );

int main(int argc,char* argv[]){

pthread_t tid;
pthread_t tid1;




sem_init(&sem1, 0, 1);
sem_init(&sem2, 0, 0);
  
  
pthread_create (&tid,NULL,&writer,NULL);
pthread_create (&tid1,NULL,&reader,NULL);

pthread_join(tid, NULL);
pthread_join(tid1, NULL);


return 0;
}


void *writer(void *)
{
 while (true)
 {
  sem_wait(&sem1);
  cin.getline(buff,N);
  sem_post(&sem2);
 }

}

void* reader (void *)
{  
   while (true)
    {
      sem_wait(&sem2);
        cout<<"Data Read: "<<buff<<endl;
      sem_post(&sem1);
    }

}
