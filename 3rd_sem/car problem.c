#include<stdio.h>
# define MAX 50
struct queue{
     int cars[10][10];
	 int front,rear;
 };
void main()
{
	struct queue *p;
	p->rear=7;
	printf("%d", p->rear);
	
}

