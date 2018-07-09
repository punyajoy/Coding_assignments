#include<stdio.h>
long fact(int i)
{  
    int j;
	long fact=1;
	if (i==0)
	{
		fact=1;		
	}
	else
	{
	for(j=1;j<=i;j++)
	{
		fact*=j;
	
	}
}
	return fact;
}
int C(int g,int h)
{
	int result = fact(g)/(fact(h)*fact(g-h));
	
	return result;
	
	
}
void main()
{
	int y,n,i,j=0;
	printf("give no of rows:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
	for(j=1;j<=(n-i);j++)
		{
		printf(" ");}
		int k=0;
	for(y=0;y<(2*i+1);y++) 
	{   
		if (y%2!=0)
		{printf(" ");}
		else
	    {
		printf("%2d",C(i,k));
		k++;
	    }
	}
	printf("\n");
}
	
}
