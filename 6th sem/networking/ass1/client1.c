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
int flag_typed=0;
void* send_cli(void* network_socket)
{
   int flag=0;
   int sending=0;
   int *network=(int *)network_socket;
   char send_message[256];
   if(flag_typed==0)
   {
    printf("CLIENT:");
    flag_typed=1;
  }
   gets(send_message);
   if(strcmp(send_message,"exit")==0)
   {
     flag=10;
   }
   sending=send(*network,send_message,sizeof(send_message),0);
   //printf("%d\n",sending);
   
   if(sending>0)
   {
    flag_typed=0;
   }
   else
   {
    flag_typed=1;
   }
   //return flag;
  return (void *)flag; 

}
void* recv_cli(void* network_socket)
{
    int flag=0;
    int *network=(int *)network_socket;
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
   //prints the server's response
       if(strcmp(recv_response,"exit")==0)
      {
          flag=10;
          printf("Server closed connection exiting \n");
       }
       else
       {
         printf("\nSERVER SENT:%s\n",recv_response);
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
   while(1){
         void* status1;
         void* status2;

         
         int rc1=pthread_create(&thread1, NULL, &send_cli, &network_socket);
         //send_cli(&network_socket);
         int rc2=pthread_create(&thread2, NULL, &recv_cli, &network_socket);
         //pthread_join(thread1,0);
         //pthread_join(thread2,0);
         sleep(6);
         //printf("\nthread 1 closing\n");
         pthread_cancel(thread1);

         //sleep(1);
         //printf("\nthread 2 closing\n");
         pthread_cancel(thread2);
         pthread_join(thread1,&status1);
         pthread_join(thread2,&status2);
         
                   
          if((int)status2==10||(int)status1==10)
          {
             break;
          }
      }
   close(network_socket);

   return 0;



}

s