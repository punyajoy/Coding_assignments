#include<stdio.h>
int gcd(int v,int u)
{
  while(v!=u)
  {
  	if(v>u)
  	return gcd(v-u,u);
  	else if(v<u)
  	return gcd(v,u-v);
  	
  	
	}	
	
	return v;
}
void main()
{
	
	
	int x,y,result;
	printf("Enter the two numbers: ");
	scanf("%d%d",&x,&y);
	result=gcd(x,y);
	printf("GCD= %d",result);
}
