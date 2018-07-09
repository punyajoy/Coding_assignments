#include<stdio.h>
void main()
{
	int m,n,arr[10][10],r[10][2],c[10][2],i,j,k,max,min;
	printf("give the number of rows");
	
	scanf("\n %d",&m);
	printf("give the number of columns");
	scanf("\n %d",&n);
	k=0;
	printf("give %d elements",m*n);
	for(i=0;i<m;i++)
	{
	 for(j=0;j<n;j++)
	 {
	 	scanf("\n%d",&arr[i][j]);
	 }
		
	}
	for(i=0;i<m;i++)
	{   max=arr[i][0];min=arr[i][0];	     
		for(j=1;j<n;j++)
		{
			if(max < arr[i][j])
			max= arr[i][j];
			if(min > arr[i][j])
			min = arr[i][j]; 
		}
		
		r[k][0]=max;
		r[k][1]=min;
		
		k++;
	}
	k=0;
    for(j=0;j<n;j++)
	{   max=arr[0][j];min=arr[0][j];	     
		for(i=1;i<m;i++)
		{
			if(max < arr[i][j])
			max= arr[i][j];
			if(min > arr[i][j])
			min = arr[i][j]; 
		}
		
		c[k][0]=max;
		c[k][1]=min;
		k++;
	}
	int flag=0;
	printf("	THE SADDLE POINT SHOWING MATRIX\n");
	printf("row position   column position   value\n");
	for(i=0;i<m;i++)
	{
	 for(j=0;j<n;j++)
	 {
	 	if(arr[i][j]==r[i][0]&&arr[i][j]==c[j][1])
	 	{
		 printf("%d		%d		%d\n",i,j,arr[i][j]);
	 	 flag=1;
	    }
	 	else if(arr[i][j]==r[i][1]&&arr[i][j]==c[j][0])
	 	{
		 printf("%d		%d		%d\n",i,j,arr[i][j]);
		flag=1; 
	    }
     } 
     
    }
    if(flag==0)
    printf("\n     no saddle point found.");
	
	
}
	
	
	
	
	
	
	


