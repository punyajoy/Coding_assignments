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
  struct timeval  timeout;
  //printf("hello");
  int shm_id,r,c,i,j,k,l,sum=0,ready_for_reading=0,read_bytes = 0;
  key_t key=ftok("mat_avg.c",4);
  shm_id=shmget(key,sizeof(int),IPC_CREAT|0777);
  int *roll = (int *)malloc(sizeof(int));;
  roll= (int *) shmat(shm_id,NULL,0);
  *(roll) =-1;
  shmdt(roll);
  
  while(1)
  {
    roll= (int *) shmat(shm_id,NULL,0);
    if(*roll==-1)
    {
    FD_ZERO(&input_set );
    /* Listen to the input descriptor */
    FD_SET(0, &input_set);
    timeout.tv_sec = WAIT;    // WAIT seconds
    timeout.tv_usec = 0;    // 0 milliseconds
    ready_for_reading = select(1, &input_set, NULL, NULL, &timeout);
    if (ready_for_reading) {
        read_bytes = read(0, roll_number, 3);
        if(roll_number[read_bytes-1]=='\n'){
        --read_bytes;
        roll_number[read_bytes]='\0';
        }
        if(read_bytes==0){
            printf("You just hit enter\n");
        } else {
            printf("Read, %d bytes from input : %s \n", read_bytes, roll_number);
            printf("the number is %d\n",atoi(roll_number));
            *roll = atoi(roll_number);
            break;
        }
        	
        
       }    
   }
   shmdt(roll);     

  }    

return 0;
}