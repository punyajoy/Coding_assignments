#include<stdio.h>
#include<string.h>
void main()
{
  char x[100] ;
  int i,j,temp=0,ctr,len,pos,m,n;
  i=0;m=0;
  j=0;
  scanf("%s",x);

  strlen(x);
  while(j<len)
  {
      ctr=0;
      for(;x[i]!=' ';i++)
          {
              ctr++;
          }
              if(ctr>temp)
                {ctr=temp;
                pos=j-ctr;}

          i++;
          j=i;

  }
  for(m=pos;x[m]!=' ';m++)
    {
        printf("%c",x[i]);
    }


}
