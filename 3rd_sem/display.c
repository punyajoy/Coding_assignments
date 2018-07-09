#include<stdio.h>
void message()
{
	printf("grt job");
	
}
void close()
{
	
printf("all files are closed");	

}

void main()
{
	system("dir");
	system("binaryreader");
	FILE *fp;
	char ch;
	fp=fopen("myfile.txt","r");
	while((ch=getc(fp))!=EOF)
	putchar(ch);
	fclose(fp);
	printf("end of main");
	atexit(message);
	atexit(close);
	
}

