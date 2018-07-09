#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


int fact(int n)
{
 int c,fact = 1;
 if(n==0)
 {
  fact=1;
 }
 else
 {
 for (c = 1; c <= n; c++)
   fact = fact * c;
 }
  
  return fact;
}

int main()
{

	int n,i,count=0;
	printf("give the number of new process to be created:");
  scanf("%d",&n);
  int arr[100];
  printf("give the elements");
  for(i=0;i<n;i++)
  {
    scanf("%d\n",&arr[i]);
  }


  for(i=0; i<n+1 ; i++)
    {
       if(fork()==0)
       {
         if(i>0)
         {        
          int t;
          t=fact(arr[i]); 
          printf("process %d factorial %d\n", i,t);
          }
          exit(0);
          
       }

    }
    
    
	return 0;
}
