#include<stdio.h>
int gcd(int ,int);
void main()
{
	int x,y,z;
	printf("\nType two integer values: ");
	scanf("%d,%d",&x,&y);
	z=gcd(x,y);
	printf("\nGCD value =%d", z);
	printf("\nLcm value =%d",(x*y)/z);
	
}
int gcd(int u,int v)
{
	
	int r;
	while(v!=0)
	{
		r=u%v;
		u=v;
		v=r;
		
		
	}
	return u;
	
	
}
