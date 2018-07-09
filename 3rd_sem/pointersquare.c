#include<stdio.h>
void main()
{
	int var=100;
	int *p1;
	int **p2;
	p1=&var;
	p2=&p1;
	printf("%d",*p1);
	printf("%d",**p2);	
}
