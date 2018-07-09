#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{

    pid_t t;
    char p[100];
    int integer=100;
	FILE* in_file  = fopen("abc1", "w"); // read only 
    if (in_file == NULL) 
    {   
              printf("Error! Could not open file\n"); 
              exit(-1); // must include stdlib.h 
    }   


    t=fork();
    if(t==0)
    {
       
       fprintf(in_file, "this is a test 2%d\n", integer);  
       
    }   
    else
    {
       //printf("process1");
       //fclose(in_file);
      fprintf(in_file, "this is a test 1 %d\n", integer);
    }

	return 0;
}
