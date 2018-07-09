#include<stdio.h>
void getarr(int arr[], int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("\nEnter the element: ");
		scanf("%d",&arr[i]);
		
	}
	
	
}
void disparr(int arr[], int n)
{
	int i;
	for(i=0; i<n ;i++)
	printf("%d\t",arr[i]);
	
	
	
}

void sort(int arr[],int n)
{
	int t;
	int i,pass;
	for(pass=0;pass<=n-2;pass++)
	{
		for(i=0;i<=n-2;i++)
		{
			if(arr[i]>arr[i+1])
			{
				t=arr[i];
				arr[i]=arr[i+1];
				arr[i+1]=t;
			}
			
		}
		disparr(arr,n);
		printf("\n");
	}
	
	
}
void main()
{
	int x[50];
	int i, n;
	printf("How many elements?");
	scanf("%d",&n);
	getarr(x,n);
	sort(x,n);
	disparr(x,n);
	
}
