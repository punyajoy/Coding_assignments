#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node{
  int data;
  struct node *next;
}*head1,*temp,*prev;
void createlist()
{
 head1=(struct node* )malloc(sizeof(struct node));
 head1->data=0;
 head1->next=NULL;
 temp=(struct node* )malloc(sizeof(struct node));
 temp->data=0;
 temp->next=NULL;
 prev=(struct node* )malloc(sizeof(struct node));
 prev->data=0;
 prev->next=NULL;

}

void insertend(int code)
{
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=code;
    newnode->next=NULL;
	if(head1->next==NULL)
	{
	
	head1->next=newnode;
    }
	else
	{
	temp=head1->next;
    }
	while(temp->next!=NULL)
	{
	 temp=temp->next;
    }
	temp->next=newnode;
    	}
    head1->data++;
}
void makecircular()
{
	temp=head1->next;
	while(temp->next!=NULL)
	{
	 temp=temp->next;
    }
	temp->next=head1->next;
    
}

void display()
{
	struct node *temp1;
	temp1=(struct node*)malloc(sizeof(struct node));
	int i;
	printf("\n");
	temp1=head1->next;
	for(i=0;i<head1->data;i++)
	{
		printf("   %d",temp1->data);
		temp1=temp1->next;
	}

	
}
void findone(int code,int no)
{
	struct node *temp2;
	temp2=(struct node*)malloc(sizeof(struct node));
	
	int count=0,i;
    temp2=head1->next;
    printf("\nthe head count is %d",head1->data);
	while(temp2->data!=code)
	{
			
		
		if(count>=head1->data)
		{
			printf("the code is not present");
			exit(0);
		}
		temp2=temp2->next;
		count++;
	}
	printf("\n%d cursor is on this",temp2->data);
	
	while(head1->data!=1)
	{
		i=0;
		printf("\n%d cursor is on this",temp2->data);
		while(i<no-1)
		{
			prev=temp2;
			printf("\nprev data is %d",prev->data);
            temp2=temp2->next;
            printf("\nnext data is %d",temp2->data);
			i++;
		}
		display();
	  	prev->next=temp2->next;
	  	free(temp2);
	  	head1->data=head1->data-1;
	  	display();
	  	printf("\nllinkconnected data is %d",prev->next->data);
	  	temp2=prev->next;
	  	display();
	}
	
	
}

void main()
{
	
   int i,n,code;
   createlist();
   do{
   	printf("\ngive the codes of the soilder(give zero to stop)");
   	scanf("\n%d",&code);
   	if(code!=0)
   	{
  	insertend(code);
    }
   }while(code!=0);
   makecircular();
   display();
   findone(23,3);
      
}


