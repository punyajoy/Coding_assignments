#include <stdio.h> //perror()
#include <unistd.h> // pid_t, fork(),execve()
#include <stdlib.h>
#include <errno.h>     //perror()
#include <sys/types.h> //wait()
#include <sys/wait.h>  //wait()


int main(int argc,char* argv[])
{

	int n,i;
  int status;    // status to locate if execv has failed or not,status =-1 if error 
  int status1;    // used to collect the variable of pid_t wait(int *status);  status =-1 if abnormal exit
  pid_t pid,p1;     
  //char myargv[100];
  for(i=0; i<argc ; i++)
  {
      if(i>0)
      {    
          /*pid_t fork(void)*/
          p1=fork();
          if(p1==0)
          {
                         
          printf("process no %d i value %d\n",p1,i);
          char *myargv[] = {argv[i],NULL}; //sending a char_array hence adding null at the end s
          /*int execve(const char *filename, char *const argv[],
          char *const envp[]);*/
          int status = execve(argv[i], myargv, NULL);
          if(status == -1){
            perror("failure()");  //status is -1 if execve fails to start
          }
          exit(0); //this is to stop the child process from executing further and creating new childs
          }
          pid = wait(&status1);/*pid_t wait(int *status);*/
          printf("pid = %d status = %d\n", pid, status1);

      }

  }
  

  
	return 0;
}
