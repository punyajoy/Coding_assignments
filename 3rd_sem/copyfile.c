#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void main(int argc,char *argv[])
{
   char ch;
	FILE *fp1,*fp2;
	fp1=fopen(argv[1],"r");
	fp2=fopen(argv[2],"w");
	if(argc!=3)
	{
		printf("sorry invalid arg");
		return;
	}
	if(fp1==NULL||fp2==NULL)
	{
		printf("sorry no file found");
	}
	while((ch=getc(fp1))!=EOF)
	putc(ch,fp2);
	fclose(fp1);
	fclose(fp2);
}
