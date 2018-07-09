#include<stdio.h>
void main()
{	
	int i,j,n1,n2,x,y;
	int a[50],b[50],c[100];
	printf("no of elements?");
	scanf("%d",&n1);
	
	printf("Enter the elements in sorted manner:\n");
	for(i=0;i<n1;i++)
	{
		scanf("%d",&a[i]);
		
	}
	printf("no of elements?");
	scanf("%d",&n2);
	
	printf("Enter the elements in sorted manner:\n");
	for(i=0;i<n2;i++)
	{
		scanf("%d",&b[i]);
		
	}
	i=0;
	j=0;
	int k=0;
	while(i<n1&&j<n2)
	{
		if(a[i]<=b[j])
		{
			c[k]=a[i];
			i++;
			k++;
		}
		else
		{
			c[k]=b[j];
			j++;
			k++;
					
		}
	}
	if(i<n1)
	{
		for(x=i;x<n1;x++)
		{
			c[k]=a[x];
			i++;
			k++;
			
		}
	}
	else if(j<n2)
	{
		for(y=j;y<n2;y++)
		{
			c[k]=b[y];
			j++;
			k++;
			
			
		}
		
		
	}

     printf("\nthe sorted element:\n"); 
      for(i=0;i<k;i++)
      {
      	printf("%d\t",c[i]);
	  }
 






}
