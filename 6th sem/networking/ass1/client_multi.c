// Client side C/C++ program to demonstrate Socket programming
#include <stdio.h>
#include <stdlib.h>

//included socket APIs
#include <sys/socket.h>
#include <sys/types.h>

//
#include <netinet/in.h>

#include <string.h>
  

int main(){
   
   // create a socket
   int network_socket;
   network_socket=socket(AF_INET,SOCK_STREAM,0);
   
   // specify an address for the socket
   struct sockaddr_in server_address; 
   server_address.sin_family=AF_INET;
   server_address.sin_port = htons(9003);
   server_address.sin_addr.s_addr=INADDR_ANY;
   
   int connection_status=connect(network_socket, (struct sockaddr *)&server_address, sizeof(server_address));
   
   // check for connection
   if(connection_status==-1)
   {
         printf("there was a error connecting\n");
         exit(0);

   }
   char recv_response[256],send_message[256];
   while(1){
   printf("Press \"exit\" to end connection\n");
   printf("CLIENT:");
   gets(send_message);
   if(strcmp(send_message,"exit")==0)
   {
     send(network_socket,send_message,sizeof(send_message),0);
     break;
   }
   send(network_socket,send_message,sizeof(send_message),0);
   recv(network_socket,&recv_response,sizeof(recv_response),0);
   //prints the server's response
   if(strcmp(recv_response,"exit")==0)
   {
     printf("Server closed connection exiting \n");
     break;
    }
   printf("SERVER SENT:%s\n",recv_response);
   }
   close(network_socket);

   return 0;



}

