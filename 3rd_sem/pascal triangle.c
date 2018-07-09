#include <stdio.h>

long factorial(int)
int main()
{
   int i, n, j,k,a,c;

   printf("Enter the number of rows you wish to see in pascal triangle\n");
   scanf("%d",&n);

   for (i = 1; i <= n; i++)
   {
      for (j=1; j <= (n - i); j++)
         printf(" ");

      for (k = 1 ; k <= i; k++)
         printf("%d ",factorial(i-1)/(factorial(k-1)*factorial(i-k)));

      printf("\n");
   }

   return 0;
}

long factorial(int y)
{
   if (y==0&&y==1)
     { return 1;}
   else
   {
       return(y*factorial(y-1));
   }
}

