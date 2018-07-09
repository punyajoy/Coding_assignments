#include<stdio.h>
#include<stdlib.h>
void main()
{
  
  int *ptr[50];
  int i,n;
  printf("dynamic memory allocation:");
  printf("how many elements:");
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {printf("enter a number:");
  ptr[i] =(int *)malloc(sizeof(int));
  scanf("%d",ptr[i]);
 }
   for(i=0;i<n;i++)
{ printf("%d\n",ptr[i]);
  free(ptr[i]);  
}
	
}
