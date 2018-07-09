#include <stdio.h>
#include <stdlib.h>      
#include <sys/types.h>  //open(),ftruncate()
#include <sys/stat.h>    //open()
#include <fcntl.h>       //open()
#include <string.h>      //strcmp()
#include <unistd.h>     //ftruncate()
#include <error.h>
#define MAX_INODE 20
#define MAX_DATABLOCK 20
#define MAX_DATABL_INODE 10
#define SetBit(A,k)     ( A[(k/32)] |= (1 << (k%32)) ) 
#define ClearBit(A,k)   ( A[(k/32)] &= ~(1 << (k%32)) )   
#define LSH_TOK_BUFSIZE 64
#define LSH_TOK_DELIM " \t\r\n\a"
#define FILE_IN_MEM 10

/*int rename(const char *oldpath, const char *newpath);*/
/*FILE *fopen(const char *path, const char *mode);*/
/*int open(const char *path, int oflag, ... );*/
/*int close(int fd);*/
/*ssize_t write(int fd, const void *buf, size_t count);*/
/*ssize_t read(int fd, void *buf, size_t count);*/
int checkBit(int A[],int k)
{

   if(A[(k/32)] == (1 << (k%32))) 
    {
      printf("if not working \n");
      
      return 1;
    }
   else 
    return 0;
}


struct super_block{
	int fsize;
	int root_node_pos;
	int block_size;
	int inode_size;
	int inode_start_locn;
	long long int inode_count;
	long long int free_inode_count;
	long long int datablock_count;
	long long int free_datablock_count;
	int inode_bitmap[MAX_INODE];
	int datablock_bitmap[MAX_DATABLOCK];
 }SB;
struct directory_entry{
    char file_name[50];
    long long int start_inode;
};


struct inodes{
    int type;
    int size;
    int datablock_count;
    int data_block[MAX_DATABL_INODE]; 
}INODE;
struct file_system{
  char *fsname;
  char dname;
  struct super_block sb;
  int fd;
}FS[FILE_IN_MEM];
int isFS[FILE_IN_MEM]={0};
int count=0;

char *read_line(void)
{
  char *line = NULL;
  ssize_t bufsize = 0; // have getline allocate a buffer for us
  return line;
}
char **delim_split(char *line,char *delim_string)
{
  int bufsize = LSH_TOK_BUFSIZE, position = 0;
  char **tokens = malloc(bufsize * sizeof(char*));
  char *token;

  if (!tokens) {
    fprintf(stderr, "lsh: allocation error\n");
    exit(EXIT_FAILURE);
  }

  token = strtok(line, delim_string);
  while (token != NULL) {
    tokens[position] = token;
    position++;

    if (position >= bufsize) {
      bufsize += LSH_TOK_BUFSIZE;
      tokens = realloc(tokens, bufsize * sizeof(char*));
      if (!tokens) {
        fprintf(stderr, "lsh: allocation error\n");
        exit(EXIT_FAILURE);
      }
    }

    token = strtok(NULL, delim_string);
  }
  tokens[position] = NULL;
  return tokens;
}

char **lsh_split_line(char *line)
{
  int bufsize = LSH_TOK_BUFSIZE, position = 0;
  char **tokens = malloc(bufsize * sizeof(char*));
  char *token;

  if (!tokens) {
    fprintf(stderr, "lsh: allocation error\n");
    exit(EXIT_FAILURE);
  }

  token = strtok(line, LSH_TOK_DELIM);
  while (token != NULL) {
    tokens[position] = token;
    position++;

    if (position >= bufsize) {
      bufsize += LSH_TOK_BUFSIZE;
      tokens = realloc(tokens, bufsize * sizeof(char*));
      if (!tokens) {
        fprintf(stderr, "lsh: allocation error\n");
        exit(EXIT_FAILURE);
      }
    }

    token = strtok(NULL, LSH_TOK_DELIM);
  }
  tokens[position] = NULL;
  return tokens;
}
int find_fs(char c)
{
  int i,flag=0;
   for(i=0;i<FILE_IN_MEM;i++)
   {
        if(FS[i].dname==c)
          flag=1;
          break;
   }
   if(flag==1)
   {
    return i;
   }
   else
    return -1;
}



