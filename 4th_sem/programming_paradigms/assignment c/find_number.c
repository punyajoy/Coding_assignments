#include<stdio.h>
#include<string.h>
int arr[50];
int findnum(int n,int num)
{ 
    int x;
	if(n==0)
	{
	   x=0;	
	}
	else if(arr[n-1]==num)
	{
	   x=1;
	}
	else
	{
	   x=findnum(n-1,num);
	}
	return x;
	
}
void main()
{
	int n,i,num,result;
	printf("\n give the numbers of element...");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	scanf("%d",&arr[i]);
	printf("\n give the number to be found");
	scanf("%d",&num);
	result=findnum(n,num);
	if(result == 1)
	{
		printf("\ntrue... number found");
		
	}
	else
	{
		printf("\n false .....number not found");
		
	}
	
}
	
