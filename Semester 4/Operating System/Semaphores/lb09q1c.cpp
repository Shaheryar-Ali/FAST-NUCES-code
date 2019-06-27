#include <iostream>
#include<fstream>
#include <semaphore.h>
#include <sys/shm.h>
#include <queue>
#include <string.h>

using namespace std;

struct Data
{
	int data[100] ;
	 int count ; 
	 float average;
};

int main(int argc,char* argv[]){

string fileName;
cout << "Enter File Name : " ; 
cin >> fileName;


int id_sem1=shmget(990, 1024,0);
   int id_sem2=shmget(992, 1024,0);
   int id_index=shmget(993, 1024, 0);
  int id_cs= shmget(991, 1024,0);

  sem_t *sem1;
  sem_t * sem2;
 
  if (id_sem1 ==-1 || id_sem2 ==-1 || id_cs==-1)
  {
   
    cout<<"ERROR!";
    return 1;
    
  }




  sem1= (sem_t*) shmat(id_sem1, NULL, 0);
   sem2= (sem_t*) shmat(id_sem2, NULL, 0);
   Data d[2]={ (Data*) shmat(id_cs, NULL, 0)};
	int* index = (int*)shmat(id_index, NULL, 0);

	

	ifstream myFile(argv[1]);
	if(myFile.fail()){
	cout << "You had one Job" <<endl;
	return 0;
	}
	
	  sem_wait(sem2);  //ask client to wait for other client
	int i=0;
	
	while(!myFile.eof()){
	
	myFile >> d[index[0]].data[i];
	i++;
	
	}
	
	myFile.close();
	d[index[0]].count = 0;
	
	index[0]=index[0]+1;
	 sem_post(sem2);   //signal client 
	 sem_post(sem1); //signal server
	 
	sem_wait(sem2); // wait for server
	
	cout<< d[0].average<<endl;
	
	
  


return 0;
}
