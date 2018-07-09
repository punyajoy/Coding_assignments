#include<stdio.h>
#include<string.h>
void main()
{
  char str[50],temp[50];
  int n,n1,i,j;
  gets(str);
  scanf("%d",&n);
  fflush(stdin);
  scanf("%d",&n1);
  for(i=0,j=0;i<n-1,j<n1;i++,j++)
      temp[j]=str[i];
  for(i=n-1+n1,j=n-1;i<strlen(str),j<strlen(str)-n;i++,j++)
      temp[j]=str[i];   
	   
  puts(temp); 	
}
