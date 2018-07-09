#include <stdio.h>  
#include <stdlib.h>    
#include <unistd.h>    //fork(),pid
#include <sys/ipc.h>   //shmget() 
#include <sys/shm.h>   //shmget()  shmat() shmdt() 
#include <sys/wait.h>  //wait()
#include <sys/types.h> //wait()  shmat() shmdt()
#include <sys/time.h>
#include <sys/sem.h>   /* for semget(2) semop(2) semctl(2) */

#define WAIT 1


#define NO_SEM  1

#define P(s) semop(s, &Pop, 1);
#define V(s) semop(s, &Vop, 1);
/*The  elements of this structure are of type struct sembuf,
       containing the following members:

           unsigned short sem_num;  /* semaphore number */
//           short          sem_op;   /* semaphore operation */
 //          short          sem_flg;  /* operation flags */

struct sembuf Pop;
struct sembuf Vop;


int main()
{
  int semid;

  int status;

   /* struct sembuf has the following fields */
  //unsigned short sem_num;  /* semaphore number */
        //short          sem_op;   /* semaphore operation */
        //short          sem_flg;  /* operation flags */

  Pop.sem_num = 0;
  Pop.sem_op = -1;
  Pop.sem_flg = SEM_UNDO;

  Vop.sem_num = 0;
  Vop.sem_op = 1;
  Vop.sem_flg = SEM_UNDO;



  //printf("hello");
  int shm_id;
  //key_t ftok(const char *pathname, int proj_id);

  key_t key=ftok("teacher_sem.c",4);
  key_t mykey = ftok("teacher_sem.c", 5);
  //int semget(key_t key, int nsems, int semflg);
  semid = semget(mykey, NO_SEM, IPC_CREAT | 0777);
  //int shmget(key_t key, size_t size, int shmflg);
  shm_id=shmget(key,sizeof(int),IPC_CREAT|0777);
  int *roll = (int *)malloc(sizeof(int));
  //sighandler_t signal(int signum, sighandler_t handler);

  roll= (int *) shmat(shm_id,NULL,0);
  if(*roll==-1)
  {
       P(semid);
       /****CRITICAL*****/
       printf("the roll number:");
       scanf("%d",roll);
       /****CRITICAL*****/
       V(semid);     	
         
  }
  //int shmdt(const void *shmaddr);
  shmdt(roll);     
   
      

return 0;
}