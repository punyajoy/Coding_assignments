#include<stdio.h>
void sum(int a ,int b)
{
	printf("%d",a+b);
	
}
void main()
{
void (*fp)(int a,int b);
fp=sum;	
(*fp)(5,10);
	fp(5,10);
	
}
