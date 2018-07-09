#include<stdio.h>
#include<stdlib.h>
void main()
{
  
  int n;
  char *ptr;
  printf("dynamic memory allocation:");
  printf("enter size of name:");
  scanf("%d",&n);
  fflush(stdin);
  ptr =(char *)malloc(n*sizeof(char));
  printf("enter a string:");
  scanf("%[^\n]",ptr);
  printf("%s",ptr);
  free(ptr);  
	
}
