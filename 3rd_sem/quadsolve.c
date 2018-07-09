#include<stdio.h>
#include<math.h>
void  main()
{
	int a,b,c;
	float x1,x2,x,d,r1;
	char t;
      do{
	
	printf("type the values of a,b,c");
	scanf("%d%d%d",&a,&b,&c);
	if(a==0)
	{
		printf("give the values for only quad not linear\n");
		printf("type them again\n");
		continue;
	}
	printf("%dx^2+%dx+%d=0",a,b,c);
	
	d=b*b-4*a*c;            /*find the discriminator*/
	x=-b/(2*a);
	if (d>0)
	{
		printf("\n Roots of the equations are ");
		x1=(-b+sqrt(d))/(2*a);
		x2=(-b-sqrt(d))/(2*a);
		printf("\nRoot 1 = %.3f",x1);
        printf("\nRoot 2 = %.3f",x2);
		}
	else if (d==0)
	{
		
		printf("\n common root is %0.3f",x);
				
	}
	else 
	{
		printf("\n Complex Roots of the equations are ");
		d=-d;
		r1=sqrt(d)/(2*a);
		printf("\nRoot 1=%.3f+i%.3f",x,r1);
		printf("\nRoot 1=%.3f-i%.3f",x,r1);
	
	}
	printf("do you want to continue?give (y/n)");
	scanf("%c",&t);
	}	while((t=getchar())!='n');
}
