#include<stdio.h>
#include<string.h>
#include<math.h>

void main()
{
	char A[100];
	int n,rem,i,j;
	int chunk[100];
	gets(A);
	n=strlen(A);
	rem=4-n%4;
	if(n%4==0)
	{
		rem=0;
	}
	for(i=0;i<rem;i++)
	{
	strrev(A);
	strcat(A,"0");
	strrev(A);
	puts(A);	
	}
	n=strlen(A);
	int k=0;
	for(i=0;i<n;i=i+4)
	{ 
	chunk[k]=0;
		 for(j=0;j<4;j++)
		    {
		    	
		    	chunk[k]=chunk[k]+(A[i+j]-48)*pow(10,3-j);
		    		   	
			}
		 		
		k++;
	}
	int r;
	for(r=0;r<k;r++)
	printf("%d\n",chunk[r]);
	
		
	
	
}

