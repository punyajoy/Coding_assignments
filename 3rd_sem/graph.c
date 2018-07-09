#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#define MAX 50
int z=0;
int v=1;
int w=0;
int patharray[MAX][MAX];
int visited[MAX];
int stack[MAX];
int top=0;

void push(int val)
{
	if(top<MAX)
	{
		stack[top] =val;
		top++;
	}
	else
	{
		printf("Stack is full");
	}
	
}
int pop()
{
	int val;
	if(top>0)
	{
	    top--;
		val =stack[top];
	    return val;
	}
	else
	{
		printf("\nStack is empty");
		return -1;
	}
	
}
void display()
{
	int i;
	printf("\n");
	for(i=0;i<top;i++)
	  printf("%d\t",stack[i]);
	
}
void disp(int n)
{
	int i;
	printf("\n");
	for(i=0;i<n;i++)
	  printf("%d",i+1);
	  
	printf("\n"); 
	  for(i=0;i<n;i++)
	  printf("%d",visited[i]);

}

int random(int n)
{
	
	int i;
	i=rand()%n;
	return i;
}
int searchzeros(int n,int arr[])
{
	int i,flag;
	flag=0;
	for(i=0;i<n;i++)
	{
		if(visited[i]==0&&arr[i]==1)
		{ 
		flag=1;
		break;
	    }
	}
	
	return flag;
}
void findpath(int G[MAX][MAX],int initial,int end,int n)
{   int qdeleted,i,j;
    
	push(initial+1);
    visited[initial]=1;
    
    for(i=0;i<n;i++)
    {
    	printf("%d ",i);
    	if(i==end&&G[initial][i]==1)
    	{
    	   push(end+1);
	        for(j=0;j<top;j++)
	        {  patharray[w][v]=stack[j];
	            v=v+1;
	        }
	         qdeleted=pop();
		patharray[w][0]=v-1;
		v=1;
		w=w+1;
		 		
		}
    	
    	else if(visited[i]==0&&G[initial][i]==1)
				   {
	
				   	  findpath(G,i,end,n);
		   	
				   }
	    if(i==n-1)
		{
		qdeleted=pop();
    	visited[qdeleted-1]=0;
        }
        
	}
	  
	}
     
	
	




void main()
{
	srand((unsigned)time(NULL));
	int n,r,ctr,arr[MAX][MAX],t,i,j,k,l,initial,final;
	
	printf("\ngive the size of adjacency matrix");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		for(j=i;j<n;j++)
		{
			if(i==j)
			arr[i][i]=0;
			else
			{
			t=random(2);
			arr[i][j]=t;
	        arr[j][i]=t;
            }
	     	
      	}
			
	}
	printf("\n");
	for(i=0;i<n+1;i++)
	{
		printf("%d  ",i);
		for(j=0;j<n;j++)
		{
			if(i==0)
		        printf("%d   ",j+1);
		    else
		        printf("%d   ",arr[i-1][j]);
	   	
      	}
      	
      	printf("\n");

	}
	printf("give the initial and final position with in range:-");
	ctr=0;
	do{
	printf("\nintial position:");	
	scanf("%d",&initial);
	printf("\nfinal position: ");
	scanf("%d",&final);
	if(initial<=n&&final<=n)
	    break;
	if(ctr>=0)
	{
		printf("\nplease give the numbers again");
		
	}
	ctr=ctr+1;
   }while(initial>n||final>n);
   visited[final-1]=1;
   findpath(arr,initial-1,final-1,n);
   printf("\n");
   
   for(i=0;i<w;i++)
      {
	  for (j=0;j<n+1;j++)
          printf("%d ",patharray[i][j]);
          
      printf("\n");    
          
    }     
   
    
   

   
   
   
}
