#include<stdio.h>
#include<string.h>
void convert (char str[], int pos)
{ int i;
  for(i=pos-1;i>=0;i--)
  {
  	if(str[i]=='0')str[i]='1';
  	else
  	str[i]=='0';
  }
  	printf("2s complement= %s",str);
  	
  }
  
void main()
{
	char str[50];
	int i,n,pos;
	printf("give the binary number:");
	gets(str); 
	n=strlen(str);
	for (i=n-1;i>=0;i--)
	{
		if(str[i]=='1')
		{
		 pos=i;
		 break;	
		}
	}
    convert(str, pos);
	
}
