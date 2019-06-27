#include <iostream>

#include <semaphore.h>
#include <sys/shm.h>
#include <queue>
#include <string.h>

using namespace std;
struct Data
{
	int *data ; 
	int count ; 
	float average;
};


int main(int argc,char* argv[]){

 

  int id_sem1=shmget(990, 1024, 0666 | IPC_CREAT | IPC_EXCL);
   int id_sem2=shmget(992, 1024, 0666 | IPC_CREAT | IPC_EXCL);
   int id_index=shmget(993, 1024, 0666 | IPC_CREAT | IPC_EXCL);
  int id_cs= shmget(991, 1024,  0666| IPC_CREAT | IPC_EXCL);

  sem_t *sem1;
  sem_t * sem2;
 
  if (id_sem1 ==-1 || id_sem2 ==-1 || id_cs==-1)
  {
   
    cout<<"ERROR!";
    return 1;
    
  }




  sem1= (sem_t*) shmat(id_sem1, NULL, 0);
   sem2= (sem_t*) shmat(id_sem2, NULL, 0);
   Data d[2]= {(Data*) shmat(id_cs, NULL, 0)};
	int* index = (int*)shmat(id_index, NULL, 0);
	
  sem_init(sem1, 0, 0); 
 sem_init(sem2, 0, 1);
 
 index[0] = 0;
 
  sem_wait(sem1); //wait for client
   sem_wait(sem1); //wait for client
   
   
  bool flag = true;
  int total=0;
  int totalCount=0;
  while(flag){
  cout << "Elements : ";
  
  for(int i=0;i<d[index[0]].count;i++){
  
  cout << d[index[0]].data[i] << " " ;
  total=total+d[index[0]].data[i];
  
  }
  
  cout << endl;
  cout <<"Count : "<<d[index[0]].count<<endl;
  totalCount = totalCount+d[index[0]].count;
  cout << index[0] << "Total : " << total<<endl;
  
  index[0]++;
  if(index[0] == 2){
  flag =false;
  
  }

}


int totalAvg=total/totalCount;
d[0].average=totalAvg;
d[1].average=totalAvg;

 sem_post(sem2); //signal client
 
 shmdt(sem1);
 shmdt(sem2);
 shmdt(index);
 shmdt(d);
 
  

}
