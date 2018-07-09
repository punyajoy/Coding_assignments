#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>
#define size 1000 
int arr_2[size],arr_index[size],median_arr[5],median_ind[5];

void display(int arr[],int n)
{
	int i;
	
	for(i=0;i<n;i++)
	{
	  
	  printf("  %d",arr[i]);	
	}
	
}
void swap (int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
 
void randomize ( int arr[], int n )
{
	int i;
    // Use a different seed value so that we don't get same
    // result each time we run this program
    srand ( time(NULL) );
 
    // Start from the last element and swap one by one. We don't
    // need to run for the first element that's why i > 0
    for (i = n-1; i > 0; i--)
    {
        // Pick a random index from 0 to i
        int j = rand() % (i+1);
 
        // Swap arr[i] with the element at random index
        swap(&arr[i], &arr[j]);
    }
}

void bubblesort(int arr[],int arr_index[],int n)
{  
   int i,flag=0,pass,temp;
   for(pass=1;pass<=n-1;pass++)
    { 
    	for(i=0;i<n-1;i++)
    	{
    		if(arr[i]>arr[i+1])
    		{
    		temp=arr[i];
    		arr[i]=arr[i+1];
    		arr[i+1]=temp;
    		
    		temp=arr_index[i];
    		arr_index[i]=arr_index[i+1];
    		arr_index[i+1]=temp;
    		flag=1;
    	    }
    	    
		}
		if(flag=0)break;
		else
		flag=0;
     }
}




int find_median(int arr[],int arr_ind[],int n)
{
   int median; 
   bubblesort(arr,arr_ind,n);
   //display(arr,n);
   //display(arr_ind,n);
   if(n%2==0)
   {
     int i=rand()%2+1;
     if(i==1)
     {
     	median=n/2+1;
     }
     if(i==2)
     {
      	median=(n+1)/2;
     }
   }
   else
   {
   	median=(n+1)/2;
    }
   return arr_ind[median-1]; 	
}

int random_select(int arr[], int n)
{
	int i,j,k,rem,quo,median;
	rem=n%5;
	quo=n/5;
	

	if(quo==0)
	{
	    display(arr_index,4);	
		median=find_median(arr,arr_index,rem);	
    }
	else
	{
		for(i=0;i<quo;i++)
		{
		
	       for(j=0;j<5;j++)
	        {
	         median_arr[j]=arr[i*5+j];
	         //display(median_arr,100);
	         median_ind[j]=arr_index[i*5+j];
	         //display(median_ind,100);
	        }
	        k=find_median(median_arr,median_ind,5);		
			arr_2[i]=arr[k];
			arr_index[i]=k;
			//display(arr_index,100);
		}
	    median=random_select(arr_2,quo);
	
	}
return median;
	
}








void main()
{
        FILE *fp1;
        int i,n,arr[1000],med;
        fp1=fopen("random_select.txt","w");
        srand((unsigned)time(NULL));
        printf("give the value of n upto which you want to take the natural numbers:");
        scanf("\n%d",&n);
		fprintf(fp1,"\n%d",n);	
		for(i=0;i<n;i++)
        {
         arr[i]=i+1;
		 arr_index[i]=i+1;	
        }
        for(i=0;i<1000;i++)
        {
        randomize(arr,n);
        med=random_select(arr,n);
        fprintf(fp1,"\n%d",med);
        printf("median=%d",arr[med]);
        }
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
}



