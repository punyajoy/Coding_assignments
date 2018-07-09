#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>  

struct client_info{
     int sock_fd;
     char name[256];
     char online;
}client_data[100];
int count=0;
/*
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
          printf("\nClient closed connection exiting\n");
          break;
       }
    
   }

   return (void *)flag;

}
*/






void* connection_handler(void* client_no)
{
   
    struct client_info *client_n= (struct client_info *)client_no;
    char recv_response[256],name[256];
    char send_name[256] = "SERVER";
    int sending=send((*client_n).sock_fd,send_name,sizeof(send_name),0);
    char send_message[256] = "SIGN IN NAME";
    sending=send((*client_n).sock_fd,send_message,sizeof(send_message),0);
    int recving=recv((*client_n).sock_fd,&name,sizeof(name),0);
    strcpy((*client_n).name,name);
    (*client_n).online='Y';
    int flag_online=0;
    int flag=0;
    count++;
    printf("%d\n",count);
    int flag_typed=0;
    //printf("%d\n",count);
    while(1){

      char send_message1[256] = "People Online\n";
      int flag_on=0;
      for(int i=0;i<count;i++)
        {

          char name_temp[256];
          strcpy(name_temp,client_data[i].name);
          if(strcmp(name_temp,name)!=0 && client_data[i].online=='Y')
          {
           flag_on=1;
           strcat(send_message1,name_temp);
           strcat(send_message1,"\n");
          }
        }
      if(!flag_on)
      {
          char mess_temp[256]="No person online";
          strcpy(send_message1,mess_temp);
          if(flag_typed==0)
          {
          sending=send((*client_n).sock_fd,send_name,sizeof(send_name),0); 
          sending=send((*client_n).sock_fd,send_message1,sizeof(send_message1),0);
          }
          
          flag_typed=1; 
          continue;   
      }
      else
      {
      sending=send((*client_n).sock_fd,send_name,sizeof(send_name),0); 
      sending=send((*client_n).sock_fd,send_message1,sizeof(send_message1),0);
      flag_typed=0;
      }
      
      //strcpy(send_message1,"Whom to send message");
      
      //sending=send((*client_n).sock_fd,send_name,sizeof(send_name),0);
      //sending=send((*client_n).sock_fd,send_message1,sizeof(send_message1),0);
      
      char send_name1[256];
      recving=recv((*client_n).sock_fd,&send_name1,sizeof(send_name1),0);
      if(strcmp(send_name1,"exit")==0)
       {
          (*client_n).online='N';
          close((*client_n).sock_fd);
          //count--;
          printf("%s is offline\n",(*client_n).name);
          break;
       }


      int flag_1=1,i;   
      for(i=0;i<count;i++)
      {

          if(strcmp(client_data[i].name,send_name1)==0 && client_data[i].online == 'Y')
          {
              flag_1=0;
              break;
          }
       }
       if(flag_1 == 0)
       {
        //char send_message1[256] = "what to send :-";
        //sending=send((*client_n).sock_fd,send_name,sizeof(send_name),0);
        //sending=send((*client_n).sock_fd,send_message1,sizeof(send_message1),0);
        recving=recv((*client_n).sock_fd,&recv_response,sizeof(recv_response),0);
        sending=send(client_data[i].sock_fd,(*client_n).name,sizeof((*client_n).name),0);
        sending=send(client_data[i].sock_fd,recv_response,sizeof(recv_response),0);
        }
        else
        {
        char send_message1[256] = "No person of this name is online\n";
        sending=send((*client_n).sock_fd,send_name,sizeof(send_name),0);
        sending=send((*client_n).sock_fd,send_message1,sizeof(send_message1),0);   
         }
        
    
    
   }
  
    //printf("\n hello \n");

    //printf("%s\n",(*client_n).name);
    //int rc1=pthread_create(&thread11, NULL, &send_ser_loop, &client_socket);
    //int rc2=pthread_create(&thread22, NULL, &recv_ser_loop, &client_socket);
    //pthread_join(thread11,&status1);
    //pthread_join(thread22,&status2);

}



int main()
{
    
    int server_socket,ret;
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
    int client_socket;
    pthread_t thread_h;
    int len= sizeof(client_address);
    while((client_socket = accept(server_socket,(struct sockaddr *) &client_address,&len)))
    {   
  
    	if(client_socket>0)
     	{
         char str[100];
         printf("ACCEPTED");
         printf("\nREQUEST FROM %s PORT %d \n",inet_ntop(AF_INET,&client_address.sin_addr,str,sizeof(str)),htons(client_address.sin_port));
         client_data[count].sock_fd=client_socket;
         if( pthread_create( &thread_h , NULL ,  connection_handler , &client_data[count]) < 0)
         {
            printf("could not create thread");
            return 1;
         }


        }
        else
        {
        	printf("could not connect to client");


        }
    }





      




    printf("hello ended");
    close(server_socket);

	return 0;
}
