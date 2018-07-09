#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int arr[90];
int HCF(int n1,int n2)
{ 
    int x;
	if(n1%n2==0)
	{
	   x=n2;	
	}
	else
	{
	   x=HCF(n2,n1%n2);	
	}
	return x;
	
}
void main()
{
	int n1,n2,i,result;
	printf("\n give the first number");
	scanf("%d",&n1);
	printf("\n give the second number");
	scanf("%d",&n2);
	if(n1<n2)
	{
	printf("the program will exit run the .exe file again");
	exit(0);
    }
	result=HCF(n1,n2);
	printf("\n the hcf given two integers is %d",result);
	
}
