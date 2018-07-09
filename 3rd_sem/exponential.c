#include<stdio.h>
void main()
{
	int n,i,j=1;
	double x,r,t,sum;
	
	printf("give no of iteration:");
	scanf("%d",&n);
	printf("give the angle or value(exponential): ");
	scanf("%lf",&x);
	
	t=1;
	sum=1;
	printf("\n iteration=%d\t sum=%lf",j,sum);
    i=0;	
	for(j=2; j<=n;j++)
	{
	t=t*x/(i+1);
	sum=sum+t;
	printf("\n iteration=%d\t sum=%lf",j,sum);
	i=i+1;
    }
}
