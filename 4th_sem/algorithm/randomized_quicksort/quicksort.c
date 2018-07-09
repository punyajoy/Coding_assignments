#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#define size 1000
FILE *fp1;
int c,flag=0;
int ind,num,comparison;
int pivotcalc(float arr[],int first,int last)
{
  
  int pivot_ind;
  pivot_ind=0;
  pivot_ind=rand()%(last-first+1);
     
   
  return pivot_ind;
}


int partition(float arr[],int first,int last)
{
     int pivot;
     float temp,pivotvalue;
     pivot=rand()%(last-first+1);
     temp=arr[first+pivot];                         //this is done to bring the pivot element to the front 
     arr[first+pivot]=arr[first];
     arr[first]=temp;
     pivotvalue=arr[first];
     if(last == pow(2,9)-1&& first == 0)
     {
	 fprintf(fp1,"%d\n",pivot);
     }
     printf("%f\n",pivotvalue);
     int leftpoint = first+1;
     int rightpoint= last;
     int flag_in=0;

     while(!flag_in)
     {
        while(leftpoint<=rightpoint&&arr[leftpoint]<=pivotvalue)
         {
		 leftpoint=leftpoint+1;
		 comparison++;
		  }
        while(rightpoint>=leftpoint&&arr[rightpoint]>=pivotvalue)
         {
		 rightpoint=rightpoint-1;
		 comparison++;
		 }
            
        if(rightpoint<leftpoint)
           {
		   flag_in=1;
		   
		   }
        else
           {
           	
             temp=arr[leftpoint];
             arr[leftpoint]=arr[rightpoint];
             arr[rightpoint]=temp;
             
            }
      }
      temp = arr[first];
      arr[first]=arr[rightpoint];
      arr[rightpoint]=temp;
      
    
    
   return rightpoint;
}
void quicksort_help(float arr[],int first,int last)
{
  int split;

  if(first<last)
   {
      split=partition(arr,first,last);
      quicksort_help(arr,first,split-1);
      quicksort_help(arr,split+1,last);

   }

}


void quicksort(float arr[],int n)
{
   quicksort_help(arr,0,n-1);
   printf("quicksort end \n");
}

void main()
{
    float arr[size],arr_norm[size];
    int num,i,j,k,x,l,num1;
    
    
     FILE *fp3,*fp4,*fp5,*fp6;
     fp1=fopen("pivot.txt","w");
     fp3=fopen("uniform.txt","r");
     fp4=fopen("normal.txt","r");
     fp5=fopen("comparison_uniform_random.txt","w");
     fp6=fopen("comparison_normal_random.txt","w");
     for(i=1;i<10;i++)
     {
       num=pow(2,i);
       for(j=0;j<num;j++)
       {
        fscanf(fp3,"%f\n",&arr[j]);
       }
     for(x=0;x<100;x++)
	 {
	 srand((unsigned)time(NULL)*x);	
	 comparison=0;
     quicksort(arr,num);
     fprintf(fp5,"%ld\n",comparison);
     }
     }
      fclose(fp5);
      fclose(fp3);
          
     for(k=1;k<10;k++)
     {
       num1=pow(2,k);
       printf("%d",k);
       for(l=0;l<num1;l++)
       {
        fscanf(fp4,"%f\n",&arr_norm[l]);
       }
         
	 
    for(x=0;x<100;x++)
	{
	 srand((unsigned)time(NULL)*x);	
	 comparison=0;
     quicksort(arr_norm,num1);
     fprintf(fp6,"%ld\n",comparison);
    }
    }
    fclose(fp6);
    fclose(fp4);
    fclose(fp1);


}
                                                                                         
