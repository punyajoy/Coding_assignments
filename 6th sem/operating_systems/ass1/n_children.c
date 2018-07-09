#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{

	int n,i;
	printf("give the number of new process to be created:");
	scanf("%d",&n);
    for(i=0; i<n+1 ; i++)
    {
       if(fork()==0)
       {
          printf("hello world\n");
          exit(0);
       }

    }
    

	return 0;
}
