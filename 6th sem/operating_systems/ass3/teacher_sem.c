#include <stdio.h>  
#include <stdlib.h>    
#include <unistd.h>    //fork(),pid
#include <sys/ipc.h>   //shmget() 
#include <sys/shm.h>   //shmget()  shmat() shmdt() 
#include <sys/wait.h>  //wait()
#include <sys/types.h> //wait()  shmat() shmdt()
#include <signal.h>
#include <sys/sem.h>   /* for semget(2) semop(2) semctl(2) */



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

int handle=0;
//userdefined signal handler
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
   //int atoi(const char *nptr);
   class_size=atoi(argv[1]);      
  }
  
  int semid;
  int status;
  union semun {
    int              val;    /* Value for SETVAL */
    struct semid_ds *buf;    /* Buffer for IPC_STAT, IPC_SET */
    unsigned short  *array;  /* Array for GETALL, SETALL */
    struct seminfo  *__buf;  /* Buffer for IPC_INFO (Linux-specific) */
  } setvalArg;
  setvalArg.val = 1;


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

  int *arr1 = (int *)malloc(class_size* sizeof(int));

  int shm_id,i;0
  key_t key=ftok("teacher_sem.c",4);
  key_t mykey = ftok("teacher_sem.c", 5);
  
  if (mykey == -1) {
    perror("ftok() failed");
    exit(1);
  }
  //int semget(key_t key, int nsems, int semflg);
  semid = semget(mykey, NO_SEM, IPC_CREAT | 0777);
  if(semid == -1) {
    perror("semget() failed");
    exit(1);
  }

  // int semctl(int semid, int semnum, int cmd, ...);
  status = semctl(semid, 0, SETVAL, setvalArg);
  if(status == -1) {
    perror("semctl() failed");
    exit(1);
  }

  shm_id=shmget(key,sizeof(int),IPC_CREAT|0777);
  if(shm_id == -1) {
    perror("shmget() failed");
    exit(1);
  }

  int *roll = (int *)malloc(sizeof(int));
  //void *shmat(int shmid, const void *shmaddr, int shmflg);
  roll= (int *) shmat(shm_id,NULL,0);
  *(roll) =-1;
  //sighandler_t signal(int signum, sighandler_t handler);
  signal(SIGINT, handle_sigint);
  // handle is changed with Pressing "CTRL+C"
  while(!handle)
  {
    
    roll= (int *) shmat(shm_id,NULL,0);
    if(*roll!=-1)
    {
      P(semid);
      /****CRITICAL*****/
      *(arr1+*roll-1)=1;
      printf("roll given\n");
      *roll=-1;
      /****CRITICAL*****/
      V(semid);
    }
    shmdt(roll);

  }
printf("Attendance register\n");
//prints the attendance register array once it gets out of the loop
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
//int shmctl(int shmid, int cmd, struct shmid_ds *buf);
shmctl(shm_id,IPC_RMID,NULL);
//int semctl(int semid, int semnum, int cmd, ...);
status = semctl(semid, 0, IPC_RMID);
if(status==-1) 
{
  perror("semctl_error");
}    
return 0;
}