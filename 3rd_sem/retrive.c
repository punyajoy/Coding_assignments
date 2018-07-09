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
  for(i=n-1,j=0;i<n1+n-1,j<n1;i++,j++)
      temp[j]=str[i];
  puts(temp); 	
}
