#include <stdio.h>
#include <sys/types.h> /* for semget(2) ftok(3) semop(2) semctl(2) */
#include <sys/ipc.h> /* for semget(2) ftok(3) semop(2) semctl(2) */
#include <sys/sem.h> /* for semget(2) semop(2) semctl(2) */
#include <unistd.h> /* for fork(2) */
#include <stdlib.h> /* for exit(3) */
#include <sys/shm.h>   //shmget()  shmat() shmdt() 
#include <sys/wait.h>  //wait()
#include <string.h>
#define MAX_STACK 10

typedef struct{
      key_t stackKey;
      int data_size;
      char type;
      int stack_size;
      int stack_top;
      int elements_no;
      int free1;
}stackdesc;
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

int shstackpush(int key,void *push_element,int element_size);
void printstackdesc();
void printstackdesci(int i);


int shstackget(int key,int element_size,int stack_size,char type)
{
	int i,shm_id,shm_id1;
    key_t key1=ftok("user_stack.c",4);
    shm_id1=shmget(key1,MAX_STACK*sizeof(stackdesc),IPC_CREAT|0777);
    //stackdesc *shared_stack = (stackdesc *)malloc(MAX_STACK*sizeof(stackdesc));
    
    stackdesc *shared_stack=(stackdesc* )shmat(shm_id1,NULL,0);
   
    for(i=0;i<MAX_STACK;i++)
    {
       if((*(shared_stack+i)).stackKey==key)
       {
          if((*(shared_stack+i)).type==type)
          {
          printf("the stack is present go access the stack\n");
          shmdt(shared_stack);
          return 1;
          }
          else
          {
          printf("stack data type mismatch please give the correct details\n");
          shmdt(shared_stack);
          return -1;
          }

       }

    }
    for(i=0;i<MAX_STACK;i++)
    {
       if((*(shared_stack+i)).free1==0)
       {

          printf("the stack is free\n");
          //shm_id=shmget(key,stack_size*element_size,IPC_CREAT|0777);
          (*(shared_stack+i)).stackKey=key;
          (*(shared_stack+i)).data_size=element_size;
          (*(shared_stack+i)).stack_size=stack_size;
          (*(shared_stack+i)).stack_top = -1;
          (*(shared_stack+i)).elements_no = 0;
          (*(shared_stack+i)).free1=1;
          (*(shared_stack+i)).type=type;
          
          //shstackpush(key,0,element_size);
          shmdt(shared_stack);     
          return 1;

       }

    }
    

}
int shstackpush(int key,void *push_element,int element_size)
{
   int i,shm_id,shm_id1;
   key_t key1=ftok("user_stack.c",4);
   shm_id1=shmget(key1,MAX_STACK*sizeof(stackdesc),IPC_CREAT|0777);
   //stackdesc *shared_stack = (stackdesc *)malloc(MAX_STACK*sizeof(stackdesc));
   stackdesc *shared_stack=(stackdesc* )shmat(shm_id1,NULL,0);
   int flag=0;
   for(i=0;i<MAX_STACK;i++)
   {
       if((*(shared_stack+i)).stackKey==key)
       {
          //printf("the stack is present go access the stack\n");
          
          int whstack_size=(*(shared_stack+i)).stack_size;
          int whno_of_elements=(*(shared_stack+i)).elements_no;
          int whdata_size=(*(shared_stack+i)).data_size;
          int whstack_top=(*(shared_stack+i)).stack_top;
          shm_id=shmget(key,whstack_size*whdata_size,IPC_CREAT|0777);   
          //int *stack_ptr=(int *)malloc(whstack_size*element_size);
          void *stack_ptr=shmat(shm_id,NULL,0);
          whno_of_elements++;
          if(whno_of_elements>whstack_size)
          {
             printf("Error():the stack is full get access of some other stack\n");


          }
          else{
          whstack_top++;
          void* target = (char*)stack_ptr+(whstack_top*whdata_size);
          memcpy(target, push_element, whdata_size);
          (*(shared_stack+i)).elements_no=whno_of_elements;
          (*(shared_stack+i)).stack_top=whstack_top;
          }
          shmdt(stack_ptr);
          shmdt(shared_stack);
          flag=1;
          break;
       }

   }  
   if(flag==0)
   {
      printf("Error:the shared stack with the key %d does not exist\n",key);
      printf("Solution:Use shstackget to create a new stack\n");
      return -1;
   }
}
int shstackpop(int key,void *source)
{
   int i,shm_id,shm_id1;
   key_t key1=ftok("user_stack.c",4);
   shm_id1=shmget(key1,MAX_STACK*sizeof(stackdesc),IPC_CREAT|0777);
   //stackdesc *shared_stack = (stackdesc *)malloc(MAX_STACK*sizeof(stackdesc));
   stackdesc *shared_stack=(stackdesc* )shmat(shm_id1,NULL,0);
   int flag=0;
   for(i=0;i<MAX_STACK;i++)
   {
       if((*(shared_stack+i)).stackKey==key)
       {
          //printf("the stack is present go access the stack\n");
          
          int whstack_size=(*(shared_stack+i)).stack_size;
          int whno_of_elements=(*(shared_stack+i)).elements_no;
          int whdata_size=(*(shared_stack+i)).data_size;
          int whstack_top=(*(shared_stack+i)).stack_top;
          shm_id=shmget(key,whstack_size*whdata_size,IPC_CREAT|0777);   
          //int *stack_ptr=(int *)malloc(whstack_size*element_size);
          void *stack_ptr=shmat(shm_id,NULL,0);
          whno_of_elements--;
          if(whno_of_elements < 0)
          {
             printf("Error():the stack is empty element cannot be popped\n");
          }
          else
          {
          void* target = (char*)stack_ptr+(whstack_top*whdata_size);
          memcpy(target, source, whdata_size);

          //printf("the popped element is %d\n",*(stack_ptr+whstack_top));
          whstack_top--;
          (*(shared_stack+i)).elements_no=whno_of_elements;
          (*(shared_stack+i)).stack_top=whstack_top;
          }
          shmdt(stack_ptr);   
          shmdt(shared_stack);
          flag=1;
          return whdata_size;
          break;
       }

   }  
   if(flag==0)
   {
      printf("Error:the shared stack with the key %d does not exist\n",key);
      printf("Solution:Use shstackget to create a new stack\n");
      return -1;
   }  

}


