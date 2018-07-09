#include<stdio.h>
#include<math.h>
struct store{
	int maximum;
	int minimum; 
};
struct store minmax(int arr[], int n)
{
	struct store s;
	int min=arr[0],max=arr[0],i;
	for(i=1;i<n;i++)
	{
		if(max<arr[i])
		{
			max=arr[i];
		}
		if(min>arr[i])
		{
			min=arr[i];
		}
	}
	s.maximum=max;
	s.minimum=min;
	return s;
 } 


void main()
{
	int i,j,k,n,m,arr[100],partition[50][50],div[100],diff[100],allmax[100],allmin[100];
	printf("give the no of elements:");
	scanf("\n%d",&n);
	printf("give the elements");
	for(i=0;i<n;i++)
	scanf("\n %d",&arr[i]);
	m=0;
	int flag=0;
	for(k=2;k<=(n/2);k++)
	{
		if(n%k==0)
		{
			div[m]=k;
			m++;
			flag=1;
		}
	}
	if(flag==0)
	{
		int sum=0,avg;
		for(i=0;i<n;i++)
		{
			sum+=arr[i];
		}
		avg=sum/n;
		arr[n]=avg;
		n=n+1;
	}
	for(i=0;i<n;i++)
	 {
	 	printf("\n%d",arr[i]);
	 }
	 for(k=2;k<=(n/2);k++)
	{
		if(n%k==0)
		{
			div[m]=k;
			m++;
			
		}
	}
	printf("\n");
	 for(i=0;i<m;i++)
	 {
	 	printf("\n%d",div[i]);
	 }
     k=sqrt(n/2);	
	printf("\n%d",k);
	for(i=0;i<m;i++)
	{
		
		diff[i]=div[i]-k; 
		
	}
	printf("\n");
	for(i=0;i<m;i++)
	 {
	 	printf("\n%d",diff[i]);
	 }
	 struct store divopt=minmax(diff,m);
	 int popt= divopt.maximum;
	 printf("\n\n%d",popt);
	 k=0;
	 for(i=0;i<popt;i++)
   {
		for(j=0;j<(n/popt);j++)
		{
			partition[i][j]=arr[k];
			k++;
		 } 
	 
}
	 printf("\n");
	 for(i=0;i<popt;i++)
   {
		for(j=0;j<(n/popt);j++)
		{
		   printf("  %d  ",partition[i][j]);	
			
		} 
	 printf("\n");
   }
   int p=0;
   for(i=0;i<popt;i++)
	 {
	 	struct store temp=minmax(partition[i],(n/popt));
	 	allmax[p]=temp.maximum;
	 	allmin[p]=temp.minimum;
	 		 p++;
	 }
	 struct store finalmax=minmax(allmax,p);
	 struct store finalmin=minmax(allmin,p);
	 printf(" the max of this array is %d\n the min of this array is %d", finalmax.maximum,finalmin.minimum);  
}
