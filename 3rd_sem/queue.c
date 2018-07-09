#include<stdio.h>
int queue[100];
int f,r;
void qinsert(int n)
{
	++r;
	queue[r]=n;
	
}
void qdelete()
{
	printf("\n deleted=%d",queue[f]);
	++f;
	
}
void qdisplay()
{
   int i;	
	for(i=f;i<=r;i++)
	  printf("%d\t",queue[i]);
	
	
}
void main()
{
	int f=1,r=0;
	int element,ch;
	scanf("%d",&element);
    scanf("\n%d",&ch);
    
	while(ch!=4)
	{
	scanf("\n%d",&ch);
	switch(ch)
	{
		case 1:
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