int  mkfs(char *ch,int block_size,int size)
{
   int fp;
   fp = open(ch,O_CREAT|O_RDWR,S_IRWXU);
   if(fp < 0)
    {
        printf("File could not be opened.\n");
        perror("open");
        return 1;
    }
   printf("inside mkfs\n");
   int s_now=ftruncate(fp, size*1048576);
   struct super_block sb;
   sb.fsize=size;
   sb.root_node_pos=0;
   sb.block_size=block_size;
   sb.inode_size=sizeof(INODE);
   sb.inode_start_locn=sizeof(SB);
   sb.inode_count=size*1048576/10;
   sb.free_inode_count=sb.inode_count;
   sb.datablock_count=(size-(sizeof(SB)+sb.inode_count*sizeof(INODE)))/block_size;
   sb.free_datablock_count=sb.datablock_count;
   memset(sb.inode_bitmap,0,MAX_INODE);
   memset(sb.datablock_bitmap,0,MAX_DATABLOCK);
   int size1=sizeof(sb);
   printf("size %d\n",size1);
   SetBit(sb.inode_bitmap,0);
   lseek(fp,0,SEEK_SET);
   write (fp,&sb,sizeof(SB));
   struct inodes root_inode;
   root_inode.type=1;
   root_inode.size=10*sb.block_size;
   root_inode.datablock_count=10;
   //printf("root_inode type %d\n",root_inode.type);
   memset(root_inode.data_block,-1,MAX_DATABL_INODE);
   lseek(fp,sizeof(SB)+1,SEEK_SET);
   write (fp,&root_inode,sizeof(root_inode));
   close(fp);
   return 1;
}
int use(char *ch,char *ch_modified)
{
   int fp,i;
   fp = open(ch,O_CREAT|O_RDWR,S_IRWXU);
   if(fp < 0)
    {
        printf("File could not be opened.\n");
        perror("open");
        return 1;
    }
  for(i=0;i<FILE_IN_MEM;i++)
  {
     if(isFS[i]==0)
        break;
  }
  isFS[i]=1;
  FS[i].fsname=ch;
  FS[i].fd=fp;
  FS[i].dname=ch_modified[0]; 
  struct super_block sb;
  read (fp, &sb, sizeof(SB));
  FS[i].sb=sb;   
  //close(fp);


}

