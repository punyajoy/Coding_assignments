#include<stdio.h>
#include<string.h>
#define MAX 50

char stack[MAX];
int top=0;

void push(char val)
{
	if(top<MAX)
	{
		stack[top] =val;
		top++;
	}
	else
	{
		printf("Stack is full");
	}
	
}
int pop()
{
	int val;
	if(top>0)
	{
	    top--;
		val =stack[top];
	    return val;
	}
	else
	{
		printf("\nStack is empty");
		return -1;
	}
	
}
void display()
{
	int i;
	for(i=0;i<top;i++)
	  printf("%c\t",stack[i]);
	
}
int empty()
{
	if(top==0)
	return 1;
	else 
	return 0;
}
void main()
{
	char ch;
	char exp[50];
	char valid='t';
	int i=0,l;
	top=0;
	printf("\n enter the exp with brackets:");
	gets(exp);
	l=strlen(exp);
	while(i<=l && valid=='t')
	{
		if(exp[i]=='(')
		{
			push(exp[i]);
		}
		if(exp[i]==')')
		{
			
			if(empty())
			valid='f';
			else
			 ch=pop();
			if(ch!='(')valid='f';
		}
		i++;
	}
	if(!empty())valid='f';
	if (valid=='f')
	   puts("Invalid expression");
	else
	   puts("valid");   
}
  	
