#include<stdio.h>
void main()
{
	float u,a,s;
	int t,n,i;
	printf("\nEnter initial velocity: ");
	scanf("%f",&u);
	printf("\nEnter the accleration: ");
	scanf("%f",&a);
	printf("\nEnter the time: ");
	scanf("%d",&t);
	printf("\nEnter the time interval: ");
	scanf("%d",&n);
	for(i=0;i<=t ;i+=n)
	{
		s=u*i+(0.5)*a*i*i;
		printf("\nTime=%d sec \t Distance =%.4f mts", i, s);
    
	}
		
		
	}
	
	
	
	