int cpy(char *source,char *dest)
{
    if(source[1]==':' && source[2]=='/'&&dest[1]==':' && dest[2]=='/')
    {
      printf("the_source and the_destination in the file_system\n");
      char **tokens1;
      tokens1=delim_split(source,"/");
      char **tokens;
      tokens=delim_split(dest,"/");


      int i,flag1=0,flag2=0;
      for(i=0;i<FILE_IN_MEM;i++)
      {
        if(FS[i].dname==tokens1[0][0])
        {
          flag1=1;
          break;
        }
      }
      int file_system1=i;

      for(i=0;i<FILE_IN_MEM;i++)
      {
        if(FS[i].dname==tokens1[0][0])
          {
          flag2=1;  
          break;
          }
      }
      int file_system2=i;

      if(flag1==1&&flag2==1)
      {

         int fp1=FS[file_system1].fd;
         int fp2=FS[file_system2].fd;
         //take the file pointer 1 and find the file inode  
         
         //take a new inode and details
         

         //take the file inode and copy the datablocks one by one
         

         //end when reach end of the data block
         

      }    

    }
    else if(dest[1]==':' && dest[2]=='/')
    {

      printf("the_destination in the file_system\n");
      char **tokens;
      tokens=delim_split(dest,"/");
      // open the file of the source that is in the same directory as the file system
      int fp;
      fp = open(source,O_RDWR,S_IRWXU);
      if(fp < 0)
      {
        printf("File could not be opened.\n");
        perror("open");
        return 1;
      }
      printf("line 257\n");
      //check for filesystem mounted if filesystem found then only proceed 
      int fsi=find_fs(tokens[0][0]);
      
      //check sequentially which indoe is empty fom the begining
      if(fsi!=-1)
      {
        int i,flag=0;
      for(i=0;i<FS[fsi].sb.inode_count*32;i++)
      {
         if(!checkBit(FS[fsi].sb.inode_bitmap,i))
           {
            flag=1;
            break;
            }
      }
      if(flag!=0)
      {
       int i_node_loc=i;
       SetBit(FS[fsi].sb.inode_bitmap,i);
       FS[fsi].sb.free_inode_count-=1;
       struct inodes file_inode,root_node;
       file_inode.type=2;
       file_inode.size=50*FS[fsi].sb.block_size;
       file_inode.datablock_count=50;
       //printf("root_inode type %d\n",root_inode.type);
       memset(file_inode.data_block,-1,MAX_DATABL_INODE);
       int fp2 = FS[fsi].fd;
       lseek(fp2,sizeof(SB)+1,SEEK_SET);
       read(fp2, &root_node, sizeof(INODE));
       printf("line 298\n");
       
       // filing the directory entry
       int data_flag=0;
        for(i=0;i<FS[fsi].sb.datablock_count*32;i++)
         {
            if(!checkBit(FS[fsi].sb.datablock_bitmap,i))
            {
            data_flag=1;
            break;
            }
         }
         int data_i_pos=i;
         if(data_flag!=0)
         {
            
             struct directory_entry ds;
             strcpy(ds.file_name,tokens[1]);
             printf("the file name is %s\n",ds.file_name);
             lseek(fp2,sizeof(SB)+FS[fsi].sb.inode_count*sizeof(INODE)+data_i_pos*sizeof(FS[fsi].sb.block_size)+1,SEEK_SET); 
             write(fp2,&ds,sizeof(ds));
             
             for(i=0;i<MAX_DATABL_INODE;i++)
             {
              if(root_node.data_block[i]!=-1)
              {
              root_node.data_block[i]=data_i_pos;
              break;
              }
             }
                
         }   

       //loading the data blocks
       printf("line 331\n");
      
       while(1)
       {
         int data_flag=0;
         for(i=0;i<FS[fsi].sb.datablock_count*32;i++)
         {
            
            printf("line 345\n");
             
            if(!checkBit(FS[fsi].sb.datablock_bitmap,i))
            {
             printf("line 340\n");
             data_flag=1;
             break;
            }
         }
         //printf("line 344\n");
      
         int data_i_pos=i;
         if(data_flag!=0)
         {
             printf("line 349\n");
       
             char buffer[FS[fsi].sb.block_size];
             //lseek(fp2,sizeof(SB)+1,SEEK_SET);
             int s_size=read (fp, &buffer, sizeof(buffer));
             printf("the size returned %d\n",s_size);
             if(s_size==0)
                break;
             lseek(fp2,sizeof(SB)+FS[fsi].sb.inode_count*sizeof(INODE)+data_i_pos*sizeof(FS[fsi].sb.block_size)+1,SEEK_SET); 
             write(fp2,buffer,FS[fsi].sb.block_size);
             
             if(i<MAX_DATABLOCK)
              file_inode.data_block[i]=data_i_pos;
         }
         

   
      } 
    printf("line 361\n");
      
    lseek(fp2,0,SEEK_SET);
    write (fp2,&FS[fsi].sb,sizeof(SB));
    lseek(fp2,sizeof(SB)+1,SEEK_SET);
    write (fp2,&root_node,sizeof(root_node));
    close(fp);
    



    }

   }
 }
   
}

int ls(char *path)
{
   char **tokens;
   tokens=delim_split(path,"/");
   
   int inode_locn=0;
   int i=0;
   printf("the drive name %c",tokens[0][0])
   int fsi=find_fs(tokens[0][0]);
   if(fsi!=-1)
   {
       while(1)
       {
         if(tokens[i+1]==NULL)
         {

            printf("inside %d\n",i);
            struct inodes ls_node;
            lseek(FS[fsi].fd,sizeof(SB)+1+(inode_locn)*FS[fsi].sb.inode_size,SEEK_SET);
            read(FS[fsi].fd, &ls_node, sizeof(INODE));
            int j;
            for(j=0;j<MAX_DATABL_INODE;j++)
            {
               if(ls_node.data_block[j]!=-1)
               {
                  printf("ds\n");
                  struct directory_entry ds;
                  lseek(FS[fsi].fd,sizeof(SB)+1+(FS[fsi].sb.inode_count)*FS[fsi].sb.inode_size+(ls_node.data_block[j])*FS[fsi].sb.block_size,SEEK_SET);
                  read(FS[fsi].fd, &ds, sizeof(ds));
                  printf("%s \n",ds.file_name);

               }

            }
            break;     
  
         }
         else
         {
           i++;
         }

       
       }


   }
   else
   {
      printf("file_system %c:/ does not exist\n",tokens[0][0]);
   }    


}


