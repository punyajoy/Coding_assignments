#include<stdio.h>
int isprime(int n)
{
	int i,flag=1;
	
	for(i=2;i<n;i++)
	{
		printf("%d",i);
		if(n%i==0)
		{
			flag=0;
			break;
			}
		
	
	}
	return flag;
	
}
void main()
{
	int num,result;
	printf("\nEnter the number:  ");
	scanf("%d",&num);
	result=isprime(num);
	if(result == 1)
	    {
		printf("\n%d is prime",num);
    }
	else
	 {   printf("\n%d is Not prime",num); 
     }
}











