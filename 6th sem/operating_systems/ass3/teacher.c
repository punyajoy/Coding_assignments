#include <stdio.h>  
#include <stdlib.h>    
#include <unistd.h>    //fork(),pid
#include <sys/ipc.h>   //shmget() 
#include <sys/shm.h>   //shmget()  shmat() shmdt() 
#include <sys/wait.h>  //wait()
#include <sys/types.h> //wait()  shmat() shmdt()
#include <signal.h>
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

  pid_t pid,pid_wait;
  int shm_id,r,c,i,j,k,l,sum=0;
  key_t key=ftok("mat_avg.c",4);
  shm_id=shmget(key,sizeof(int),IPC_CREAT|0777);
  int *roll;
  roll= (int *) shmat(shm_id,NULL,0);
  *(roll) =-1;
  signal(SIGINT, handle_sigint);

  while(!handle)
  {
    roll= (int *) shmat(shm_id,NULL,0);
    if(*roll!=-1)
    {
      *(arr1+*roll-1)=1;
      printf("roll given\n");
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
    printf("Roll No %02d present\n", i+1);
    count=count+1;
  }  
  else
  {
    printf("Roll No %02d absent\n",i+1);

   }
}
printf("%d students are present\n",count);
shmctl(shm_id,IPC_RMID,NULL);
   
return 0;
}