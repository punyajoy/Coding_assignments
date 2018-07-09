#include<stdio.h>
int x=10;
void one()
{   int x=5;
	static int y=1;
	printf("\n%d",y);
	y++;x++;
	printf("\n x=%d",x);
	
	
}
void main()
{
	one();
	one();
	one();
	printf("%d",x);
	n();
	
}
