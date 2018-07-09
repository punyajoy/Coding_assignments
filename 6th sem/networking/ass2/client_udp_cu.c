// Client side C/C++ program to demonstrate Socket programming
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <ctype.h>
#include <time.h>       /* time_t, time (for timestamp in second) */
#include <sys/timeb.h>  /*microseconds*/
#include <sys/time.h>
void gen_random(char *s, const int len) {
    static const char alphanum[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

    for (int i = 0; i < len; ++i) {
        s[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
    }

    s[len] = 0;
}

int verbose=0;



int main(int argc,char* argv[]){
   

   if(argc<6)
   {
         printf("please give valid input in command line");
         //exit(0);
   }  
   else
   {
      FILE *fptr;
      fptr = fopen(argv[5], "a");
      int client_socket, portNum, nBytes,nBytes_total;
      char buffer[256],buffer1[1024];
      struct sockaddr_in server_address; 
      socklen_t addr_size;
      client_socket=socket(AF_INET,SOCK_DGRAM,0);
      server_address.sin_family=AF_INET;
      server_address.sin_port = htons(atoi(argv[2]));
      server_address.sin_addr.s_addr=inet_addr(argv[1]);
      addr_size = sizeof(server_address);
      struct timeval timer_usec1; 
      long long int timestamp_usec1; 
    
      if (!gettimeofday(&timer_usec1, NULL)) {
             timestamp_usec1 = ((long long int) timer_usec1.tv_sec) * 1000000ll +(long long int) timer_usec1.tv_usec;
           }
        else{
          timestamp_usec1 = -1;
            }

      int i;
      long long int sum=0;
      for(i=0;i<50;i++)
      {


        struct timeval timer_usec; 
        long long int timestamp_usec; /* timestamp in microsecond */
        long long int timestamp_usec_recv;
        char time_data[9];
        char time_data1[9];
      
        char sec_char[2];
        char ttl_char[2];
        int ttl;      
        sscanf(argv[4], "%d", &ttl);
        sprintf(ttl_char,"%02d", ttl);     
        if (!gettimeofday(&timer_usec, NULL)) 
             {
             timestamp_usec = ((long long int) timer_usec.tv_sec) * 1000000ll +(long long int) timer_usec.tv_usec;
              }
        else {
             timestamp_usec = -1;
               }
        sprintf(time_data,"%08lld", timestamp_usec-timestamp_usec1);
        sprintf(sec_char,"%02d", i);
        if(verbose==1)
        {
           printf("sequence num %02d\n", i);
           printf("microsecond: %s\n",time_data);
        }
        char *buffer= malloc(atoi(argv[3])); 
        gen_random(buffer, atoi(argv[3]));
        if(verbose==1)
          printf("You typed: %s\n",buffer);
        char *buffer_total = malloc(2+sizeof(time_data)+2+atoi(argv[3]));//+1 for the null-terminator
        int nBytes_total = 2+sizeof(time_data)+2+atoi(argv[3]);
        strcpy(buffer_total,sec_char);
        strcat(buffer_total,time_data);
        strcat(buffer_total,ttl_char);
        strcat(buffer_total,buffer);
        if(verbose==1)
        {
           printf("You send: %s\n",buffer_total);
           printf("You send: %d bytes\n ",nBytes_total);                 
        }
        
        while(1)
        {
            sendto(client_socket,buffer_total,nBytes_total,0,(struct sockaddr *)&server_address,addr_size);
            nBytes = recvfrom(client_socket,buffer1,sizeof(buffer1),0,NULL, NULL);
            char ttl_recv[3];
            strncpy(ttl_recv, buffer1+10, 2);
            sprintf(ttl_recv,"%02d",(atoi(ttl_recv)-1));
            if(atoi(ttl_recv)==0)
            {
                break;
            }
            strncpy(buffer1+10, ttl_recv, 2);
            strcpy(buffer_total,buffer1);

        }

        if (!gettimeofday(&timer_usec, NULL)) 
             {
             timestamp_usec_recv = ((long long int) timer_usec.tv_sec) * 1000000ll +(long long int) timer_usec.tv_usec;
              }
        else 
            {
             timestamp_usec_recv = -1;
            }
        long long int crtt=timestamp_usec_recv-timestamp_usec;
            
        if(verbose==1)
        {
         printf("trip_ended\n");
         printf("Cumulative RTT: %lld\n",crtt);
        }
        sum+= crtt;
      }
      
      fprintf(fptr,"%d %lld\n", atoi(argv[3]),sum/50);
      fclose(fptr);
      close(client_socket);

    }
  return 0;   


}

