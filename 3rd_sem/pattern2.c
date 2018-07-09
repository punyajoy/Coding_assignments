#include<stdio.h>
void main()
{
	int num=0,i,j,k; 
	printf("give the number of rows:  ");
	scanf("%d",&num);
	for(i=1;i<=num;i++)
	{int p=2*i-1
;		for(j=1;j<=(num-i);j++)
		{
		printf(" ");}
		{
		for(k=1;k<=p;k++)
		if(k<=i)
		{
		printf("%d",k);
		
		}
		else
		{
		printf("%d",(2*i-k));
		
		}
		
	}
        printf("\n");
	}
	
}
