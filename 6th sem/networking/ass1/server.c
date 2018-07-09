// Server side C/C++ program to demonstrate Socket programming
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#define PORT 8080
int main(){
    char server_message[256];
    
    int server_socket;
    server_socket =socket(AF_INET,SOCK_STREAM,0);


    struct sockaddr_in server_address;
    server_address.sin_family=AF_INET;
    server_address.sin_port=htons(9003);
    server_address.sin_addr.s_addr=INADDR_ANY;
    
    bind(server_socket, (struct sockaddr*) &server_address,sizeof(server_address));
    listen(server_socket,5);
    int client_socket;
    client_socket = accept(server_socket,NULL,NULL); //local machine hence null
    
    int rec_message=read(client_socket,&server_message, sizeof(server_message));
    send(client_socket, server_message , sizeof(server_message),0);
    
    printf("client sent data %s\n",server_message);

    close(server_socket);
    return 0;

}
