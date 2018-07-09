#include<stdio.h>
#include<time.h>
#define MAX 100000
int random()
{
	
	int i;
	i=rand();
	return i;
}

void bubblesort(int arr[],int n)
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
    		flag=1;
    	    }
    	    
		}
		if(flag=0)break;
		else
		flag=0;
     }
     printf("\nthe sorted element:\n"); 
      for(i=0;i<n;i++)
      {
      	printf("%d\t",arr[i]);
	  }
}

void selectionsort(int arr[],int n)
{
	int i,j,temp,maxi;
	for(j=n;j>0;j--)
	{
		maxi=0;
	for(i=0;i<j;i++)
	{
		if(arr[i]>arr[maxi])
		  {
	        maxi=i;
			 	  	
		  }
	}

	temp=arr[maxi];
	arr[maxi]=arr[j-1];
	arr[j-1]=temp;
    }
printf("\nthe sorted element:\n"); 
      for(i=0;i<n;i++)
      {
      	printf("%d\t",arr[i]);
	  }
	
}

void insertionsort(int arr[],int n)
{
	int i,j,current;
	for(i=1;i<n;i++)
	{
	if(arr[i]<arr[i-1])
	{
	  current=arr[i];	
		for(j=i-1;j>=0;j--)
		{
			arr[j+1]=arr[j];
			if(j==0||arr[j-1]<=current)
			break;
		}
		arr[j]=current;
		}	
	}
printf("\nthe sorted element:\n"); 
      for(i=0;i<n;i++)
      {
      	printf("%d\t",arr[i]);
	  }
	
	
	
}
int partition(int arr[],int low,int high)
{
	int t,i,pivot,lastsmall;
	t=arr[low];
	arr[low]=arr[(low+high)/2];
	arr[(low+high)/2]=t;
	pivot=arr[low];
	lastsmall=low;
	for(i=low+1;i<=high;i++)
	{
		if(arr[i]<pivot)
		    {
		    	lastsmall++;
            t=arr[lastsmall];
			arr[lastsmall]=arr[i];
			arr[i]=t;
			
		    }
		    
	}
	t=arr[low];
		arr[low]=arr[lastsmall];
		arr[lastsmall]=t;
	
	return lastsmall;
	
	
}
void recquicksort(int arr[],int low, int high)
{
	int pos,i;
	if(low<high)
	{
		pos=partition(arr,low,high);
		recquicksort(arr,low,pos-1);
		recquicksort(arr,pos+1,high);
	}
}
void quicksort(int arr[], int n)
{
	int i;
	recquicksort(arr,0,n-1);
	printf("\nthe sorted element:\n"); 
      for(i=0;i<n;i++)
      {
      	printf("%d\t",arr[i]);
	  }
	
}

   void merge(int,int,int,int arr[]); 
   void merge_sort(int low,int high,int arr[]) 
   { 
     int mid; 
     if(low<high) 
     { 
       mid=(low+high)/2; 
       merge_sort(low,mid,arr); 
       merge_sort(mid+1,high,arr); 
       merge(low,mid,high,arr); 
     } 
   } 
   void merge(int low,int mid,int high,int arr[]) 
   { 
     int h,i,j,k,b[high]; 
     h=low; 
     i=low; 
     j=mid+1; 
     while((h<=mid)&&(j<=high)) 
     { 
       if(arr[h]<=arr[j]) 
       { 
         b[i]=arr[h]; 
         h++; 
       } 
       else 
       { 
         b[i]=arr[j]; 
         j++; 
       } 
       i++; 
     } 
     if(h>mid) 
     { 
       for(k=j;k<=high;k++) 
       { 
         b[i]=arr[k]; 
         i++; 
       } 
     } 
     else 
     { 
       for(k=h;k<=mid;k++) 
       { 
         b[i]=arr[k]; 
         i++; 
       } 
     } 
     for(k=low;k<=high;k++) 
     arr[k]=b[k]; 
   } 
   

void main()
{
	srand((unsigned)time(NULL));
	clock_t time;
	int t,num1[MAX],num2[MAX],num3[MAX],num4[MAX],num5[MAX],n,i,j;
	FILE *fp2;
	fp2=fopen("sort.txt","w");

for(j=2;j<90000;j=j+10)
 {
 	
    fprintf(fp2,"%d  ",j);		
	for(i=0;i<j;i++)
	{   t=random();
		num1[i]=t;
		num2[i]=t;
		num3[i]=t;
		num4[i]=t;
		num5[i+1]=t;
				
	}
	time=clock();
    selectionsort(num1,j);
    time=clock()-time;
	double timetaken=((double)time)/CLOCKS_PER_SEC;
	fprintf(fp2,"%f  ",timetaken);
		
	time=clock();
    bubblesort(num2,j);
    time=clock()-time;
	timetaken=((double)time)/CLOCKS_PER_SEC;
	fprintf(fp2,"%f  ",timetaken);
	
	
	time=clock();
    insertionsort(num3,j);
    time=clock()-time;
	timetaken=((double)time)/CLOCKS_PER_SEC;
	fprintf(fp2,"%f  ",timetaken);

    
	time=clock();
    quicksort(num4,j);
    time=clock()-time;
	timetaken=((double)time)/CLOCKS_PER_SEC;
	fprintf(fp2,"%f  ",timetaken);
		
	
   time=clock();
  merge_sort(1,j,num5);
    printf("\nthe sorted element:\n"); 
     for(i=1;i<=j;i++)
     {
      	printf("%d\t",num5[i]);
    }
	
    time=clock()-time;
    timetaken=((double)time)/CLOCKS_PER_SEC;
	fprintf(fp2,"%f  ",timetaken);
   fprintf(fp2,"\n");   
	
	
}
fclose(fp2);
}



