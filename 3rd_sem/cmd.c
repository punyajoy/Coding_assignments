#include<stdio.h>
void main(int argc,char *argv[],char *envp[])
{
	int i;
	for(i=0;i<argc;i++)
	printf("\n%s",argv[i]);
	for(i=0;envp[i]!=NULL;i++)
	printf("\n%s",envp[i]);
	
 } 
