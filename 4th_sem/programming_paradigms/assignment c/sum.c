#include<stdio.h>
#include<string.h>
int arr[50];
int sum(int n)
{ 
    int x;
	if(n==1)
	{
	   x=arr[0];	
	}
	else
	{
	   x=arr[n-1]+sum(n-1);
	}
	return x;
	
}
void main()
{
	int n,i,result;
	printf("\n give the numbers of element...");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	scanf("%d",&arr[i]);
	result=sum(n);
	printf("\n the sum of given n integers is %d",result);
	
}
