#include<stdio.h>
void main()
{
	
	int i,n,flag=0,pass,temp;
	int num[50];
	printf("no of elements?");
	scanf("%d",&n);
	
	printf("Enter the elements in sorted manner:\n");
	for(i=1;i<=n;i++)
	{
		scanf("%d",&num[i]);
		
	}
    for(pass=1;pass<=n-1;pass++)
    {
    	for(i=pass+1;i<=n;i++)
    	{
    		if(num[i]<num[pass])
    		{
    		
    		temp=num[i];
    		num[i]=num[pass];
    		num[pass]=temp;

    	    }
    	    
		}
   }
     printf("\nthe sorted element:\n"); 
      for(i=1;i<=n;i++)
      {
      	printf("%d\t",num[i]);
	  }
         
	}

