// Server side C/C++ program to demonstrate Socket programming
#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <wait.h>

int main(){
    char send_message[256],recv_message[256];
    pid_t childpid;
    int server_socket,ret,s;
    server_socket =socket(AF_INET,SOCK_STREAM,0);
    if(server_socket<0){
         printf("Error creating socket!\n");
         exit(1);
       }
    


    struct sockaddr_in server_address,client_address;
    server_address.sin_family=AF_INET;
    server_address.sin_port=htons(9003);
    server_address.sin_addr.s_addr=INADDR_ANY;
    ret=bind(server_socket, (struct sockaddr*) &server_address,sizeof(server_address));
    if(ret<0)
    {
     printf("Error binding!\n");
     exit(1);
    }
    printf("Waiting for new connection....\n");
    listen(server_socket,5);
    

    int flag_1=0;
    while(1){
     int client_socket;
     int len= sizeof(client_address);
     client_socket = accept(server_socket,(struct sockaddr *) &client_address,&len); //getting address from client
     if (client_socket < 0) {
        if(flag_1==0)
        printf("Error accepting connection!\n");
        exit(1);
         } 
      
     childpid=fork();
     if(childpid==0)
     {
          close(server_socket); 
          int flag=0;
          while(1){
               int rec_message=read(client_socket,&recv_message, sizeof(recv_message));
               printf("CLIENT SENT:%s\n",recv_message);  
               if(strcmp(recv_message,"exit")==0)
               {
                 flag_1=1;
                 close(client_socket);
                 printf("the client closed connection\n");
                 break;
               }
               printf("press \"exit\" to close the server\n");
               printf("SERVER:");
               gets(send_message);
               if(strcmp(send_message,"exit")==0)
               {
                flag=1;

                send(client_socket, send_message , sizeof(send_message),0);
                break;   
               }

               send(client_socket, send_message , sizeof(send_message),0);
               }
          
          if(flag==1)
           {
             close(server_socket);
             printf("Closing server\n");
             break;
           }
    
           

      

   
     
    }

   }
    
    kill(childpid, SIGINT);
    printf("all connection closed");
    return 0;

}
