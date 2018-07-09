
#include <stdio.h>   
#include <stdlib.h>    
#include <unistd.h>    //fork(),pid
#include <sys/ipc.h>   //shmget() 
#include <sys/shm.h>   //shmget()  shmat() shmdt() 
#include <sys/wait.h>  //wait()
#include <sys/types.h> //wait()  shmat() shmdt()


//int shmget(key_t key, size_t size, int shmflg); shmget() command 
/*the function to take in an array of integers where the starting array pointer  is passed along with rows and columns*/
void get_array(int m, int n, int *arr)
{
  int i, k;
  
  for(i = 0; i < m; i++){
    for(k = 0; k < n; k++){
       scanf("%d", (arr+i*n+k));
       
    }
  }
  
}
/*the function to print an array of integers where the starting array pointer is passed along with rows and columns*/

void print_array(int m, int n, int *arr)
{
  int i, k;
  
  for(i = 0; i < m; i++){
    for(k = 0; k < n; k++){
       printf("%d ", *(arr+i*n+k));    // print value in from  array.
    }
    printf("\n");
  }
  
}

void cpy_array(int m, int n, int *arr,int *arr1)
{
  int i, k;
  
  for(i = 0; i < m; i++){
    for(k = 0; k < n; k++){
       *(arr+i*n+k)=*(arr1+i*n+k);    
    }
    //printf("\n");
  }
  
}




int check_array(int m, int n, int *arr,int d)
{
  int i, j, k,l;
  
  for(i = 0; i < m; i++){
    for(j = 0; j < n; j++){
        
        for(k = 0; k < m; k++){
          for(l = 0; l < n; l++){
              if(!(i==k && j==l))
              {
                  if(abs(*(arr+i*n+j)-*(arr+k*n+l))<d)
                      return 1;                   

              }     
      }
     }
    }
   }
  return 0;
}


int main()
{
  pid_t pid,pid_wait;
  int shm_id,r,c,i,j,k,l,sum=0;
  printf("give rows and cols of matrix");
  scanf("%d",&r);
  scanf("%d",&c);

  shm_id=shmget(IPC_PRIVATE,r*c*sizeof(int),IPC_CREAT|0777);
  int *arr1 = (int *)malloc(r * c * sizeof(int)); //this is the memory allocated for the array that is used as input from user
  int *resarr = (int *)malloc(r * c * sizeof(int));  //this is the memory allocated for collecting the shared memory 
    
  printf("give elements of matrix:");
  get_array(r,c,arr1);
  printf("\n");                                 //get the elements of the array
  print_array(r,c,arr1);                       //print the array to show the elements in the array
  int diff;
  printf("give the minimal difference(+ve) possible:");
  scanf("%d",&diff);
  if(diff<=0)
  {
    diff=1;
    printf("since %d is less then one holding default value that is 1\n",diff);

  }
  int flag_run=0;
  while(!check_array(r,c,arr1,diff))
  { 
    flag_run=1;
    for(i=0;i<r;i++)
    {
      for(j=0;j<c;j++)
      {
        //pid_t fork(void);
        pid=fork();
        //void *shmat(int shmid, const void *shmaddr, int shmflg);
        if(pid==0)
        {
          resarr= (int *) shmat(shm_id,NULL,0);
          //printf("%d and %d\n",i,j);
          int count=0;
          //each element is taken and neighbouring elements are calculated   
          for(k=i-1;k<i+2;k++)
          {
      	   for(l=j-1;l<j+2;l++)
      	   {
      	     	// this checks whether the neihbouring elements exists or not and adds it to the sum
              if(!(k<0|k>r-1|l<0|l>c-1))
              {
              //printf("%d\n",*(arr1+k*c+l));
              sum+=*(arr1+k*c+l);
              //printf("the number %d\n",*(arr1+k*c+l));
              count++;
              }
            }
          }
        //printf("%d\n",sum);
          //print_array(r,c,arr1);                       //print the array to show the elements in the array

          *(resarr+i*c+j) = sum/count;
          //printf("the number %d\n",*(resarr+i*c+j));
          //printf("sum %d\n",sum);
              
          shmdt(resarr);   
          exit(0);    // to stop execution of the child 
        }
        sum = 0; // sum is initialised to 0 in each run
        int status2;
        //pid_t wait(int *status);
        pid_wait = wait(&status2);

      }


    }
    
    resarr= (int *) shmat(shm_id,NULL,0);
    //print_array(r,c,arr1);
    cpy_array(r, c, arr1,resarr);
    printf("intermidiate step\n");
    print_array(r,c,arr1);
    shmdt(resarr);
    //printf("hello\n");
  } 


  if(flag_run==0)
  {
    printf("Result for multiple distributed averaging:\n");
    print_array(r,c,arr1);
     
  }
  else
  {
    resarr= (int *) shmat(shm_id,NULL,0);
    printf("Result for multiple distributed averaging:\n");
    print_array(r,c,resarr);
    //void *shmat(int shmid, const void *shmaddr, int shmflg);
    shmdt(resarr);
  
  }
  //int shmctl(int shmid, int cmd, struct shmid_ds *buf);
  shmctl(shm_id,IPC_RMID,NULL);
    
  




 return 0;
 } 