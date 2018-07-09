#include<stdio.h>
#include<string.h>
char arr[90];

int palindrome(int m,int n)
{ 
    int x;
	if(n==0||n==1)
	{
	   x=1;	
	}
	else
	{
		if((int)arr[m]==(int)arr[n-1])
		   {
		   x=palindrome(m+1,n-1);
		   }
		else
		   x=0;
	}
	return x;
	
}
void main()
{
	int n,result;
	printf("\n give the string ");
	scanf("%s",arr);
	n=strlen(arr);
	result=palindrome(0,n);
    if(result==1)
      printf("\ntrue");
    else
       printf("\nfalse");      
	  	
	
}
