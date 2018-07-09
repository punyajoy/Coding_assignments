#include<stdio.h>
void main()
{
	unsigned long int num;
	int digit,sum=0;
	printf("enter the number: ");
	scanf("%ld",&num);
	while(num!=0)
	{
		digit =num%10;
		sum=sum+digit;
		num=num/10;
		
	}
	printf("Sum of the digits: %d", sum);
	
	
	}
