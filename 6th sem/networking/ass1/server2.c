#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>  

char exit_message[100];
void *send_ser_loop(void* network_socket)
{
   int *network= (int *)network_socket;
   int flag=0;
   int sending=0;
   while(1)
   {
      char send_message[256];
      if(strcmp(exit_message,"exit")==0)
      {
        sending=send(*network,send_message,sizeof(send_message),0);
        break;
      }   
      gets(send_message);
      if(strcmp(send_message,"exit")==0)
      {
        sending=send(*network,send_message,sizeof(send_message),0);
        strcpy(exit_message,send_message);
        break;
      }

      sending=send(*network,send_message,sizeof(send_message),0);
      
   }


   return (void *)flag;
}

void *recv_ser_loop(void* network_socket)
{
   int *network= (int *)network_socket;
   int flag=0;
   while(1)
   {
 
     char recv_response[256];
     int recving=recv(*network,&recv_response,sizeof(recv_response),0);
     //prints the server's response
     if(strcmp(exit_message,"exit")==0)
      {
        break;
      }

     if(strcmp(recv_response,"exit")==0)
       {

          strcpy(exit_message,recv_response);
          //close(*network);
          printf("\nClient closed connection exiting \n press exit to close server\n");
          int sending=send(*network,exit_message,sizeof(exit_message),0);
          break;
       }
    else
       {
           printf("\nCLIENT SENT:%s\n",recv_response);    
       }
   }

   return (void *)flag;

}



int main(){
    pthread_t thread11, thread22;
    char send_message[256],recv_message[256],str[100];
    struct sockaddr_in cli;

    int server_socket;
    server_socket =socket(AF_INET,SOCK_STREAM,0);
         

    struct sockaddr_in server_address;
    server_address.sin_family=AF_INET;
    server_address.sin_port=htons(9003);
    server_address.sin_addr.s_addr=inet_addr("127.0.0.1");
    
    int binding=bind(server_socket, (struct sockaddr*) &server_address,sizeof(server_address));
    if(binding<0)
    {
       printf("binding error\n");
       exit(0);

    }

    printf("Waiting for new connection....\n");
    listen(server_socket,5);
    int client_socket;
    int len =sizeof(cli);
    client_socket = accept(server_socket,(struct sockaddr*)&cli,&len); //local machine hence null
    printf("ACCEPTED");
    printf("\nREQUEST FROM %s PORT %d \n",inet_ntop(AF_INET,&cli.sin_addr,str,sizeof(str)),htons(cli.sin_port));
    int flag=0;
    printf("press \"exit\" to close the server\n");
    void* status1;
    void* status2;
          //send_ser(&client_socket);  
    int rc1=pthread_create(&thread11, NULL, &send_ser_loop, &client_socket);
    int rc2=pthread_create(&thread22, NULL, &recv_ser_loop, &client_socket);
          
    pthread_join(thread11,&status1);
    pthread_join(thread22,&status2);
          

     //printf("\nthread 1 closing\n");
    printf("Closing server\n");
    close(server_socket);

    return 0;

}
