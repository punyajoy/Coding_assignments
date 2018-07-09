#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
int random(int n)
{
	
	int i;
	i=rand()%n;
	return i;
}
void main()
{
	srand((unsigned)time(NULL));
	int n,ctr,arr[20][20],t,i,j,k,l,initial,final;
	
	printf("\ngive the size of adjacency matrix");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		for(j=i;j<n;j++)
		{
			if(i==j)
			arr[i][i]=0;
			else
			{
			t=random(2);
			arr[i][j]=t;
	        arr[j][i]=t;
            }
	     	
      	}
			
	}
	printf("\n");
	for(i=0;i<n+1;i++)
	{
		printf("%d  ",i);
		for(j=0;j<n;j++)
		{
			if(i==0)
		        printf("%d   ",j+1);
		    else
		        printf("%d   ",arr[i-1][j]);
	   	
      	}
      	
      	printf("\n");

	}
	printf("give the initial and final position with in range:-");
	do{
	scanf("\n%d",&initial);
	scanf("\n%d",&final);
   }while(initial>n||final>n);
   k=initial-1;
   l=final-1;
   if(arr[k][l]==1)
     ctr++;
   for(i=0;i<n,i!=l;i++)
     {
     	 if(arr[k][i]==1)
     	   printf("\n%d",i);
	 }
    printf("\n%d",i);
   
   
   
   
   
   
   
   
   
}
