#include <stdio.h>
#include <stdlib.h>      
#include <sys/types.h>  //open(),ftruncate()
#include <sys/stat.h>    //open()
#include <fcntl.h>       //open()
#include <string.h>      //strcmp()
#include <unistd.h>     //ftruncate()
#include <sys/types.h>
#include <sys/wait.h>
#include <error.h>

#define LSH_TOK_BUFSIZE 64
#define LSH_TOK_DELIM " \t\r\n\a"


#define clear() printf("\033[H\033[J")



char **lsh_split_line(char *line,char *delim_string)
{
  int bufsize = LSH_TOK_BUFSIZE, position = 0;
  char **tokens = malloc(bufsize * sizeof(char*));
  char *token;

  if (!tokens) {
    fprintf(stderr, "lsh: allocation error\n");
    exit(EXIT_FAILURE);
  }

  token = strtok(line, delim_string);
  while (token != NULL) {
    tokens[position] = token;
    position++;

    if (position >= bufsize) {
      bufsize += LSH_TOK_BUFSIZE;
      tokens = realloc(tokens, bufsize * sizeof(char*));
      if (!tokens) {
        fprintf(stderr, "lsh: allocation error\n");
        exit(EXIT_FAILURE);
      }
    }

    token = strtok(NULL, delim_string);
  }
  tokens[position] = NULL;
  return tokens;
}

void flush()
{
  int c;
  while ((c = getchar()) != '\n' && c != EOF);
        
}
int exe_comm(char *command)
{
         char **sub_tokens;
         sub_tokens=lsh_split_line(command," ");
         
         if(strcmp(sub_tokens[0],"cd")==0)
         {
           int c=chdir(sub_tokens[1]);
           if(c == -1)
           {
             perror("Failure()");
             return 0;
           }
           else
           {
            return 1;
           }
           //printf("hello\n");
         }
         else if(strcmp(sub_tokens[0],"pwd")==0)
         {
           //printf("hello");
           char cwd[1024];
           if (getcwd(cwd, sizeof(cwd)) != NULL)
           {
              fprintf(stdout, "Current working dir: %s\n", cwd);
              return 1;
           }
           else
           {
              perror("getcwd() error");
              return 0;
            }
         }
         else if (strcmp(sub_tokens[0],"clear")==0)
         {
            clear();
         }
         else if(strcmp(sub_tokens[0],"exit") == 0)
         {
            printf("exiting the program\n");
            exit(0);

         }
         else
         {  
           pid_t p1,pid;
           char src[50];
           char dest1[50];
           
           //strcpy(src,  "This is source");
           p1=fork();
           if(p1==0)
           {

                      /*int execve(const char *filename, char *const argv[],
                  char *const envp[]);*/
          
            //char *arg[]={sub_tokens[0],NULL};
            
            strcpy(dest1, "/bin/");
            strcat(dest1,sub_tokens[0]);
            sub_tokens[0]=dest1;
            //printf("Final destination string : |%s|\n", sub_tokens[1]);
   
            //printf("status 1\n");
            int status = execve(sub_tokens[0],sub_tokens, NULL); 
            if(status == -1){
               perror("failure()");    //status is -1 if execve fails to start

               }
              
            exit(0);
            }
            int status2;
            /*pid_t wait(int *status);*/
            pid = wait(&status2);
            if(WIFEXITED(status2))    // this handles all the normal exit of the child processes
           {
                int status_child=WEXITSTATUS(status2);
                printf("pid = %d status=%d exited successfully\n", pid,status_child);
                return 1;  
           }
           else
           {
            return 0;
           }

            
         }
 


}

