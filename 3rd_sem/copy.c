#include<stdio.h>
int n,l1,l2,i=0,j=0;
static char str[50];
static char sub[50];
static char temp[50];
void copystr()
{
	
	for(i=0; i<n;i++)
	{
		temp[j++]=str[i];
		
	}
	
}
void copysub()
{
		for(i=0; i<l2;i++)
		temp[j++]=sub[i];
	
}
void copystr1()
{
	for(i=n;i<l1;i++)
	 temp[j++] =str[i];
	
}
void copytemp()
{
	for(i=0;i<l1+l2;i++)
	str[i]=temp[i];
}
void main()
{
	printf("Enter the string:\n");
	gets(str);
	printf("Enter the sub string: \n");n
	gets(sub);
	printf("Enter the position: ");
	scanf("%d",&n);
	n--;
	while(str[i]!='\0')
	   i++;
	   l1=i;	
	while(sub[j]!='\0')	
	   j++;
	   l2=j;
	i=0;
	j=0;
	copystr();
	copysub();
	copystr1();
	copytemp();
	printf("\n Now thwe main is:%s",str);
	
}
