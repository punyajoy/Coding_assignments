#include<stdio.h>
#include<stdlib.h>
int *get(int r,int c)
{
	int i;
	int *x;
	x=(int *)malloc(r*c*sizeof(int));
	printf("enter the elements:");
	for(i=0;i<(r*c);i++)
	{
		scanf("%d",x+i);
		
	}
	return x;
	
}
void display(int *x,int r,int c)
{
	int i,j;
	printf("\n2d array:\n");
	for(i=0; i<c;i++)
	{
	for(j=0; j<r;j++)
	{
		printf("%d\t",*(x+j+i));
		
	}
	printf("\n");
    }
}
void main()
{
	int *a;
	int r,c;
	printf("how manyh elements?\n");
	scanf("%d%d",&r,&c);
	a=get(r,c);
	display(a,r,c);
}

