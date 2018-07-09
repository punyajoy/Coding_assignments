
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
#include <stdio.h>
#include <sys/types.h>  //open(),ftruncate()
#include <sys/stat.h>    //open()
#include <fcntl.h>       //open()
#include <error.h>
#include <string.h>
#define MAX_ITER 16
static const char* MODE="octet";
char* datapacket(char*,short int);
char* ACK(short int);
char* RRQ(char *,short int);
char* WRQ(char *,short int);
char* ERR(char *,short int);
int check_ack(int,int,struct sockaddr_in,socklen_t);
struct sockaddr_in reply_addr ;
int addrlen= sizeof(reply_addr);
int ver = 0;



int main(int argc,char* argv[]){
   
    if(argc<5)
    {
      if(ver) printf("give the correct arguments\n");
      exit(1);
    }
   

      int client_socket, portNum, nBytes,nBytes_total;
      char buffer[256],buffer1[1024],filename[50],func[3];
      struct sockaddr_in server_address; 
      socklen_t addr_size;
      client_socket=socket(AF_INET,SOCK_DGRAM,IPPROTO_UDP);
      server_address.sin_family=AF_INET;
      server_address.sin_port = htons(69);
      server_address.sin_addr.s_addr=inet_addr("127.0.0.1");
      addr_size = sizeof(server_address);
      
      if(strcmp(argv[3],"get")==0)
      {
        strcpy(filename,argv[4]);
        int fp;
        fp = open(filename,O_CREAT|O_RDWR,S_IRWXU);
        if(fp<0)
        {
          if(verbose) printf("No file of this name present\n");
            exit(1);
        }
        char *read_req=RRQ(filename,2);
        //int nBytes_total=sizeof(write_req);
        int l=sendto(client_socket,read_req,516,0,(struct sockaddr *)&server_address,addr_size);
        if(l==-1)
        {
          printf("there is error in sending \n");
        }
        do{
              unsigned char datapacket[516],datablock[512]; 
              int result = recvfrom(client_socket,datapacket,516,0,(struct sockaddr *)&reply_addr,&addrlen);
              if (result == -1)
              {
                    printf("error_receiving\n");
                    return -1;
              }
              else
              {

                    if(datapacket[1] == 3)
                    {

                      short int block_recv=(datapacket[2]<<8)+datapacket[3];
                      printf("block_no %2d is received and ACK sent\n",block_recv);
                      //block_recv++;
                      char *ACK_buffer;
                      ACK_buffer=ACK(block_recv);
                      memcpy(datablock,datapacket+4,512);            
                      write(fp,&datablock,result);
                      int result2=sendto(client_socket,ACK_buffer,4,0,(struct sockaddr *)&reply_addr,addrlen);
                      if(result2==-1)
                      {
                        printf("ack not sent\n");
                      }
                      if(result<516)
                      {
                      printf("the file is received\n");
                      close(fp);
                      break;
                      }
                    }
                    else if(datapacket[1]=5)
                    {
                       short int error_code;
                       unsigned char error_msg[512];
                       //memcpy(&error_code,datapacket+2,2);
                       error_code=(datapacket[2]<<8)+datapacket[3];
                       memcpy(error_msg,datapacket+4,512); 
                       printf("the err_code:%d the message:%s\n",error_code,error_msg);
                       break;
                    }
                    
              }

        }while(1);  
                         

      }
      else if(strcmp(argv[3],"put")==0)
      {
        strcpy(filename,argv[4]);
        int fp;
        fp = open(filename,O_RDONLY,S_IRWXU);
        if(fp<0)
        {
          if(verbose) printf("No file of this name present\n");
            exit(1);
        }
        char *write_req=WRQ(filename,2);
        //int nBytes_total=sizeof(write_req);
        int l=sendto(client_socket,write_req,516,0,(struct sockaddr *)&server_address,addr_size);
        if(l==-1)
        {
          printf("there is error in sending \n");
        }
        char ACK_buffer[4];
        int recv=check_ack(0,client_socket,server_address,addr_size);  
        if(recv==1)
        {
          int k=1;
          int s_size=0;
          int iter=0;
          do
          {
            if(ver) printf("the block_no %d\n",k);
            unsigned char block[512];
            unsigned char* packet;
            packet = malloc (sizeof (unsigned char) * 516);
            bzero(block,512);
            bzero(packet,516);
            lseek(fp,(k-1)*512,SEEK_SET);
            s_size=read(fp, &block, 512);
            if(ver) printf("the size is %d\n",s_size);
            //packet=datapacket(block,k);
            unsigned char *data1;
            data1 = malloc (sizeof (unsigned char) * 516);
            bzero(data1, 516);
            //short int opcode=3;
            //memcpy(data1,&opcode,2);
            data1[0]=0;
            data1[1]=3;
            //memcpy(data1+2,&block,2);
            data1[2]=k>>8;
            data1[3]=k%(0xff+1);
            if(ver) printf("block %d\n",k);
            if(ver) printf("data1 3rd position %d\n",data1[3]);
            int size=strlen(block);
            if(ver) printf("size of block %d\n",size);
            memcpy(data1+4,block,s_size);            
            l=sendto(client_socket,data1,s_size+4,0,(struct sockaddr *)&reply_addr,addrlen);
            if(l==-1)
            {
              printf("there is error in sending \n");
            }

            recv = check_ack(k,client_socket,server_address,addr_size);
            if(recv==1)
            {
              printf("datablock sent %2d and ACK received\n",k); 
              k++;
              iter=0;
            }
            else
            {
              iter++;

            }
            if(iter>MAX_ITER)
            {
              printf("the file could not be send properly send again\n");
              break;
            }
            if(s_size<512)
            {

              break;
            }
          }while(1);
          if(iter<MAX_ITER)
          {
           printf("file transmitted\n");
          }       
        }  
        else
        {



        }  

 
      }

      
   


  close(client_socket);
      
   
  return 0;   

}

