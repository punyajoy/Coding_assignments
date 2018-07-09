#include <stdio.h>
#include <stdlib.h> /* for exit(3) */
#include <pthread.h> /* for thread functions */
#include <math.h>
struct passedData {
	int x;
	int skip1;
};

int data[100];


void *add(void *param)
{
  struct passedData *data2; /* the structure that holds our data */
  data2 = (struct passedData *)param; /* the structure that holds our data */
  //((struct passedData *)param)->x=((struct passedData *)param)->x+((struct passedData *)param)->y;
  //param=(void *)data2;
  int i=data2->x;
  int skip=	data2->skip1;
  data[skip*i]=data[skip*i]+data[skip*i+(skip/2)];   
  //printf("the skip is %d\n",skip);
  //printf("the data is %d\n",i);
  
  

}
int sumOfElements(int size)
{   
   int i,skip=2;
   pthread_attr_t attr; /*Set of thread attributes required to be passed in pthread_create() */
   pthread_attr_init(&attr);      
   while(size/skip!=0)
   {
   pthread_t *tids=(pthread_t *)malloc((size/skip) * sizeof(pthread_t)); //this is the memory allocated for the array that is used as input from user
   for(i=0;i<(size/skip);i++)
   {  
   	  struct passedData *data1;
      data1 = (struct passedData *) malloc(sizeof(struct passedData));
  	  data1->x=i;
  	  data1->skip1=skip;
  	  //printf("skip is %d\n",data1->skip1);
  	  //printf("data is %d\n",data1->x);
  	  
  	  //data1->x = data[skip*i];
      //data1->y = data[skip*i+skip/2];
      int status = pthread_create(tids+i, &attr, add, data1);
      //data[skip*i]=data1->x;
       //free(data1); 
     }
     for(i = 0; i < (size/skip); i++) {
	       int istatus = pthread_join(*(tids+i), NULL);
      }
     
	
     printf("array elements\n");
     for(i=0;i<size;i++)
     {
      printf("%d\n",data[i]);
     }
     free(tids);
     skip=skip*2;
   }
   
}

int main()
{
  int num,i;
  //int data[100];
  //printf("give the number of elements:\n");
  //scanf("%d",&num);
  //printf("%d\n",num);
  
  //printf("give the elements:\n");
  num=8;
  for (i=0;i<num;i++)
  {
  //	    scanf("%d",&data[i]);
    data[i]=i+1;
  }
  int result=sumOfElements(num);
  printf("the result is:%d",data[0]);
}