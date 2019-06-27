#include <iostream>
using namespace std;
#include <semaphore.h>
#include <pthread.h>

sem_t sem1;
sem_t sem2;
int buffer[50];
int N;

void *Writer(void *)
{
	for(int i = 0; i < N; i++)
	{
		cout << "Enter Value = ";
		cin >> buffer[i];
	}
	cout << endl;
sem_post(&sem1);
}

void* Reader (void *)
{  
	sem_wait(&sem1);
		for(int i = 0; i < N; i++)
		{
			cout << "Read Value = " << buffer[i] << endl;
		}        
}

int main()
{

   pthread_t id1, id2;
  sem_init(&sem1, 0, 0);
 
	cout <<"How many values do you want to enter = ";
	cin >> N; 

  pthread_create(&id1, NULL, &Writer, NULL);
  pthread_create(&id2, NULL, &Reader, NULL);
  
  pthread_join(id1, NULL);
  pthread_join(id2, NULL);

}