int shstackrm(int key)
{
  int i,shm_id,shm_id1;
   key_t key1=ftok("user_stack.c",4);
   shm_id1=shmget(key1,MAX_STACK*sizeof(stackdesc),IPC_CREAT|0777);
   //stackdesc *shared_stack = (stackdesc *)malloc(MAX_STACK*sizeof(stackdesc));
   stackdesc *shared_stack=(stackdesc* )shmat(shm_id1,NULL,0);
   int flag=0;
   for(i=0;i<MAX_STACK;i++)
   {
       if((*(shared_stack+i)).stackKey==key)
       {
          
          int whstack_size=(*(shared_stack+i)).stack_size;
          int whdata_size=(*(shared_stack+i)).data_size;
          shm_id=shmget(key,whstack_size*whdata_size,IPC_CREAT|0777);   
          (*(shared_stack+i)).elements_no=0;
          (*(shared_stack+i)).stack_top=0;
          (*(shared_stack+i)).stackKey=0;
          (*(shared_stack+i)).data_size=0;
          (*(shared_stack+i)).free1=0;
          (*(shared_stack+i)).stack_size=0;
          shmctl(shm_id,IPC_RMID,NULL);
          shmdt(shared_stack);
          flag=1;
          break;
       }

   }  
   if(flag==0)
   {
      printf("Error:the shared stack with the key %d does not exist\n",key);
      printf("Solution:Use shstackget to create a new stack\n");
      return -1;
   }  

}

