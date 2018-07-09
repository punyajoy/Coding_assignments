#include<stdio.h>
#include<math.h>
int fact(int l)
{
	int factorial=1;
	int q=1;
	if (l=0)
	{
		factorial=1;
	}
	else
	{
	for(q=1;q<=l;q++)
	   {
	   factorial*=q;}
     }
	return factorial;
	
}
double sine(double y,int z)
{double r=(y*3.14159)/180;
 double resultsin=0;
 int w=1;	 
 for(w=1;w<=z;w++)	
	{ int p=2*w-1;
	  double term2=0;
	  double term =pow(r,p)/fact(p);
	  printf("%lf",term);
	  if((w%2)==0)
	  {term2=-term;}
	  else
	  {term2=term;}
	   printf("%lf",term2);
	  resultsin += term2;
	 }
	 return resultsin;
	
}
double cose(double y,int z)
{
	double r=(y*3.14159)/180;
  double resultcos=0;
  int w=1;	 
 for(w=1;w<=z;w++)	
	{
	  double term1 = pow(r,(2*w-2))/fact(2*w-2);
	  if((w%2)==0)
	  term1=-term1;
	  else
	  term1=term1;

	  resultcos += term1;
	 }
   return resultcos;	
   	
	
}
double exponential(double y,int z)
{
  double resultex=1;
  int w=1;	 
 for(w=0;w<=z;w++)	
	{
	  double term2 =pow(y,w)/fact(w);
	  resultex += term2;
	 }
   return resultex;	
}




void main()
{
	int i,op;
	double x,result;
	printf("give no of iteration:");
	scanf("%d",&i);
	printf("give the angle or value(exponential): ");
	scanf("%lf",&x);
	printf("give the operation");
	printf("\n 1.sin value");
	printf("\n 2.cos value");
	printf("\n 3.exponential value");
	scanf("%d",&op);
	switch(op)
	{
	  case 1:
	  result=sine(x,i);
	  break;
	  case 2:
	  result=cose(x,i); 
	  break;
	  case 3:
	  result=exponential(x,i);
	  break;
	  default:
	  printf("wrong option");
			
	}
	printf("the result is: %lf",result);
}
