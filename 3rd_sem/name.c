#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void append(char str1[],char str2[])
{
	int i=0,j=0,k=0;
	int n1=strlen(str1);
	int n2=strlen(str2);
	int n3=n1+n2;
	char temp[n3];
     for(i=0;i<n3;i++)
     {
     	if(i<n1)
     	{
     		temp[i]=str1[j];
     		j++;
		 }
		 else
		 {
		 	temp[i]=str2[k];
		 	k++;
		 }
		 printf("%c",temp[i]);
	}
}

char *function(char *n)
{
	char *s1="hello ";
	strcat(s1,n);
	 return s1;
	
	}
void main()
{
	char *name;
	name=(char *)malloc(20);
	printf("\n eneter the name\n");
	gets(name);
	printf("!");
    printf("%s",function(name));	
	}	