void rm(char *path)
{
    char **tokens;
   tokens=delim_split(path,"/");
   
   int inode_locn=0;
   int i=0;

   int fsi=find_fs(tokens[0][0]);
   if(fsi!=-1)
   {
       while(1)
       {
         if(tokens[i+2]==NULL)
         {

            printf("inside %d\n",i);
            struct inodes ls_node;
            lseek(FS[fsi].fd,sizeof(SB)+1+(inode_locn)*FS[fsi].sb.inode_size,SEEK_SET);
            read(FS[fsi].fd, &ls_node, sizeof(INODE));
            int j;
            for(j=0;j<MAX_DATABL_INODE;j++)
            {
               if(ls_node.data_block[j]!=-1)
               {
                  printf("ds\n");
                  struct directory_entry ds;
                  lseek(FS[fsi].fd,sizeof(SB)+1+(FS[fsi].sb.inode_count)*FS[fsi].sb.inode_size+(ls_node.data_block[j])*FS[fsi].sb.block_size,SEEK_SET);
                  read(FS[fsi].fd, &ds, sizeof(ds));
                  //printf("%s \n",ds.file_name);
                  if(strcmp(ds.file_name,tokens[i+1])==0)
                  {
                     
                     struct inodes fin_inode;
                     lseek(FS[fsi].fd,sizeof(SB)+1+(ds.start_inode)*FS[fsi].sb.inode_size,SEEK_SET);
                     read(FS[fsi].fd, &fin_inode, sizeof(INODE));
                     
                  }

               }

            }
            break;     
  
         }
         else
         {
           i++;
         }

       
       }


   }
   else
   {
      printf("file_system %c:/ does not exist\n",tokens[0][0]);
   }



}








int print_fs(char *ch)
{
   int fp;
   fp = open(ch,O_CREAT|O_RDWR,S_IRWXU);
   if(fp < 0)
    {
        printf("File could not be opened.\n");
        perror("open");
        return 1;
    }
   struct inodes test_block;
   struct super_block test_block1;
   read (fp, &test_block1, sizeof(SB));
   printf("fsize:%lld\n",test_block1.datablock_count);
   
   lseek(fp,sizeof(SB)+1,SEEK_SET);
   read (fp, &test_block, sizeof(INODE));
   printf("fsize:%d",test_block.data_block[0]);
   
   //buffer[sizeof(SB)+sizeof(INODE)]='\0';
   

   close(fp);
   return 1;

}
int print_fs_structure()
{
  int i;
  for(i=0;i<FILE_IN_MEM;i++)
  {
   if(isFS[i]!=0)
   { 
   printf("the file name %s\n",FS[i].fsname);
   printf("the drive name %c:/\n",FS[i].dname);
   printf("the superblock_size %d\n",FS[i].sb.block_size);
   printf("the int descriptor %d\n",FS[i].fd);
   }   

  }
   

   
  return 1;

}






int main(){
         


     while(1)
     {
     	  char command[100];
        printf("\nmyfs>");
        char * pch;
         
        //scanf("%s",command);
        char *line = NULL;
        ssize_t bufsize = 0; // have getline allocate a buffer for us
        getline(&line, &bufsize, stdin);
        
        printf("the line is %s \n",line);
        char **tokens;
        tokens=lsh_split_line(line);
        if(strcmp(tokens[0],"mkfs")==0)
        {
           mkfs(tokens[1],atoi(tokens[2]),atoi(tokens[3]));
           print_fs(tokens[1]);
        }
        else if(strcmp(tokens[0],"ls")==0)
        {
           ls(tokens[1]);
   		  }
        else if(strcmp(tokens[0],"use")==0)
        {
           use(tokens[1],tokens[2]);
           print_fs_structure();
           
   		  }
        else if(strcmp(tokens[0],"cp")==0)
        {
           cpy(tokens[1],tokens[2]);
           
        } 
        else if(strcmp(tokens[0],"rm")==0)
        {
          rm(tokens[1]);
           
        }
        else if(strcmp(tokens[0],"exit")==0)
        {
          printf("exiting the program\n");
          exit(0);
        }
        else
        {
          printf("invalid command\n");        
        }

     }








return 0;
}