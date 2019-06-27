#include<iostream>
#include<pthread.h>
#include <semaphore.h>
using namespace std;


sem_t sem1;
sem_t sem2;
sem_t sem3;


void* thread1 (void* );
void* thread2 (void* );
void* thread3 (void* );

int main(int argc,char* argv[]){

pthread_t tid;
pthread_t tid1;
pthread_t tid2;

 sem_init(&sem1, 0, 1);
  sem_init(&sem2, 0, 0);
   sem_init(&sem3, 0, 0);

pthread_create (&tid,NULL,&thread1,NULL);
pthread_create (&tid1,NULL,&thread2,NULL);
pthread_create (&tid2,NULL,&thread3,NULL);

pthread_join(tid, NULL);
pthread_join(tid1, NULL);
pthread_join(tid2, NULL);

return 0;
}

void* thread1 (void* ){

while(1){
sem_wait(&sem3);
cout << "a\n" ;
sem_post(&sem1);
}

}
void* thread2 (void*){
while(1){

 sem_wait(&sem2);
cout << 'b' ;
sem_post(&sem3);
}



}
void* thread3(void*){
while(1){

sem_wait(&sem1);
cout << 'c' ;
sem_post(&sem2);
}


}


