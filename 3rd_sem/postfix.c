#include<stdio.h>
#include<string.h>
char stack[50];
int top=0;
float stack1[50];
int top1=0;

void push(char val)
{
	stack[++top]=val;
			
}
void pushint(float val)
{
	stack1[++top1]=val;
			
}

char pop()
{
	return (stack[top--]);
	    	
}
float popint()
{
	return (stack1[top1--]);
	    	
}
void display1()
{
	int i;
	printf("\n");
	for(i=0;i<top1;i++)
	  printf("%f\t",stack1[i]);
	
}
void display()
{
	int i;
	printf("\n");
	for(i=0;i<top;i++)
	  printf("%c\t",stack[i]);
	
}
int priority(char ch)
{
	int prior;
	if(ch=='@')prior=1;
	else if(ch==')'||ch=='(')prior=1;
	else if(ch=='+'||ch=='-')prior=2;
	else if(ch=='*'||ch=='/'||ch=='%')prior=3;
	return prior;
}

float evaluate(char string[])
{
   int i,n;
   float p,value,t,op1,op2;
   char ch;
   n=strlen(string);
   popint();
   for(i=0;i<n;i++)
   {
   	
   	ch=string[i];
   	if(isdigit(ch))
   	{t=(float)ch-48.00;
   	printf("\n %f",t);
   	 pushint(t);
   	 
   	 
    }
    else 
    {
    	op1=popint();
    	op2=popint();
    	switch(ch)
    	{
    		case '+':
    			value=op1+op2;
    			break;
    		case '-':
    			value=op1-op2;
    			break;
    		case '*':
    			value=op1*op2;
    			break;
    		case '/':	
    		    value=op1/op2;
    		    break;
    		case '%':
    			value=(float)((int)op1/(int)op2);		
    	}
    	printf("\n%f",value);
    	pushint(value);
         }
    
   	}
   	
	p=popint();
    return p;   	
  }


void main()
{
	char infix[100],postfix[100];
	int i,n,j=0;
	char ch,m;
		
	printf("give your expression:\n");
	scanf("%[^\n]",infix);
	n=strlen(infix);
	push('@');
	for(i=0;i<n;i++)
	{
		ch=infix[i];
	if(ch>47&&ch<58)
		{
		postfix[j++]=ch;
		
	    }
    else if(ch==')'||ch=='('||ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='%')
		{
		switch(ch)
		{
		case '(':
		push('(');
		break;
		case ')':
		while(stack[top]!='(')
		     postfix[j++]=pop();
		     pop();
			break;
		case '+':
		case '-':
           while(priority(stack[top])>2)
		    postfix[j++]=pop();			
			push(ch);
			break;
		case '/':
     	case '*':
		case '%':
		   push(ch);
		   
	     }
  		}
		else
		{
			printf("not valid");
			break;
		}
		
	}
	    while(stack[top]!='@')
		     postfix[j++]=pop();
		
		display();
		printf("%s",postfix);
	    float r =evaluate(postfix);	
		printf("%f",r);
	}
		

