#include<stdio.h>
#include<string.h>
void main()
{
	char str[50],str1[50];
	printf("\nEnter the word  ");
	gets(str1);
	strcpy(str,str1);
	if(stricmp(str,strrev(str1))==0)
	{printf("it is a palindrome");
	}
	else
	{
		printf("it is not a palindrome");
	}
	
}
