#include<stdio.h>
#include<string.h>
void main()
{
	char str[50];
	int i,n;
	printf("give the binary number:");
	gets(str); 
	n=strlen(str);
	for (i=n-1;i>=0;i--)
	{
		if(str[i]=='0')
		str[i]='1';
		else
		str[i]='0';
		
	}
	printf("1s complment=%s",str);
	
	
}
