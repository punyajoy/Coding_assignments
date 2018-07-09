#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void main(int argc,char *argv[])
{
   char ch;
   int cc,wc,lc,flag;
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
	{
		if (ch!=' ')
		{
			cc++;
			flag=0;
		}
		if (ch==' '&&flag==0)
		{
			wc++;
			flag=1;
		}
		if(ch='\n')lc++;
	}
	printf("%d %d %d",cc-lc,wc+lc,lc);
	fclose(fp);
}
