#include <stdio.h> //perror()
#include <unistd.h> // pid_t, fork(),execve()
#include <stdlib.h>
#include <errno.h>     //perror()
#include <sys/types.h> //wait()
#include <sys/wait.h>  //wait()
/*
struct exec_files{
      char *arg_file;




}exe[1000];
*/

int main(int argc,char* argv[])
{

	int n,i;
  int status;   //status for handling normal and abnormal exit
  pid_t pid,p1; 
  for(i=0; i<argc ; i++)
  {
    if(i>0)
    {    
       /*pid_t fork(void)*/ 
       p1=fork();
       if(p1==0)   //only enter if the process id is that of a child
       {
                  
          printf("process no %d i value %d\n",p1,i);
          char *myargv[] = {argv[i],NULL}; //sending a char_array hence adding null at the end s
          /*int execve(const char *filename, char *const argv[],
                  char *const envp[]);*/
          int status = execve(argv[i], myargv, NULL); 
          if(status == -1){
            perror("failure()");    //status is -1 if execve fails to start 
          }
          exit(0); //this is to stop the child process from executing further and creating new childs

       }
      int status2;
      /*pid_t wait(int *status);*/
      pid = wait(&status2);
      /*WIFEXITED(status)
        returns true if the child terminated normally, that is, by call‐
        ing exit(3) or _exit(2), or by returning from main().
      */
      if(WIFEXITED(status2))    // this handles all the normal exit of the child processes
      {
        int status_child=WEXITSTATUS(status2);
        printf("pid = %d status=%d exited successfully\n", pid,status_child);  
      }
      /*WIFSIGNALED(status)
         returns true if the child process was terminated by a signal.
      */

      if(WIFSIGNALED(status2)) // this handles abnormal exit of the child in this case abnormal exit is caused due to segmentation fault
      {
        printf("pid = %d abnormal exit\n",pid);
      }      

    } 
      
  }

  
return 0;
}
