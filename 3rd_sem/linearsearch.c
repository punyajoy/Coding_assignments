#include<stdio.h>
void main()
{
	
	int i,n,flag=0;
	float arr[50],s;
	printf("no of elements?");
	scanf("%d",&n);
	printf("Enter the elements:\n");
	for(i=0;i<n;i++)
	{
		scanf("%f",&arr[i]);
		
	}
	printf("enetr the element to search:");
	scanf("\n%f",&s);
	for(i=0;i<n;i++)
	{
		if(s==arr[i])
	    {
	    	printf("element found at %d",i+1);
			}	
	
		
	}
	
	
	
	
	
	
}
