#include<stdio.h>
void swap1(int x ,int y)
{
	int t;
	t=x;
	x=y;
	y=t;
	
	
}
void swap2(int *x ,int *y)
{
	int t;
	t=*x;
	*x=*y;
	*y=t;
	
}
void main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	swap1(a,b);
	printf("%d%d",a,b);
	swap2(&a,&b);
    printf("%d%d",a,b);
}
