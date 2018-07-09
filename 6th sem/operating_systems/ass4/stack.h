#include <stdio.h>
#include <sys/types.h> /* for semget(2) ftok(3) semop(2) semctl(2) */
#include <sys/ipc.h> /* for semget(2) ftok(3) semop(2) semctl(2) */
#include <sys/sem.h> /* for semget(2) semop(2) semctl(2) */
#include <unistd.h> /* for fork(2) */
#include <stdlib.h> /* for exit(3) */
#define MAX_STACK 10
/*
typedef struct{
      key_t stackKey;
      int data_size;
      int stack_size;
      void *stack_top;
      int elements_no;
      int free1;
}stackdesc;
*/


void printstackdesc();
void printstackdesci(int);
int shstackpush(int,int,int);
int shstackget(int,int,int);
int shstackpop(int);
int shstackrm(int);
int printshstack(int);
