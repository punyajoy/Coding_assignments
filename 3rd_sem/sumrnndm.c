#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void main()
{
	int a[100],i=0,num,sum=0;
	clrscr();
	randomize();
	while(i<100)
	{
		num=random(101);
		if(num==0)num++;
		a[i]=num;
		printf("\t %d",a[i]);
		sum=sum+a[i];
		i++;
	}
	printf("\nSum of random nos=%d",sum);
	
		
}