int check_ack(int block_no,int client_socket,struct sockaddr_in server_address,socklen_t addr_size)
{
    struct timeval tv = {0,0};
    tv.tv_sec = 10;
    fd_set readset = {};
    FD_ZERO(&readset);
    FD_SET(client_socket, &readset);
    unsigned char ACK_buffer[516];
    bzero(ACK_buffer,516);
    select(client_socket+1, &readset, NULL, NULL, &tv);
    
    if (FD_ISSET(client_socket, &readset))
    {
        int result = recvfrom(client_socket,ACK_buffer,516,0,(struct sockaddr *)&reply_addr, &addrlen);
        if (result == -1)
        {
            printf("error_receiving\n");
            return -1;
        }
        else
        {
            //printf("message_received\n");
            int opcode=0;
            //memcpy(&opcode,ACK_buffer,2);
            //printf("ACK_buffer 1st position %d\n",ACK_buffer[1]);
            if(ACK_buffer[1] == 4)
            {
              int block_recv=(ACK_buffer[2]<<8)+ACK_buffer[3];
              //memcpy(&block_recv,ACK_buffer+2,2);
              //printf("block_recv %d\n",block_recv);
            
              if(block_recv==block_no)
              {
                 if(ver)printf("sending_next_block %d\n",block_no);
                 return 1;

              } 
              else
              {
                 if(ver) printf("sending the same block again %d\n",block_recv);
                 return -1;

              }

            }
            else if(ACK_buffer[1] == 5)
            {
                int error_type=0;
                unsigned char *error_msg;

                memcpy(&error_type,ACK_buffer+2,2);
                int i = 4;
                while(ACK_buffer[i]!='\0')
                {
                    i++;
                }

                error_msg = malloc (sizeof (char) * (i-3));
                memcpy(&error_msg,ACK_buffer+4,i-4);
                
                
                //error_msg[i-4]='\0';
                printf("in error %d\n",i);
                printf("the error_type is:%d\n",error_type);
                //printf("the error is:%s\n",error_msg);
                
                return -1;
           }


        }
    }
    else
    {
       printf("timeout\n");

    }
      

}



char* datapacket(char* data,short int block)
{
    
    char *data1;
    data1 = malloc (sizeof (char) * 516);
    bzero(data1, 516);
    //short int opcode=3;
    //memcpy(data1,&opcode,2);
    data1[0]=0;
    data1[1]=3;
    //memcpy(data1+2,&block,2);
    data1[2]=block>>8;
    data1[3]=block%256;
    //printf("block %d\n",block);
    //printf("data1 3rd position %d\n",data1[3]);
    int size=strlen(data);
    //printf("size of block %d\n",size);
    
    memcpy(data1+4,data,512);
    return data1;
}

char* ACK(short int block){
    char *data1;
    data1 = malloc (sizeof (char) * 4);
    bzero(data1, 4);
    data1[0]= 0;
    data1[1]= 4;
    data1[2]=block>>8;
    data1[3]=block%256;
    //printf("block is %d\n",block);
    return data1;
}
char* RRQ(char *data, short int mode)
{
    char *data1;
    data1 = malloc (sizeof (char) * 516);
    bzero(data1, 516);
    //short int opcode=1;
    //memcpy(data1,&opcode,2);
    data1[0]= 0;
    data1[1]= 1;
    //printf("data1 1st pos %d\n",data1[1]);
    int size=strlen(data);
    memcpy(data1+2,data,size);
    memcpy(data1+size+2+1,MODE,strlen(MODE));
    return data1;



}
char* WRQ(char *data , short int mode)
{
    char *data1;
    data1 = malloc (sizeof (char) * 516);
    bzero(data1, 516);
    //short int opcode=2;
    
    //memcpy(data1,&opcode,2);
    data1[0]= 0;
    data1[1]= 2;
    //printf("data1 1st pos %d\n",data1[1]);
    
    int size1=strlen(data);
    //printf("int size %d\n",size1);
    memcpy(data1+2,data,size1);
    memcpy(data1+size1+2+1,MODE,strlen(MODE));
    return data1;



}
char* ERR(char *err_msg ,short int error_no)
{
    char *data1;
    data1 = malloc (sizeof (char) * 516);
    bzero(data1, 516);
    data1[0]= 0;
    data1[1]= 5;
    memcpy(data1+2,&error_no,2);
    int size=(int)sizeof(err_msg);
    memcpy(data1+4,err_msg,size);
    return data1;
}


