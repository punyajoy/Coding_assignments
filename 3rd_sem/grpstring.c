#include<stdio.h>
#include<string.h>
#define MAX 50
void sort(char arr[][MAX], int n)
{
	char t[MAX];
	int i,pass;
	for(pass=0;pass<=n-2;pass++)
	{
	for(i=0;i<=n-2;i++)
	{
	if (stricmp(arr[i],arr[i+1])>0)
	{
		strcpy(t,arr[i]);
		strcpy(arr[i+1],arr[i]);
		strcpy(arr[i+1],t);
		
	}
	
}
}
}






void myfunction(char arr[MAX][MAX], int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		puts(arr[i]);
	}
		
}
void main()
{
	char str[MAX][MAX];
	int i,n;
	printf("\nHow many strings?");
	scanf("%d",&n);
	fflush(stdin);
	printf("\nEnter the string: \n");
	for(i=0; i<n;i++)
	  gets(str[i]);
	sort(str,n);   
	printf("\nthe string are: \n");
	myfunction(str,n);
	
}
