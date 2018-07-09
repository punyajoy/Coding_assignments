#include <stdio.h>
#include <stdlib.h>
#define Inf 99999999
int m[100][100];
int s[100][100];



int matrix_rec_chain(int p[],int i,int j)
{
   int n,k,l,q;
   if(i!=j)
	{
	   m[i][j]=Inf;
	   for(k=i;k<=j-1;k++)
	   {
	   	
		   q=matrix_rec_chain(p,i,k)+matrix_rec_chain(p,k+1,j)+p[i-1]*p[j]*p[k];
	   	if(q<m[i][j])
	   	{
	   		m[i][j]=q;
		   }
	   	
		}	
	   }   
   
   
   
   
   
   
   
   
}   			
		   
          		
   		
   		
   		
   
void Print_optimal(i,j)
{
	int k;
	k=1;
	if(i==j)
	{
		printf("A%d",i);
		
	}
	else
	{
		printf("(");
		Print_optimal(i,s[i][j]);
		Print_optimal(s[i][j]+1,j);
		printf(")");
	}
		
		
 } 
	
	
void print(int n,int k)
{
	int i,j;
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=n;j++)
		 {
		 	if(k==1)
		 	{
		 	  printf("	%d",m[i][j]);
		    }
		    if(k==2)
		 	{
		 	  printf("	%d",s[i][j]);
		    }
		}
		printf("\n");
		
	}
	
	
	
	
	
}
void printp(int p[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{	
	printf(" %d",p[i]);
	}
	
}

	




void main()
{
   	int p[100],i,n,k,rows,col;
   	printf("\n give the no of matrix that is needed to be parenthesize");
   	scanf("\n%d",&n);
   	k=0;
   	for(i=0;i<n;i++)
   	{

   
        if(i==0)
        {
   		printf("\n give the rows of %d matrix",i+1);
        scanf("%d",&rows);
		p[k]=rows;
        k++;
        }
   	    printf("\n give the col of %d matrix",i+1);    		
   		scanf("\n%d",&col);
        p[k]=col;
        k++; 
   }
   printp(p,n+1);
   printf("\n");
   int lowest=matrix_rec_chain(p,1,n+1);
   print(n,1);
   printf("the lowest matrix order is %d",lowest);
   
   
   
   
}
