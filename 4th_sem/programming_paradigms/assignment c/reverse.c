#include<stdio.h>
#include<string.h>
int arr[90];
void reverse(int n)
{ 
	if(n>0)
	{
		printf("%d	",arr[n-1]);
		reverse(n-1);
	}
		
}
void main()
{
	int n,i,result;
	printf("\n give the numbers of element...");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	scanf("%d",&arr[i]);
	printf("\n the reverse order");
	reverse(n);
	
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
