#include<stdio.h>
#include<math.h>
double squareroot(double y)
{
	double x =sqrt(y);
	return x;
}
void main()
{
	double a,result;
	printf("Give the number whose squareroot is to be found: ");
	scanf("%lf",&a);
	result=squareroot(a);
	printf("result of squareroot of %lf is %lf",a,result);
	
}
