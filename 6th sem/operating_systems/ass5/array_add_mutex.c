#include <stdio.h>
#include <stdlib.h> /* for exit(3) */
#include <pthread.h> /* for thread functions */
#include <math.h>  
#include <unistd.h>
struct passedData {
	int x;  //i value 
	int skip1;  //value to calculate next elements
  int y;      //the  vlaue that represents whether two elements are considered or three 
};

int data[10000];  //the global data array
pthread_mutex_t p_mutex[10000]; // array of the mutexes

void *add(void *param)
{
  struct passedData *data2; /* the structure that holds our data */
  data2 = (struct passedData *)param; /* the structure that holds our data */
  //((struct passedData *)param)->x=((struct passedData *)param)->x+((struct passedData *)param)->y;
  //param=(void *)data2;
  int i=data2->x;
  int skip=	data2->skip1;
  int y=data2->y;
  int status =  pthread_mutex_lock(&p_mutex[skip*i]);  //locking element 1st element 
  status =  pthread_mutex_lock(&p_mutex[skip*i+(skip/2)]);  //locking element 2nd element
  data[skip*i]=data[skip*i]+data[skip*i+(skip/2)];
  if(y==1)
  {//the third element  locking and unlocking 
  status =  pthread_mutex_lock(&p_mutex[skip*i+2*(skip/2)]);
  data[skip*i]=data[skip*i]+data[skip*i+2*(skip/2)];
  status =  pthread_mutex_unlock(&p_mutex[skip*i+2*(skip/2)]);
  }
  status =  pthread_mutex_unlock(&p_mutex[skip*i]);  //unlocking 1st element 
  status =  pthread_mutex_unlock(&p_mutex[skip*i+(skip/2)]);  //unlocking 2nd element 
  
  //printf("the skip is %d\n",skip);
  //printf("the data is %d\n",i);
  
  

}
int sumOfElements(int size)
{   
   int i,j,skip=2,sum,size_temp;
   pthread_attr_t attr; /*Set of thread attributes required to be passed in pthread_create() */


   pthread_attr_init(&attr);      //initialising the attribute for all the thread once as this is the correct according to manual
   size_temp=size;
   struct passedData data1[10000];  // taking max passed elements to be 10000 
   int status;
   for(i=0;i<10000;i++)
   {
     status = pthread_mutex_init(&p_mutex[i], NULL);
   }
   int count=0;   
   /* this loop calculates all the position where addition will take place and with which elements*/
   while(size_temp!=0)
   {
      size_temp=size_temp/2;
      for(i=0;i<size_temp;i++)
      {  
      data1[count].x=i;          
      data1[count].skip1=skip;
      data1[count].y=-1;
      count=count+1;
      }
      printf("size_temp %d\n",size_temp);
      if(size_temp!=0)
        {
        printf("hello");
        data1[count-1].y=1;
        }
      skip=skip*2;
   }
   for(i=0;i<count;i++)
   {  
       printf("\nthe data and skip %d and %d and %d",data1[i].x,data1[i].skip1,data1[i].y);   
   }
   
   pthread_t tids[count];
   
  //for each element in the passedData structure array a thread is initiialised on order to run the processes 
   for(i=0;i<count;i++)
   {  
      int status = pthread_create(&tids[i], &attr, add, &data1[i]);
      

   }
   // all the threads are joined together 
   for(i=0;i<count;i++)
   {  
    int status = pthread_join(tids[i], NULL);
   }
   //the array is printed at the end
    printf("\narray elements\n");
      for(j=0;j<size;j++)
      {
      printf("%d\n",data[j]);
      }
     
    return 1;
}

int main()
{
  int num,i;
  //int data[100];
  printf("give the number of elements:\n");
  scanf("%d",&num);
  //printf("%d\n",num);
  
  printf("give the elements:\n");
  //num=6;
  for (i=0;i<num;i++)
  {
  	    scanf("%d",&data[i]);
    //data[i]=i+1;
  }
  int result=sumOfElements(num);
  //since the array is global hence the 0th element can be accesed
  printf("\nthe result is:%d\n",data[0]);
}