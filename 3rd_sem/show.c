#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void main(int argc,char *argv[])
{
   char ch;
	FILE *fp;
	fp=fopen(argv[1],"r");
	if(argc!=2)
	{
		printf("sorry invalid arg");
		return;
	}
	if(fp==NULL)
	{
		printf("sorry no file found");
	}
	while((ch=getc(fp))!=EOF)
	putchar(ch);
	fclose(fp);
}