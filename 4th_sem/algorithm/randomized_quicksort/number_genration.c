#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>
float randm()
{

        float i;
        i=(float)rand()/RAND_MAX;
        i=i*2-1;
        return i;
}

float Normal(float mean, float stdev)
{

        float R1;
        R1 = rand()/((float)RAND_MAX+1);
        float R2;
        R2 = rand()/((float)RAND_MAX+1);
        return mean + stdev*cos(2*3.14*R1)*sqrt(-log(R2));
}

void main()
{
        FILE *fp1,*fp2;
        float rand_int;
        int i;
        srand((unsigned)time(NULL));
        fp1=fopen("normal.txt","w");
        fp2=fopen("uniform.txt","w");
        for(i=0;i<100000;)
        {
         rand_int=Normal(0,1);
         if(rand_int>-1&&rand_int<1)
         {
          fprintf(fp1,"%f\n",rand_int);
          i++;
         }
        }
        for(i=0;i<100000;)
        {
         rand_int=randm();
          fprintf(fp2,"%f\n",rand_int);
          i++;
        }
    fclose(fp2);
    fclose(fp1);
}

