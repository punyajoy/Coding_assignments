#include<stdio.h>
void main()
{
	int n,i,j=1;
	double x,r,t,sum;
	
	printf("give no of iteration:");
	scanf("%d",&n);
	printf("give the angle or value(exponential): ");
	scanf("%lf",&x);
	r=(x*3.14159)/180;
	t=r;
	sum=r;
	printf("\n iteration=%d\t sum=%lf",j,sum);
    i=2;	
	for(j=2; j<=n;j++)
	{
	t=(-1)*t*r*r/(i*(i+1));
	sum=sum+t;
	printf("\n iteration=%d\t sum=%lf",j,sum);
	i=i+2;
    }
}
