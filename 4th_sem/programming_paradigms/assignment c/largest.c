#include<stdio.h>
#include<string.h>
int arr[90];
int largest(int n)
{ 
    int x;
	if(n==1)
	{
	   x=arr[0];	
	}
	else
	{
		if(arr[n-1]>largest(n-1))
		   x=arr[n-1];
		else
		   x=largest(n-1);
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
	result=largest(n);
	printf("\n the largest of given %d integers is %d",n,result);
	
}
