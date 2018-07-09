#include<stdio.h>
#include<string.h>
void main()
{
	char str[100],sub[100];
	char *n;
	printf("\nEnter the main string: ");
	scanf("%[^\n]",str);
	fflush(stdin);
	printf("\nEnter the substring: ");
	scanf("%[^\n]",sub);
	n=strstr(str, sub);
	if(n== NULL)
	printf("\nsub string not found");
	else
	printf("\nsubstring found at position %d",n-str);
}
