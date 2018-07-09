#include<stdio.h>
#define MAX 50

int stack[MAX];
int top=0;

void push(int val)
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
	  printf("%d\t",stack[i]);
	
}
void main()
{
  int choice =0,val=0;		
   
  while(choice!=4)
  {
  	printf("\nSTACKS");
  	printf("\n-----");
  	printf("\n1.push");
  	printf("\n2.pop");
  	printf("\n3.display");
  	printf("\n4.exit");
	printf("\n your choice:");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			printf("\nEnter the element:");
			scanf("%d",&val);
			push(val);
		    break;
		case 2:
			val=pop();
			if(val != -1)
			{
				printf("\n popped element:%d",val);
			}
		    break;
		case 3:
			display();
			break;
		case 4:
		 break;
		default:
			printf("wrong choice");
			break;
	}

		
	}
	
	
	
	
	
	
	
	  }	
	
	
	
	
	
	
	
	
	

