#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
struct node{
  int data;
  char name[20];
  struct node *next;
}*head1,*temp,*prev;


int random(n)
{
	srand((unsigned)time(NULL));
	int i;
	i=rand()%n+1;
	return i;
		
}
void insertend(int n)
{
 int i;
 char name[20];
 struct node *newnode; 
 head1->next=temp;
 head1->data=n;
 for(i=0;i<n;i++)
 {
 
  if(i==0)
  {
  printf("give the name of the soilder:-");
  scanf("%s",&temp->name);  
  temp->data=i+1;
  newnode=(struct node* )malloc(sizeof(struct node));
  temp->next=newnode;
    }
  else
  {
  printf("give the name of the soilder:-");
  scanf("%s",&newnode->name);  
  newnode->data=i+1;
  temp=newnode;
  newnode=(struct node* )malloc(sizeof(struct node));
  if(i==n-1)
  temp->next=head1->next;
  else	
  temp->next=newnode;
  }
  
  }
 	
 	
}

void search(int n)
{
	temp=head1->next;
	if(n>head1->data)
	 {
	 printf("\ndata not available");	
	 exit(0);
     }
	while(temp->data!=n-1)
	{
		
		temp=temp->next;
		
	}
	printf("\nthis person is selected:%s",temp->name);
	
	
}
void keepone(int h,int g)
{
	int count;
    search(h);
    printf("\nnumber of soilders to be skipped= %d",g);
    while(head1->data!=2)
	{
	for(count=0;count<g-1;count++)
	{
	  prev=temp;	
      temp=temp->next;
	}
	printf("\nsoilder eliminated %s",temp->name);
	prev->next=temp->next;
	temp=prev->next;
	head1->data=head1->data-1;
	}
    for(count=0;count<g-1;count++)
	{
	  prev=temp;	
      temp=temp->next;
	}
	printf("\nsoilder eliminated %s",temp->name);
	head1->next=prev;

 
}

void main()
{
 int n,t,r;
 printf("give the number of soilders?");
 scanf("%d",&n);
 head1=(struct node* )malloc(sizeof(struct node));
 head1->data=0;
 head1->next=NULL;
 temp=(struct node* )malloc(sizeof(struct node));
 temp->next=NULL;
 prev=(struct node* )malloc(sizeof(struct node));
 prev->next=NULL;	
 insertend(n);
 t=random(n);
 r=random(n)+1;
 printf("%d %d",t,r);
 keepone(t,r);
 printf("\nthe soilder to escape with the horse :%s",head1->next->name);
  }
