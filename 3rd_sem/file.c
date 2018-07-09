#include<stdio.h>


void main()
{
	int k;
   FILE *fp2;
   fp2=fopen("sort.txt","w");
   k=2;
   fprintf(fp2,"%d",k);
   fprintf(fp2,"\n");
   fprintf(fp2,"%d",k);
   fclose(fp2);
}
