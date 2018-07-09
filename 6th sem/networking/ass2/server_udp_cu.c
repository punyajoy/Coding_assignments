// Server side C/C++ program to demonstrate Socket programming
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <ctype.h>



int verbose=0;

int main(int argc,char* argv[]){
    char buffer[1313],buffer_sent[1313];
    

    if(argc<2)
    {
        printf("please give valid input in command line");
        //exit(0);
    }
    else
    {
     int server_socket;
     server_socket =socket(AF_INET,SOCK_DGRAM,0);
     struct sockaddr_in server_address,client_address;
     struct sockaddr_storage serverStorage;

     socklen_t addr_size, client_addr_size;
     server_address.sin_family=AF_INET;
     int port;
     sscanf(argv[1], "%d", &port);
     server_address.sin_port=htons(port);
     server_address.sin_addr.s_addr= INADDR_ANY;    
     bind(server_socket, (struct sockaddr*) &server_address,sizeof(server_address));
     addr_size = sizeof serverStorage;
     while(1)
     {
          char seq_no[3];
          char time_stamp[9];
          char ttl[3];
          char msg[1300];
          int nBytes = recvfrom(server_socket,buffer,sizeof(buffer),0,(struct sockaddr *)&serverStorage, &addr_size);
          
          buffer[nBytes]='\0';
          int i;
          //strncpy(seq_no, buffer, 2);
          //strncpy(time_stamp, buffer + 2, 8);
          strncpy(ttl, buffer+10, 2);
          //strncpy(msg, buffer+12,(int)sizeof(buffer)-12);
          //msg[(int)sizeof(buffer)-11]='\0';
          if(verbose==1)
          {
          //printf("nbytes: %d\n",nBytes);
          //printf("Sequence number is: %s\n",seq_no);
          //printf("Time_stamp: %s\n",time_stamp);
          printf("TTL: %s\n",ttl);
          //printf("Message: %s\n",msg);
          //printf("total_buffer: %s\n",buffer);
          }
          sprintf(ttl,"%02d",(atoi(ttl)-1));
          /*char *buffer_total = malloc(sizeof(buffer));//+1 for the null-terminator
          int nBytes_total = sizeof(buffer);
          strcpy(buffer_total,seq_no);
          strcat(buffer_total,time_stamp);
          strcat(buffer_total,ttl);
          strcat(buffer_total,msg);
          */
          strncpy(buffer+10, ttl, 2);
          sendto(server_socket,buffer,sizeof(buffer),0,(struct sockaddr *)&serverStorage,addr_size);


     }
     close(server_socket);
    }    
    

    
    
    
    return 0;

}