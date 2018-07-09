#include<stdio.h>

void main()
{
    char ch;
    int n,p,r,j,k,i,m,q;
    printf("Give the number of rows= \n");
    scanf("%d",&n);
    ch= 'A';
    p= n/7;
    r=n%7;
    for(i=1;i<=p;i++)
    {
        ch='A';
        for(j=1;j<=7;j++)
        {
            for (k=1;k<=j;k++)
            {
              if(ch<='Z')
                {printf("%c",ch);
                ch++;}

            }
           printf("\n");
        }

    }
   ch='A';
    for(m=1;m<=r;m++)
    {
        for(q=1;q<=m;q++)
        {
            if(ch<='Z')
           {
            printf("%c",ch);
            ch++;
           }
        }
        printf("\n");
    }

