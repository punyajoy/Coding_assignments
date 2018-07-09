#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#define Inf 99999999
float table[100][100];
int s[100][100];
float  p[50][50];
struct coordinates{
	float x;
	float y;	
	
}points[100];

 

float cost(int i, int j, int k)
{
    return p[i][j]+p[j][k]+p[k][i]; 
}

void polygon_triangulation(int n)
{
   int i,j,k,l,q,gap;
  if(n>3)
  {
   for (gap = 0; gap < n; gap++)
   {
      for (i = 0, j = gap; j < n; i++, j++)
      {
          if (j < i+2)
             table[i][j] = 0.0;
          else
          {
              table[i][j] = Inf;
              for (k = i+1; k < j; k++)
              {
                float val = table[i][k] + table[k][j] + cost(i,j,k);
                if (table[i][j] > val)
                     table[i][j] = val;
              }
          }
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
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		 {
		 	if(k==1)
		 	{
		 	  printf("	%f",table[i][j]);
		    }
		    if(k==2)
		 	{
		 	  printf("	%f",p[i][j]);
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
   	int i,j,n,k;
   	double x,y;
	printf("\n give the no of vertices of the polygon....(please give greater than three)");
   	scanf("\n%d",&n);
   	k=0;
   	for(i=0;i<n;i++)
   	{

   
     	printf("\n give the x-coordinate of point no.%d",i+1);
        scanf("%f",&points[i].x);
  	    printf("\n give the y-coordinate of point no.%d",i+1);
        scanf("%f",&points[i].y);
	}
	
	for(i=0;i<n;i++)
	{
		for(j=i;j<n;j++)
		{
		   	if(i==j)
		   	{
		   		p[i][j]=0;
		    }
		    else
		    {
		    	x=points[i].x-points[j].x;
		    	y=points[i].y-points[j].y;
		    	printf("%f %f",x,y);
	
		    	p[i][j]=sqrt(pow(x,2)+pow(y,2));
		 
		    	p[j][i]=sqrt(pow(x,2)+pow(y,2));
			}
		}
		printf("\n");
		
		
	}
	
	
	
	
	
   
   printf("\n");
   polygon_triangulation(n);
   printf("\n");
   print(n,1);
   printf("\n");
   printf("\n");      
   print(n,2);
   Print_optimal(1,n);
//        	
	
	
	
	
	
	
}
