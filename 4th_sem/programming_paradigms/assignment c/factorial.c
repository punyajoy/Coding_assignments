#include<stdio.h>
#include<string.h>

int factorial(int n)
{ 
    int x;
	if(n==1)
	{
	   x=1;	
	}
	else
	{
		x=n*factorial(n-1);
	}
	return x;
	
}
void main()
{
	int n,result;
	printf("\n give the number...");
	scanf("%d",&n);
	result=factorial(n);
	printf("\n the factorial n is %d",result);
	
}
