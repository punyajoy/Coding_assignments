// Server side C/C++ program to demonstrate Socket programming
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
#include <sys/types.h>  //open(),ftruncate()
#include <sys/stat.h>    //open()
#include <fcntl.h>       //open()
#include <error.h>




char* datapacket(char*,short int);
char* ACK(short int);
char* RRQ(char *,short int,short int);
char* WRQ(char *,short int,short int);
char* ERR(char *,short int);
int verbose=1;

int main(int argc,char* argv[]){
    //char buffer[1313],buffer_sent[1313];
    

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
     server_address.sin_addr.s_addr= inet_addr("127.0.0.1");    
     bind(server_socket, (struct sockaddr*) &server_address,sizeof(server_address));
     addr_size = sizeof(serverStorage);
     while(1)
     {
          char buffer[1000],buffer_total[1000];
          int nBytes_total=sizeof(buffer_total);
          int nBytes = recvfrom(server_socket,buffer,50,0,(struct sockaddr *)&serverStorage, &addr_size);
          int opcode=0;
          memcpy(&opcode,buffer,2);
          printf("the opcode is %d\n",opcode);
          if(opcode==1)
          {



          }
          else if(opcode==2) 
          {
             char *filename;
             int i = 2;
             while(buffer[i]!='\0')
             {

                i++;
             }
             filename = malloc (sizeof (char) * (i-1));
             printf("the null pos%d\n",i);
             memcpy(filename,buffer+2,i-2);
             filename[i-1]='\0';
             if(verbose) printf("the file name is %s\n",filename);
             int fp;
             fp = open(filename,O_CREAT|O_RDWR,S_IRWXU);
             if(fp < 0)
             {
               printf("File could not be opened.\n");
               perror("open");
               return 1;
             }    
             //char err[30];
             //strcpy(err,"error");
             char* ACK0 = malloc (sizeof (char) * 4);
    
             ACK0=ACK(0);
             //printf("size of packet %d\n",(int)sizeof(err));
             int packet_send=sendto(server_socket,ACK0,sizeof(ACK0),0,(struct sockaddr *)&serverStorage,addr_size);
             int less_flag=0;
             do{
                char* recv_block;
                char* recv_msg;
                recv_block=malloc (sizeof (char) * 516);
                recv_msg=malloc (sizeof (char) * 512);
                int recv = recvfrom(server_socket,recv_block,516,0,(struct sockaddr *)&serverStorage, &addr_size);
                int opcode;
                int block_no;
                memcpy(&opcode,recv_block,2);
                memcpy(&block_no,recv_block+2,2);
                memcpy(recv_block,recv_block+4,512);
                lseek(fp,(block_no-1)*512,SEEK_SET);
                write(fp,recv_block,512);
                for(i=0;i<512;i++)
                {
                    printf("inside for\n");
                    if(recv_msg[i]!='\0')
                    {
                       less_flag=1;
                       break;
                    }
                }
                char* ACK0 = malloc (sizeof (char) * 4);
                ACK0=ACK(block_no);
                int packet_send=sendto(server_socket,ACK0,sizeof(ACK0),0,(struct sockaddr *)&serverStorage,addr_size);
             
             }while(less_flag!=1);

             printf("file received");
             close(fp);

          }
          //sendto(server_socket,buffer_total,nBytes_total,0,(struct sockaddr *)&serverStorage,addr_size);


     }
     close(server_socket);
    }    
    
return 0;

}



char* datapacket(char* data,short int block)
{
    
    char *data1;
    data1 = malloc (sizeof (char) * 516);
    bzero(data1, 516);
    short int opcode=3;
    memcpy(data1,&opcode,2);
    memcpy(data1+2,&block,2);
    int size=(int)sizeof(data);
    memcpy(data1+4,data,size);
    return data1;
}

char* ACK(short int block){
    char *data1;
    data1 = malloc (sizeof (char) * 4);
    bzero(data1, 4);
    short int opcode=4;
    memcpy(data1,&opcode,2);
    memcpy(data1+2,&block,2);
    return data1;
}
char* RRQ(char *data ,short int block, short int mode)
{
    char *data1;
    data1 = malloc (sizeof (char) * 50);
    bzero(data1, 50);
    short int opcode=1;
    memcpy(data1,&opcode,2);
    memcpy(data1+2,&block,2);
    int size=(int)sizeof(data);
    memcpy(data1+4,data,size);
    memcpy(data1+size+4+1,&mode,2);
    return data1;



}
char* WRQ(char *data ,short int block, short int mode)
{
    char *data1;
    data1 = malloc (sizeof (char) * 50);
    bzero(data1, 50);
    short int opcode=2;
    memcpy(data1,&opcode,2);
    memcpy(data1+2,&block,2);
    int size=(int)sizeof(data);
    memcpy(data1+4,data,size);
    memcpy(data1+size+4+1,&mode,2);
    return data1;



}
char* ERR(char *err_msg ,short int error_no)
{
    char *data1;
    data1 = malloc (sizeof (char) * 50);
    bzero(data1, 50);
    short int opcode=5;
    memcpy(data1,&opcode,2);
    memcpy(data1+2,&error_no,2);
    int size=(int)sizeof(err_msg);
    printf("size of err_msg %d\n",size);
    memcpy(data1+4,err_msg,size);
    return data1;



}
