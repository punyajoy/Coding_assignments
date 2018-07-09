#include<stdio.h>
#include<math.h>
void main()
 {
     int x,n,i,j;
     float f=1.0,s=0.0,m=1.0;
     printf("enter the numbers of x: ");
     scanf("%d",&x);
     printf("enter the numbers of n: ");
     scanf("%d",&n);
     for(i=1;i<n;i++)
     {
         for(j=1;j<=i;j++)
         {
             f=f*j;
         }
         m=pow(x,i);
         s=(s+(m/f));
     }
          printf("sum=%f\n",(s+1));
 }