void printstackdesc()
{
   int i,shm_id1;
   key_t key1=ftok("user_stack.c",4);
   shm_id1=shmget(key1,MAX_STACK*sizeof(stackdesc),IPC_CREAT|0777);
   //stackdesc *shared_stack = (stackdesc *)malloc(MAX_STACK*sizeof(stackdesc));
   stackdesc *shared_stack=(stackdesc* )shmat(shm_id1,NULL,0);
   for(i=0;i<MAX_STACK;i++)
   {
    
          printf("the key of %d desc is %d\n",i,(*(shared_stack+i)).stackKey);
          printf("the data_size of %d desc is %d\n",i,(*(shared_stack+i)).data_size);
          printf("the stack_size of %d desc is %d\n",i,(*(shared_stack+i)).stack_size);
          printf("the stack_top of %d desc is %d\n",i,(*(shared_stack+i)).stack_top);
          printf("the elements_no of %d desc is %d\n",i,(*(shared_stack+i)).elements_no);
          printf("the free of %d desc is %d\n",i,(*(shared_stack+i)).free1);
  
    
   }
  shmdt(shared_stack);     
}
void printstackdesci(int i)
{
   int shm_id1;
   key_t key1=ftok("user_stack.c",4);
   shm_id1=shmget(key1,MAX_STACK*sizeof(stackdesc),IPC_CREAT|0777);
   //stackdesc *shared_stack = (stackdesc *)malloc(MAX_STACK*sizeof(stackdesc));
   stackdesc *shared_stack=(stackdesc* )shmat(shm_id1,NULL,0);
   printf("the key of %d desc is %d\n",i,(*(shared_stack+i)).stackKey);
   printf("the data_size of %d desc is %d\n",i,(*(shared_stack+i)).data_size);
   printf("the stack_size of %d desc is %d\n",i,(*(shared_stack+i)).stack_size);
   printf("the stack_top of %d desc is %d\n",i,(*(shared_stack+i)).stack_top);
   printf("the elements_no of %d desc is %d\n",i,(*(shared_stack+i)).elements_no);
   printf("the free of %d desc is %d\n",i,(*(shared_stack+i)).free1);
   shmdt(shared_stack);     
          
}






int printshstack(int key)
{
   int i,shm_id,shm_id1;
   key_t key1=ftok("user_stack.c",4);
   shm_id1=shmget(key1,MAX_STACK*sizeof(stackdesc),IPC_CREAT|0777);
   //stackdesc *shared_stack = (stackdesc *)malloc(MAX_STACK*sizeof(stackdesc));
   stackdesc *shared_stack=(stackdesc* )shmat(shm_id1,NULL,0);
   int flag=0;
   for(i=0;i<MAX_STACK;i++)
   {
       if((*(shared_stack+i)).stackKey==key)
       {
          printf("the stack is present go access the stack\n");
          int whstack_size=(*(shared_stack+i)).stack_size;
          int whno_of_elements=(*(shared_stack+i)).elements_no;
          int whdata_size=(*(shared_stack+i)).data_size;
          int whstack_top=(*(shared_stack+i)).stack_top;
          shm_id=shmget(key,whstack_size*whdata_size,IPC_CREAT|0777);   
          int *stack_ptr=(int *)malloc(whstack_size*whdata_size);
          stack_ptr=(int *)shmat(shm_id,NULL,0);
          if(whstack_top==-1)
          {
              printf("Error:the stack is empty\n");

           }
          else
          {
          for(i=whstack_top;i>=abs(whno_of_elements-whstack_top-1);i--)
              printf("the %d stack element %d\n",i,*(stack_ptr+i));

          }
          shmdt(stack_ptr);
          shmdt(shared_stack);
          flag=1;
          break;

       }

   }  
   if(flag==0)
   {
      printf("Error:the shared stack with the key %d does not exist\n",key);
      printf("Solution:Use shstackget to create a new stack\n");
      return -1;
   }
   
}
