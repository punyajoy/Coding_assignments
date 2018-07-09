#include<stdio.h>
void main()
{
	
	int i,n,flag=0,pass,temp;
	int num[50];
	printf("no of elements?");
	scanf("%d",&n);
	printf("Enter the elements");
	for(i=1;i<=n;i++)
	{
		scanf("%d",&num[i]);
		
	}
    for(pass=1;pass<=n-1;pass++)
    {
    	for(i=1;i<=n-1;i++)
    	{
    		if(num[i]>num[i+1])
    		{
    		
    		temp=num[i];
    		num[i]=num[i+1];
    		num[i+1]=temp;
    		flag=1;
    	    }
    	    
		}
		if(flag=0)break;
		else
		flag=0;
     }
     printf("\nthe sorted element:\n"); 
      for(i=1;i<=n;i++)
      {
      	printf("%d\t",num[i]);
	  }
         
	}

