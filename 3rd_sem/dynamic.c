#include<stdio.h>
#include<stdlib.h>
void main()
{
  
  int *ptr;
  printf("dynamic memory allocation:");
  printf("enter a number:");
  ptr =(int *)malloc(sizeof(int));
  scanf("%d",ptr);
  printf("%d",*ptr);
  free(ptr);  
	
	
	
}
