#include <stdio.h>
#include <sys/types.h> /* for semget(2) ftok(3) semop(2) semctl(2) */
#include <sys/ipc.h> /* for semget(2) ftok(3) semop(2) semctl(2) */
#include <sys/sem.h> /* for semget(2) semop(2) semctl(2) */
#include <unistd.h> /* for fork(2) */
#include <stdlib.h> /* for exit(3) */
#include "stack.h"



int main()
{
    
    
    while(1)
    {
      int x;
      printf("This is a shared stack program\n"); 
      printf("Supported Number of stacks are 10\n");
      printf("Please do any of the following to do an operation in the set of STACKS\n");
      printf("1.Get some stack or access it\n");
      printf("2.Push a element\n");
      printf("3.Pop a element\n");
      printf("4.Remove the stack\n");
      printf("5.(Developers Option)See the status of a stack\n");
      printf("6.(Developers Option)See the status of a desc \n");
      printf("7.(Developers Option)See the whole stack desc\n");
      printf("8.Exit the program\n");
      
      scanf("%d",&x);
      switch (x)
      {
       case 1:
             {int key;
              int stacksize;
              int elementsize;
              printf("give the key\n");
              scanf("%d",&key);
              printf("give the stack size\n");
              scanf("%d",&stacksize);
              shstackget(key,4,stacksize);
              break;
             }
       case 2: 
              {
              int key;
              int element;
              printf("give the key\n");
              scanf("%d",&key);
              printf("give the element\n");
              scanf("%d",&element);
              shstackpush(key,element,4);
              break;}
       case 3:{
              int key;
              printf("give the key\n");
              scanf("%d",&key);
              shstackpop(key);
              break;}
       case 4:{
              int key;
              printf("give the key\n");
              scanf("%d",&key);
              shstackrm(key);
              break;}
       case 5:{
              int key;
              printf("give the key\n");
              scanf("%d",&key);
              printshstack(key);
              break;}
       case 6:
              {int i;
              printf("give the position of the stack_desc to be seen\n");
              scanf("%d",&i);
              printstackdesci(i);
              break;
              }
       case 7:printstackdesc();
              break;
       case 8:printf("EXITING\n");
              return 0;

       default:printf("option does not exist\n");
            break;     
      }
    
      


    }



    return 0;
}