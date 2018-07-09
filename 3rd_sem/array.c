#include<stdio.h>
#include<stdlib.h>
void main()
{
	float a[10][10], b[10][10], c[10][10];
	int i,j,k,r1,r2,c1,c2,op;
	float sum;
	printf("\nEnter no.of the rows, cols of matrix1: ");
	scanf("%d, %d",&r1,&c1);
	printf("\nEnter no.of the rows, cols of matrix2: ");
	scanf("%d, %d",&r2,&c2);
	printf("\nEnter elements of matrix1: ");
	for(i=0;i<r1;i++)
		{
			for(j=0;j<c1;j++)
			{
				scanf("%f",&a[i][j]);
				
			}
		}
	printf("\nEnter elements of matrix2: ");	
	for(i=0;i<r2;i++)
		{
			for(j=0;j<c2;j++)
			{
				scanf("%f",&b[i][j]);
				
			}
		}
	
	printf("\nEnter the operation:1.addition,2.multiplication");
	scanf("%d",&op);
	switch(op)
	{
	case 1:
	if(r1!=r2 || c1!=c2)
	{
		printf("\naddition is not possible");
		exit(0);
		}
	for(i=0;i<r1;i++)
		{
			for(j=0;j<c1;j++)
			{
				c[i][j]=a[i][j]+b[i][j];
				printf("%f\t",c[i][j]);
				
			}
			printf("\n");
		}
		break;	
	case 2:
	if(r2!=c1)		
	{
		printf("\nmultiplication is not possible");
		exit(0);
		
    }
    for(i=0;i<r1;i++)
		{
			for(k=0;k<c2;k++)
			{
			
			sum=0.0;
			for(j=0;j<c1;j++)
			{
				c[i][k]=a[i][j]*b[j][k];
				sum+=c[i][k];
				
				
			}
			printf("%d\t",sum);
		   }
			printf("\n");
		}
	
    
    break;
    default:
    		printf("\noption not possible");
		
		
    } 
}
