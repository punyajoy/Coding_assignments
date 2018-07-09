#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>

void main()
{
	FILE *fp1,*fp2;
	float rand_int_uniform[1000],rand_int_normal[1000];
	int i; 
	srand((unsigned)time(NULL));
	fp1=fopen("normal.txt","r");
	fp2=fopen("uniform.txt","r");
	for(i=0;i<100;)
	{	 
	  fscanf(fp1,"%f\n",rand_int_normal[i]);
	  i++;
     
    }
    for(i=0;i<100;)
	{	 
	   fscanf(fp2,"%f\n",rand_int_uniform[i]);
	   i++;
      
    }
    fclose(fp2);
    fclose(fp1);
}

