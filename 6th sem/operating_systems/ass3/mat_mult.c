#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>    //fork(),pid
#include <sys/ipc.h>   //shmget 
#include <sys/shm.h>   //shmget 
#include <sys/wait.h>
#include <sys/types.h>
//int shmget(key_t key, size_t size, int shmflg);

void get_array(int m, int n, int *arr)
{
  int i, k;
  
  for(i = 0; i < m; i++){
    for(k = 0; k < n; k++){
       scanf("%d", (arr+i*m+k));
       
    }
  }
  
}
void print_array(int m, int n, int *arr)
{
  int i, k;
  
  for(i = 0; i < m; i++){
    for(k = 0; k < n; k++){
       printf("%d ", *(arr+i*m+k));    // print value in from  array.
    }
    printf("\n");
  }
  
}




int main()
{
  pid_t pid,pid_wait;
  int shm_id,r,c,r1,c1,i,j,k,sum=0;
  printf("give rows and cols of matrix1");
  scanf("%d",&r);
  scanf("%d",&c);
  printf("give rows and cols of matrix2");
  scanf("%d",&r1);
  scanf("%d",&c1);
  if(c != r1)
  {
    printf("multiplication is not possible\n");
    exit(0);
  }
  shm_id=shmget(IPC_PRIVATE,r*c1*sizeof(int),IPC_CREAT|0777);
  int *arr1 = (int *)malloc(r * c * sizeof(int));
  int *arr2 = (int *)malloc(r1 * c1 * sizeof(int));
  int *resarr = (int *)malloc(r * c1 * sizeof(int));
  get_array(r,c,arr1);
  get_array(r1,c1,arr2);
  print_array(r,c,arr1);
  print_array(r1,c1,arr2);
  

  for (i = 0; i < r; i++) {
      for (j = 0;  j< c1; j++) {
      	pid=fork();
      	resarr= (int *) shmat(shm_id,NULL,0);
      	if(pid==0)
      	{
        for (k = 0; k < c; k++) {
          sum = sum + *(arr1+i*c+k) * *(arr2+j+k*c1);
        }
        //printf("%d\n",sum);
        *(resarr+i*c+j) = sum;
        shmdt(resarr);
        exit(0);
        }
        sum = 0;
        int status2;
        pid_wait = wait(&status2);

      }
    }
  resarr= (int *) shmat(shm_id,NULL,0);    
  print_array(r,c1,resarr);
  shmdt(resarr);
  shmctl(shm_id,IPC_RMID,NULL);




  /* 
  
  
  
  for(i=0; i< ; i++)
  {
      if(i>0)
      {    
       p1=fork();
       if(p1==0)
       {
                  
          printf("process no %d i value %d\n",p1,i);
          char *myargv[] = {argv[i],NULL};
          int status = execve(argv[i], myargv, NULL);
          if(status == -1){
            perror("failure()");
          }
          exit(0);
       }
         int status2;
        

       }
      
  }  













*/
return 0;
}