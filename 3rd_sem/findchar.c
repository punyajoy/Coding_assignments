#include<stdio.h>
#include<string.h>
void main()
{
	char str[100],ch;
	char *n;
	printf("\n Enter the string: ");
	gets(str);
	printf("\nEnter a character: ");
	ch=getchar();
	n=strchr(str,ch);
	if(n == NULL)
	printf("\nCharacter is not found");
	else
	printf("\n The first occurence is %d",n-str);
}
