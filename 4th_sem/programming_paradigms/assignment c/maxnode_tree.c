#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int degree;
int max=0;
int storage[100];  
void largestnode(int arr[],int height)
{
	if(height==0)
	{
		if(arr[0]>max)
		   max=arr[0];
	}
	else
	{
	   int i,sum,maxnow;
	   sum=0;
       for(i=0;i<height;i++)
	   {
	   	  sum=sum+storage[i];
	   }
	   maxnow=arr[sum];
	   for(i=arr[sum+1];i<arr[sum+storage[height]];i++)
	    {
	   	  if(arr[i]>maxnow)
	   	    {
	   	      maxnow=arr[i];	
			}
        }
        if(maxnow>max)		
		    max=maxnow;
	    largestnode(arr,height-1);
	}

}
void main()
{
     int arr[1000],max_height,i,j,count,k,level_max;
	 printf("give the max height of the tree:");
	 scanf("%d",&max_height);
	 printf("give the degree of the tree:");
	 scanf("%d",&degree);
	 i=0;
	 k=0;
	 j=0;
	 while(i<=max_height)
	 {
	 	level_max=pow(degree,storage[i]);
	 	if(j<level_max)
	 	{    
	 	    int ans;
	 		printf("do u want to change level? press 1 for yes and 0 for no");
	        scanf("%d",&ans);
	        if(ans==0)
	 	     { 
	 	        printf("\n give the node:");
			    scanf("%d",&arr[k]);
	 	        k++;
	 	        j++;
			  }
			else
			  {
			  	if(j>0)
			  	{
			 	i++;
			  	j=0;
			    }
			    else
			    {
			     printf("please give atleast one element!!!\n");
				}
			  }  
		 }
	 	else
	 	{
	 	  	int ans;
	 		printf("the level max capcity exceeded....do u want to change level? press 1 for yes and 0 for no");
	        scanf("%d",&ans);
	        if(ans==0)
	 	     {
			   printf("the program  will exit because of your chutiyapa!!");
			   exit(0);
			  }
			else
			  {
			  	i++;
			  	j=0;
			  }
	 	 		
		}
		storage[i]=j;
	
	 		
	 }
	 largestnode(arr,max_height);
	 printf(" the maximum in the tree is %d",max);
	 
}
	 



