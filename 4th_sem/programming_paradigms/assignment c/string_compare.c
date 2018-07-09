#include<stdio.h>
#include<string.h>
char str1[50],str2[50];
int strcompare(int n1,int n2)
{ 
    int x;
    if(n1==0&&n2==0)
       x=0;
    else if((int)str1[n1-1]>(int)str2[n2-1])
       x=1;
    else if((int)str1[n1-1]<(int)str2[n2-1])
       x=-1;
    else
        x=strcompare(n1-1,n2-1);
	return x;
	
}
void main()
{
	int n1,n2,result;
	printf("\n give the string 1");
	scanf("%s",str1);
	printf("\n give the string 2");
	scanf("%s",str2);
	n1=strlen(str1);
	n2=strlen(str2);
	result=strcompare(n1,n2);
	printf("\n the result is %d",result);
	
}
