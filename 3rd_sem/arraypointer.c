#include<stdio.h>
void main()
{
	int arr2[][4]={{1,2,3},{2,3,4},{4,5,6}};
	int *ptr2 =&arr2[0][0];
	int i,j;
	printf("\nAccessing elements using array name:\n");
	
	for(i=0; i<3; i++)
	{
		for(j=0;j<4;j++)
		{
			printf("%d\t",*(*(arr2+i)+j));
		}
		printf("\n");
	}
	
	for(i=0; i<3; i++)
	{
		for(j=0;j<4;j++)
		{
			printf("%d\t",*ptr2++);
		}
		printf("\n");
		}
	
}
