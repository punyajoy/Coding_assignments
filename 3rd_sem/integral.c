#include<stdio.h>
float f(float x,float a,float b,float c,float d,float e,float f)
{
	return (((a*x*x)+(b*x)+c)/((d*x*x)+(e*x)+f)); 
	
}
void main()
{
	float h,sum=0,sum1=0,sum2=0,a,b,result,result1,result2,n1,n2,n3,d1,d2,d3;
	int i,n;
	printf("Enter the lower limit, upper limit: ");
	scanf("%f%f",&a,&b);
	printf("Enter the intervals(more intervals means more accurate): ");
	scanf("%d",&n);
	printf("Enter the values of a,b,c,d,e,f in a(x^2)+b(x)+c/ d(x^2)+e(x)+f");
	scanf("%f%f%f%f%f%f",&n1,&n2,&n3,&d1,&d2,&d3);
	h=(b-a)/n;
	for(i=1;i<=n-1;i++)
	{
		if(i%2==0) 
		sum1 += f((a+i*h),n1,n2,n3,d1,d2,d3);
		else
		sum2 += f((a+i*h),n1,n2,n3,d1,d2,d3);	
		
	}
	for(i=1;i<=n-1;i++)
	{
		sum += f((a+i*h),n1,n2,n3,d1,d2,d3);
	
		
	}
	
	result1=(h/2)*(f(a,n1,n2,n3,d1,d2,d3)+f(b,n1,n2,n3,d1,d2,d3)+2*sum);
	result2=(h/3)*(f(a,n1,n2,n3,d1,d2,d3)+f(b,n1,n2,n3,d1,d2,d3)+4*sum1+2*sum2);
	result=(result1+result2)/2;
	printf("Integral value is:%f",result);
	
	
	
	
}
