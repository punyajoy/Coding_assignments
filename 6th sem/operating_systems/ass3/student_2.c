#include <stdio.h>  
#include <stdlib.h>    
#include <unistd.h>    //fork(),pid
#include <sys/ipc.h>   //shmget() 
#include <sys/shm.h>   //shmget()  shmat() shmdt() 
#include <sys/wait.h>  //wait()
#include <sys/types.h> //wait()  shmat() shmdt()
#include <sys/time.h>

#define WAIT 1
int main()
{
  //printf("hello");
  int shm_id;
  key_t key=ftok("mat_avg.c",4);
  shm_id=shmget(key,sizeof(int),IPC_CREAT|0777);
  int *roll;
  roll= (int *) shmat(shm_id,NULL,0);
  *(roll) =-1;
  shmdt(roll);
  roll= (int *) shmat(shm_id,NULL,0);
  if(*roll==-1)
  {
       printf("the roll number:");
       scanf("%d",roll);
        	
        
  }
  shmdt(roll);     

      

return 0;
}