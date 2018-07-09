#include<stdio.h>
#include<string.h>
void main()
{
	char string[100],str[100];
	int n,n1;
	printf("\n Enter the string: ");
	gets(string);
	fflush(stdin);
	scanf("%[aeiou]",str);
	n=strlen(string);
	n1=strlen(str);
	printf("\nThis string contains %d chracter.", n);
    printf("\nThis string contains %d chracter.", n1);		
	
}