int main(){
         


     while(1)
     {
     	  int command_flag[100];
        char cwd[1024];
        if (getcwd(cwd, sizeof(cwd)) == NULL)
        {
              perror("getcwd() error");
              return 0;
        }
              
        strcat(cwd,"~mysh>");
        /*
        ; is 1   //seq
        && is 2  //and
        || is 3  //or
        | is 4  //pipe
        > is 5  //output redirection  
        < is 6  //input redirection
         */
        
        printf("\n%s",cwd);
        char * pch;

        //scanf("%s",command);
        char *line=NULL;
        char line_copy[200];
        //char *line;
        ssize_t bufsize = 0; // have getline allocate a buffer for us
        getline(&line, &bufsize, stdin);
        strcpy(line_copy,line);
        //scanf("%24[^\n]", line); 
        printf("the line is %s \n",line_copy);
        
        

        char **tokens;
        tokens=lsh_split_line(line,";|&><\n");
                
        int i=0;
        int sum=0;
        while(tokens[i]!=NULL)
        {

          int h;
          printf("the word %s\n",tokens[i]);
          printf("the sum till now %d\n",sum);
          if(i!=0)
          {
                
              if(line_copy[sum]=='|')
              {
                 if(line_copy[sum+1]=='|')
                 {
                 printf("the chracter is %c\n",line[sum+1]);
                 printf("the or\n");
                 command_flag[i-1]=3;
                 sum=sum+1;
                 }
                 else
                 {
                  printf("the chracter is %c\n",line[sum+1]);
                  printf("the pipe\n");
                  command_flag[i-1]=4;
                  
                 }
              }
              else if(line_copy[sum]=='&')
              { 
                if(line_copy[sum+1]=='&') 
                {
                printf("the chracter is %c\n",line_copy[sum]);
                printf("the and\n");
                command_flag[i-1]=2;
                sum=sum+1;
                }
                else
                {
                  printf("invalid command\n");
                  exit(0);
                }
              }
              else if(line_copy[sum]==';')
              {
                printf("the chracter is %c\n",line_copy[sum]);
                printf("the seq\n");
                command_flag[i-1]=1;
              }
              else if(line_copy[sum]=='>')
              {
                printf("the chracter is %c\n",line_copy[sum]);
                printf("the output_redirection\n");
                command_flag[i-1]=5; 
              }
              else if(line_copy[sum]=='<')
              {
                printf("the chracter is %c\n",line_copy[sum]);
                printf("the input_redirection\n");
                command_flag[i-1]=6; 
              }
              else if(line_copy[sum]=='\0')
              {
                command_flag[i-1]=1; 
              }  

          }
          
          for(h=0;h<(int)sizeof(tokens[i]);h++)
          {
              printf("chracter %c\n",tokens[i][h]);
              if(tokens[i][h]=='\0')
                 break;
          }
          

          if(i==0)   
            sum+=(h);
          else
            sum+=h+1;
          i++;

        }
        command_flag[i-1]=1;  
         //printf("command %d is %s\n",i,tokens[i]); 
        i=0;
        int status_flag=0;
        while(tokens[i]!=NULL)
        {
          if(i>0&&command_flag[i-1]==2)
          {
              if(status_flag==1)
              {
                status_flag=exe_comm(tokens[i]);  
                
              }
              else
              {
                printf("previous command failed no further execution");
                exit(0);
              }  
   
          }
          if(i>0&&command_flag[i-1]==3)
          {
             if(status_flag==0)
              {
                status_flag=exe_comm(tokens[i]);  
                
              }
              else
              {
                printf("previous command successful no further execution");
                exit(0);
              }

          }
          else if(command_flag[i]==1)
          {
             status_flag=exe_comm(tokens[i]);
          }
          else if(command_flag[i]==4)
          {
           
            int fd[2];
            pid_t childPid;
            if (pipe(fd) != 0)
               perror("failed to create pipe");

            if ((childPid = fork()) == -1)
               perror("failed to fork");

            if (childPid == 0)
            {
                close(1);
                close(fd[0]);
                //close(fd[1]);
                dup(fd[1]);

                exe_comm(tokens[i]);
                perror("failed to exec command 1");
                printf("printf writeend%d\n",fd[1]);

            }
            else
            {
                close(0);
                //close(fd[0]);
                close(fd[1]);
                dup(fd[0]);
                exe_comm(tokens[i+1]);
                perror("failed to exec command 2");
                printf("printf readend %d\n",fd[0]);
            }
            


            int status2;
            /*pid_t wait(int *status);*/
            pid_t pid;
            pid = wait(&status2);
            if(WIFEXITED(status2))    // this handles all the normal exit of the child processes
           {
                int status_child=WEXITSTATUS(status2);
                printf("\npid = %d status=%d exited successfully\n", pid,status_child);  
           }
           i++;  

          }
          else if(command_flag[i]==5)
          {
               
               //dup2(1,fd[1]);
               pid_t pid;
               pid=fork();
               if(pid==0)
               {
                 int fd;
                 close(1);
                 fd=open(tokens[i+1],O_RDWR,S_IRWXU);
                 status_flag=exe_comm(tokens[i]);
                 close(fd);
                 exit(0);
               }
               int status;
               wait(&status);
               //dup2(fd[1],1);
               //close(fd[1]);
               i++;

          }
          else if(command_flag[i]==6)
          {
               //dup2(0,fd[1]);
               pid_t pid;
               pid=fork();
               if(pid==0)
               {
                int fd;
                close(0);
                fd=open(tokens[i+1],O_RDONLY,S_IRWXU);
                status_flag=exe_comm(tokens[i]);
                close(fd);
               }
               int status;
               wait(&status);
               

               //dup2(fd[1],0);
               //close(fd[1]);
               i++;

            



          }



         i++;
 
        }
        //flush();                   
  
     }








return 0;
}