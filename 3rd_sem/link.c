#include<stdlib.h>
#include<string.h>

struct node {
	  int data;
	  struct node *next;
	
};

struct node *head1, *head2;

void createlist()
{
    head1->data=0;
	head2->data=0;
	head1->next=NULL;
	head2->next=NULL;          
}
void main()
{
	createlist();
}
