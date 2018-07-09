#include<stdio.h>
void main()
{
  int x[50];
  int i=0;
  char resp='y';
  int *p1, *p2;
  p1=&x[0];
  while(resp =='y'||resp=='Y')
  {
  	printf("\nEneter an element: ");
  	scanf("%d",&x[i]);
	printf("\nEnter one more?(y/n): ");
	fflush(stdin);
	resp=getchar();
	i++;  	
  	}
  p2 =&x[i];
  printf("no of elements %d\n",p2-p1);
  for(;p1<p2;)
      printf("%d\t",*p1++);
}
