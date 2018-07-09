#include<stdio.h>
int length(char str[])
{
	int i=0;
	while(str[i]!='\0')
	{
		i++;
	}
	return i;
}
void main()
{
	char str[80];
	int n;
	gets(str);
	n=length(str);
	printf("%d",n);
}




