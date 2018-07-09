#include<stdio.h>
#include<string.h>
int convert(char ch)
{
	int x=0;
	if (ch=='I')x=1;
	if (ch=='V')x=5;
	if (ch=='L')x=50;
	if (ch=='C')x=100;
	if (ch=='D')x=500;
	if (ch=='M')x=1000;
	if (ch=='X')x=10;
    return x;
}

void main()
{
	char str[50];
	int num[50];
	int n,i=0,j=0,k,tot=0;
	printf("enter the roman number:");
	gets(str);
	strcpy(str,strupr(str));
	n=strlen(str);
	for(i=0;i<n;i++)
		{
		num[i]=convert(str[i]);}
	
		k=n-1;
		tot =num[k];
		for(i=k ;i>=0;i--)
		{
			j=i-1;
			if(j<0) num[j]=0;
			if(num[j]>=num[i])tot=tot+num[j];
			else tot=tot-num[j];
		}
		printf("Decimal integer=%d",tot);
		
		
}

