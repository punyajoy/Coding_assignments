#include<stdio.h>
void main()
{
	
	int i,j,n,temp;
	int arr[50];
	printf("no of elements?");
	scanf("%d",&n);
	
	printf("Enter the elements in sorted manner:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
		
	}
	for(i=1;i<n;i++)
	{
	temp=arr[i];
	j=i-1;
	while(temp<arr[j]&&j>=0)
	{
	arr[j+1]=arr[j];
	j=j-1;	
	}	
	arr[j+1]=temp;		
	}
	  printf("\nthe sorted element:\n"); 
      for(i=0;i<n;i++)
      {
      	printf("%d\t",arr[i]);
	  }
         
	}

