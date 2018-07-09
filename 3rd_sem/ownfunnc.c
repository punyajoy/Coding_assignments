#include<stdio.h>
#include<string.h>
void copystring(char str1[],char str2[])
{
	int i=0;
	while(str1[i] !='\0')
	{
	str2[i]=str1[i];
	i++;
   }
}
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

void reverse(char str1[])
{    
    int n=strlen(str1); 
	char temp[n];
	int i=0;
	while(str1[i] !='\0')
	{
		temp[i]=str1[n-1-i];
		i++;
	}
	copystring(temp,str1);	
}
void main()
{
	char s1[50],s2[50];
	gets(s1);
    gets(s2);
    strcat(s1,s2);
	puts(s1);
		
}
