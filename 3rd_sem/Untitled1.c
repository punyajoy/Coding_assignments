#include<stdio.h>

int main()
{
  int i,c,n;
  char a= "A";
  printf("enter the number the rows of the pattern \n");
  scanf("%d",n);
  for(i=1;i<=n;i++)
    {
      for(c=1;c<=i;c++)
      { printf("%c",a);
         a++;}

         printf("\n");
    }
    return 0;
}
