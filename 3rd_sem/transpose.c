#include<stdio.h>
void main()
{
	int i,j,r,c;
	int mat[50][50];
    printf("no of rows and column(write as m, n):");
	scanf("%d, %d",&r,&c);
	printf ("\nenter the matrix:\n");
	for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				scanf("%d\t",&mat[i][j]);
				
			}
		}
	printf ("\n the transpose matrix:\n");
	for(i=0;i<c;i++)
	{
		for(j=0;j<r;j++)
		{
			printf("%d\t",mat[j][i]);
		}
		printf("\n");
	}
	
	
}
