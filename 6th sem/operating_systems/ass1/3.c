#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{

    pid_t t;
    char p[100];
	FILE* in_file  = fopen("abc", "r"); // read only 
    if (in_file == NULL) 
    {   
              printf("Error! Could not open file\n"); 
              exit(-1); // must include stdlib.h 
    }   


    t=fork();
    if(t==0)
    {
       
       fscanf(in_file, "%s", p);  
       printf("file read from process2 element %s\n",p);

    }   
    else
    {
       //printf("process2");
       fscanf(in_file, "%s", p);  
       printf("file read from process1 element %s\n",p);
       //fclose(in_file);

    }

	return 0;
}
