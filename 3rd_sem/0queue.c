#include<stdio.h>
int queue[5];
int front=0,rear=0;
void qinsert(int n)
{
	
	rear=(rear+1)%5;
	queue[rear]=n;
	
}
void qdelete()
{
	front=(front+1)%5;
	printf("\n deleted=%d",queue[front]);
	
	
}
void qdisplay()
{
   int i;	
	for(i=front+1;i<=rear;i++)
	  printf("%d\t",queue[i]);
	
	
}
void main()
{
	int f=1,r=0;
	int element,ch;
    scanf("\n%d",&ch);
    
	while(ch!=4)
	{
	scanf("\n%d",&ch);
	switch(ch)
	{
		case 1:
     	scanf("%d",&element);
   	    qinsert(element);
		break;		
		case 2:
		qdelete();
		break;
		case 3:
		qdisplay();
		break;	
		case 4:
		break;
		default:
		printf("Wrong option");	
		}
	}
	
}

