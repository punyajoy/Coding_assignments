#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char arr[90];

int changeletter(int n,char c,char t)
{ 
    if(n>0)
	{
		if(arr[n-1]==c)
		    arr[n-1]=t;
		changeletter(n-1,c,t);
		 
	}
		
}
void main()
{
	int n,result,c,t;
	printf("\n give the string ");
	scanf("%s",arr);
	n=strlen(arr);
	printf("\ngive the chracter to be changed\n");
	fflush(stdin);
	scanf("%c",&c);
	printf("the chracter to be replaced");
	fflush(stdin);
	scanf("%c",&t);
	changeletter(n,c,t);
    printf("%s",arr);  	
	
}
