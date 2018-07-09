#include<stdio.h>
void main()
{
	 int i,j;
	int fact=1;
	scanf("%d",&i);
	if (i==0)
	{
		fact=fact;		
	}
	else
	{
	for(j=1;j<=i;j++)
	{
		fact=fact*j;
	
	}
    }
	printf("%d",fact) ;	
	
	
}
