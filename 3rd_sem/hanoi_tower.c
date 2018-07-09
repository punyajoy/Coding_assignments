#include<stdio.h>
void towers(int n,char a,char c,char b)
{
	if(n==1)
	{
		printf("\nMove the disk %d from pole %c to pole %c",n,a,c);
    }
    else
    {
    	towers(n-1,a,b,c);
    	printf("\nMove the disk %d from pole %c to pole %c",n,a,c);
    	towers(n-1,b,c,a);
    }
}

void main()
{
	int n;
	printf("enter the number of disks: ");
	scanf("%d",&n);
	towers(n,'A','C','B');
	
	
}
    	
	
		
		
		
	
	
	
	

