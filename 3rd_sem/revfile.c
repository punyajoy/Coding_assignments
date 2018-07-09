#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
void main(int argc,char *argv[])
{
   char ch,arr[50];
   int n;
   n=atoi(argv[3]);
   
	FILE *fp1,*fp2;
	fp1=fopen(argv[1],"r");
	fp2=fopen(argv[2],"w");
	if(argc!=4)
	{
		printf("sorry invalid arg");
		return;
	}
	if(fp1==NULL||fp2==NULL)
	{
		printf("sorry no file found");
	}
	int i=0;
	while((ch=getc(fp1))!=EOF)
	{
		arr[i++]=ch;
		if(i>=n)break;
	}
	i=n-1;
	rewind(fp1);
	while((ch=getc(fp1))!=EOF)
	{
		if(i>0)
		putc(arr[i--],fp2);
		else
		putc(ch,fp2);
	}
	printf("new file created");
	fclose(fp1);
	fclose(fp2);
}
