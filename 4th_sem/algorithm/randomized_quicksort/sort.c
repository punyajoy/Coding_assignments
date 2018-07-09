#include<stdio.h>
#include<string.h>
int arr[90];
void sort(int n)
{   int max,i,t;
	if(n==1)
	{
		printf("sorting not required");
    }
    else
    {
    	max=0;
    	for(i=0;i<n;i++)
    	    {
    	    	if(arr[i]>arr[max])
    	    	   max=i;
			}
    	t=arr[n-1];
    	arr[n-1]=arr[max];
    	arr[max]=t;
    	sort(n-1);
    	
	}
		
}
void main()
{
	int n,i,result;
	printf("\n give the numbers of element...");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	scanf("%d",&arr[i]);
	printf("\n the sorted order");
	sort(n);
	
	for(i=0;i<n;i++)
	printf("%d ",arr[i]);
}

