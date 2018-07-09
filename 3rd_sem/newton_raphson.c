#include<stdio.h>
#include<math.h>
double f(double x)
{
	return ((x*x*x)-(2*x)-5);
}
double f1(double x)
{
	return (3*(x*x)-2);
}
void main()
{
	double x0,h,max,root,x1;
	int i, n;
	printf("Enter the first approximation: ");
	scanf("%lf",&x0);
	printf("Enter the max error");
	scanf("%lf",&max);
	printf("Enter no of iteration");
	scanf("%d",&max);
	i=1;
	printf("\nIteration no.\t Approxmation of root value ");
	while(i<=n)
	{
		h=f(x0)/f1(x0);
		x1=x0-h;
		printf("\n%d\t\t%.10lf",i,x1);
		if(abs(h)<max)
		  {
		  	root=x1;
		  	break;
		  }
		else
		{
			x0=x1;
		}
		i++;
	}
	if(root==x1)
	printf("\n\n the root is %.10lf",x1);
	else
	printf("\n insufficient");
		
}

