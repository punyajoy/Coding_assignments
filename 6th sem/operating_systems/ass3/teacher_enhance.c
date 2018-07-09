#include <stdio.h>  
#include <stdlib.h>    
#include <unistd.h>    //fork(),pid
#include <sys/ipc.h>   //shmget() 
#include <sys/shm.h>   //shmget()  shmat() shmdt() 
#include <sys/wait.h>  //wait()
#include <sys/types.h> //wait()  shmat() shmdt()
#include <signal.h>
#include <time.h>
int handle=0;
void handle_sigint(int sig)
{
    printf("Caught signal %d\n", sig);
    handle=1;
}



int main(int argc, char* argv[])
{
  int class_size;
  if(argc<2)
  {
    printf("default class size is 40\n");
  	class_size=40;
  }
  else if(argc==2)
  {
   class_size=atoi(argv[1]);      
  }

  int *arr1 = (int *)malloc(class_size* sizeof(int));
  int *process_arr= (int *)malloc(class_size* sizeof(int));
  pid_t pid,pid_wait;
  int shm_id,shm_id1,shm_id2,i,j,k,l,sum=0;
  key_t key=ftok("teacher.c",4);
  key_t key1=ftok("teacher.c",6);
  key_t key2=ftok("teacher.c",8);
  
  shm_id=shmget(key,sizeof(int),IPC_CREAT|0777);
  shm_id1=shmget(key1,sizeof(int),IPC_CREAT|0777);
  shm_id2=shmget(key2,sizeof(int),IPC_CREAT|0777);

  int *roll = (int *)malloc(sizeof(int));;
  roll= (int *) shmat(shm_id,NULL,0);
  *(roll) =-1;
  signal(SIGINT, handle_sigint);

  while(!handle)
  {
    roll= (int *) shmat(shm_id,NULL,0);
    if(*roll!=-1)
    {
      if(*roll > class_size)
      {
        printf("roll number is invalid\n");
        int *roll1= (int *) shmat(shm_id1,NULL,0);
        *roll1=100;
        //printf("valid_check %d\n",*roll1);
        shmdt(roll1);
      }
      else
      {
     *(arr1+*roll-1)=1;
      printf("roll given\n");
      int *roll1= (int *) shmat(shm_id1,NULL,0);
      *roll1=50;
      shmdt(roll1);
      int *process1= (int *) shmat(shm_id2,NULL,0);
      sleep(5);
      //printf("process is %d\n",*process1);
      *(process_arr+*roll-1)=*process1;  
      shmdt(process1);
      }
      *roll=-1;
    }
    shmdt(roll);

  }
printf("Attendance register\n");

int count=0;
for(i=0;i<class_size;i++)
{

  if(*(arr1+i)==1)
  {
    printf("Roll No %02d present marked by process number %d\n", i+1, *(process_arr+i));
    count=count+1;
  }  
  else
  {
    printf("Roll No %02d absent\n",i+1);

   }
}
printf("%d students are present\n",count);
shmctl(shm_id,IPC_RMID,NULL);
shmctl(shm_id1,IPC_RMID,NULL);
shmctl(shm_id2,IPC_RMID,NULL);
   
return 0;
}          