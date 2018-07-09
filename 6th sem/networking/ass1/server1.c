// Server side C/C++ program to demonstrate Socket programming
#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>  

int flag_typed=0;

void* send_ser(void* network_socket)
{
   int flag=0;
   int sending=0;
   int *network= (int *)network_socket;
   char send_message[256];
   if(flag_typed==0)
   {
    printf("SERVER:");
    flag_typed=1;
   }
   
   gets(send_message);
   if(strcmp(send_message,"exit")==0)
   {
     flag=10;
   }
   sending=send(*network,send_message,sizeof(send_message),0);
   if(sending>0)
   {
    flag_typed=0;
   }
   else
   {
    flag_typed=1;
   }
   


   return (void *)flag;
   

}
void* recv_ser(void* network_socket)
{
     int flag=0;
     int *network= (int *)network_socket;
     char recv_response[256];
     int recving=recv(*network,&recv_response,sizeof(recv_response),0);
    if(recving>0)
     {
       flag_typed=0;
     }
     else
     {
       flag_typed=1;
      }
   //


   //prints the server's response
    if(strcmp(recv_response,"exit")==0)
       {
          flag=10;
          close(*network);
          printf("\nClient closed connection exiting\n");
       }
    else
       {
           printf("\nCLIENT SENT:%s\n",recv_response);    
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
    while(1){
    printf("Waiting for new connection....\n");
    listen(server_socket,5);
    int client_socket;
    int len =sizeof(cli);
    client_socket = accept(server_socket,(struct sockaddr*)&cli,&len); //local machine hence null
    printf("ACCEPTED");
    printf("\nREQUEST FROM %s PORT %d \n",inet_ntop(AF_INET,&cli.sin_addr,str,sizeof(str)),htons(cli.sin_port));
    int flag=0;
    printf("press \"exit\" to close the server\n");
    while(1)
        {
          void* status1;
          void* status2;
          //send_ser(&client_socket);  
          int rc1=pthread_create(&thread11, NULL, &send_ser, &client_socket);
          int rc2=pthread_create(&thread22, NULL, &recv_ser, &client_socket);
          
          

          sleep(1);
          //printf("\nthread 1 closing\n");
          pthread_cancel(thread11);
          //sleep(1);
          //printf("\nthread 2 closing\n");
          pthread_cancel(thread22);
          pthread_join(thread11,&status1);
          pthread_join(thread22,&status2);
    
          
          if((int)status1==10)
          {
             flag=1;
             break;
          }
          
          if((int)status2==10)
          {
             
             break;
          }

         }

      

         if(flag==1)
         {
          printf("Closing server\n");
          break;
          }
    }
    close(server_socket);

    return 0;

}
