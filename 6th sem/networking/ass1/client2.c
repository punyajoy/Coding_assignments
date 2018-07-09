// Client side C/C++ program to demonstrate Socket programming
#include <stdio.h>
#include <stdlib.h>

//included socket APIs
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>  

char exit_message[100];

void *send_cli_loop(void* network_socket)
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

void *recv_cli_loop(void* network_socket)
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
          printf("\nServer closed connection exiting \n press exit to close client window\n");
          int sending=send(*network,exit_message,sizeof(exit_message),0);    
          break;
       }
    else
       {
           printf("\nSERVER SENT:%s\n",recv_response);    
       }
   }

   return (void *)flag;

}



int main(){
  

   pthread_t thread1, thread2;
   char str[100];

   // create a socket
   int network_socket;
   network_socket=socket(AF_INET,SOCK_STREAM,0);
   
   // specify an address for the socket
   struct sockaddr_in server_address; 
   server_address.sin_family=AF_INET;
   server_address.sin_port = htons(9003);
   server_address.sin_addr.s_addr=inet_addr("127.0.0.1");
   
   int connection_status=connect(network_socket, (struct sockaddr *)&server_address, sizeof(server_address));
    
   // check for connection
   if(connection_status==-1)
   {
         printf("there was a error connecting\n");
         exit(0);

   }
   printf("\nCONNECTED");
   printf("\nSERVER AT %s PORT %d \n",inet_ntop(AF_INET,&server_address.sin_addr,str,sizeof(str)),server_address.sin_port);
   
   printf("Press \"exit\" to end connection\n");
   
   void* status1;
   void* status2;

         
   int rc1=pthread_create(&thread1, NULL, &send_cli_loop, &network_socket);
   //send_cli(&network_socket);
   int rc2=pthread_create(&thread2, NULL, &recv_cli_loop, &network_socket);
         //pthread_join(thread1,0);
         //pthread_join(thread2,0);
    pthread_join(thread1,&status1);
    pthread_join(thread2,&status2);
         
                   
   close(network_socket);

   return 0;
}

