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
  char roll_number[3]={0}; // in case of single character input
  fd_set input_set;
  //printf("hello");
  int shm_id,shm_id1,shm_id2,i,j,k,l,sum=0;
  key_t key=ftok("teacher.c",4);
  key_t key1=ftok("teacher.c",6);
  key_t key2=ftok("teacher.c",8);
  
  shm_id=shmget(key,sizeof(int),IPC_CREAT|0777);
  shm_id1=shmget(key1,sizeof(int),IPC_CREAT|0777);
  shm_id2=shmget(key2,sizeof(int),IPC_CREAT|0777);


  int *roll= (int *) shmat(shm_id,NULL,0);
  *(roll) =-1;
  shmdt(roll);
  roll= (int *) shmat(shm_id,NULL,0);
  if(*roll==-1)
  {
       printf("the roll number:");
       scanf("%d",roll);
       sleep(1);
       int *roll1= (int *) shmat(shm_id1,NULL,0);
       //printf("valid_checker %d\n", *roll1);
       if(*roll1==100)
       {
           printf("the roll number is not valid\n");
       }
       else if(*roll1==50)
       {
           printf("the roll number is valid\n");
          int *process1= (int *) shmat(shm_id2,NULL,0);
          pid_t pid_student= getpid();
          *(process1) = pid_student;
          shmdt(process1);
   

       }
       shmdt(roll1);  	
       pid_t pid_student= getpid();
       printf("pid of the process %d\n",pid_student);
  }
  shmdt(roll);     

      

return 0;
}