#include<stdio.h>
int binarysearch(int lower,int upper,float arr[],float s)
{
	float m;
	int flag=0;
	int mno=(lower+upper)/2;
	m=arr[mno];
	if(lower!=upper)
	{
	
	if(s==m)
	{
		printf("the element is found at %d",mno+1);
		flag=1;
	}
	else if(s<m)
	{
	   	binarysearch(lower,mno-1,arr,s);
	   	
	}
	else
	{
		binarysearch(mno+1,upper,arr,s);
		
	}
	return flag;
    }
}
void main()
{
	
	int i,n,flag;
	float arr[50],s;
	printf("no of elements?");
	scanf("%d",&n);
	printf("Enter the elements in sorted manner:\n");
	for(i=0;i<n;i++)
	{
		scanf("%f",&arr[i]);
		
	}
	printf("enetr the element to search:");
	scanf("\n%f",&s);
	flag=binarysearch(1,n,arr,s);
	printf("\n%d",flag);
	if(flag==0)
	{
		printf("element is not found");
	}
	}
	
	
	
	
	
	

