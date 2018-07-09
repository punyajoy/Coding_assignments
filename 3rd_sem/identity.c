#include<stdio.h>
void main()
{
	int id;
	char sex;
	char name[20];
	printf("\nEnter the id: ");
	scanf("%d",&id);
	fflush(stdin);
	printf("\n Enter the sex: ");
	sex=getchar();
	fflush(stdin);
	printf("\n Enter name: ");
	scanf("%[^\n]",name);
	printf("\nId =%d",id);
	printf("\nSex=%c",sex);
	printf("\nName=%s",name);
}
