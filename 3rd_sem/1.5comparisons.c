#include<stdio.h>
void main()
{
	int arr[100],i,j,k=0,n,max[50],min[50];
	printf("give the no of elements: ");
	scanf("\n%d",&n);
	printf("give the elements");
	for(i=0;i<n;i++)
	scanf("\n%d",&arr[i]);
	if(n%2==0)
	{
		for(i=0;i<n-1;i=i+2)
		{
			if(arr[i]>arr[i+1])
			{
				max[k]=arr[i];
				min[k]=arr[i+1];
				k++;
			}
			else 
			{
				
				min[k]=arr[i];
				max[k]=arr[i+1];
				k++;
			}
			
		}
	}
	else
	{    k=0;
		for(i=0;i<n-2;i=i+2)
		{
			if(arr[i]>arr[i+1])
			{
				max[k]=arr[i];
				min[k]=arr[i+1];
				k++;
			}
			else 
			{
				
				min[k]=arr[i];
				max[k]=arr[i+1];
				k++;
			}
			
		}
		min[k]=arr[n-1];
		max[k]=arr[n-1];
		k++;
		
		
	}
	printf("max  min\n");
	for(i=0;i<k;i++)
	printf("%d   %d\n",max[i],min[i]);
	
		int max1=max[0];
		int min1=max[0];
		int max2=min[0];
		int min2=min[0];
	
	for(i=1;i<k;i++)
	{ 
		if(max[i]>max1)
		{
			max1=max[i];
			
		}
		else
		{
			min1=max[i];
		}
		if(min[i]>max2)
		{
			max2=min[i];			
		}
		else
		{
			min2=min[i];
		}
		
		
	}
	if(max1>max2)
	printf("%d",max1);
	else
	printf("%d",max2);
	
	
	if(min1>min2)
	printf("%d",min2);
	else
	printf("%d",min1);
	
	
	
	
}
