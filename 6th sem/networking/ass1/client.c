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
   char server_response[256],send_message[256];

   gets(send_message);
   send(network_socket,send_message,sizeof(send_message),0);
   recv(network_socket,&server_response,sizeof(server_response),0);
   
   //prints the server's response
   printf("the server sent the data: %s\n",server_response);
   close(network_socket);

   return 0;



}

