#include<stdio.h>
int a[50];
void quicksort(int m,int r,int n)
{int i,j,flag,p,k,count;

  if(r>m)	
	{
	i=m;
	j=r;
	p=a[i];
	flag=0;
	while(!flag)
	{count++;
		if(count>100)
		return;
     for(k=0;k<n;k++)
	 printf("%d\t",a[k]);
	printf("\n");
     do{
	 ++i;
	 }while(a[i]<=p&&i<=r);
	 while(a[j]>=p&&j>m)
	 {
	 	--j;
	 }
	if(i>=j)
	{
	int t;
	t=a[j];
	a[j]=a[m];
	a[m]=t;
	flag=1;	
	}
	else
	{
	int te;
	te=a[j];
	a[j]=a[i];
	a[i]=te;	
	}
     
    }
    
    quicksort(m,j-1,n);
    quicksort(i,r,n);
}
}


void main()
{
	
	int i,n;
	printf("no of elements?");
	scanf("%d",&n);
	printf("Enter the elements in sorted manner:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		
	}
	  
	  quicksort(0,n-1,n);
     printf("\nthe sorted element:\n"); 
      for(i=0;i<n;i++)
      {
      	printf("%d\t",a[i]);
	  }
      
         
}

