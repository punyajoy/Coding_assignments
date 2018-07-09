#include<stdio.h>
#include<conio.h>
void main()
{
   char name[20];
   printf("your good name: ");
	scanf ("%[^\n]",name);
	printf("hello %s",name);
	printf("\n Happy birthday to you!");
	getch();
	

}
