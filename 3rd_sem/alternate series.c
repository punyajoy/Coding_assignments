#include<stdio.h>
#include<math.h>
 void main()
 {
   int i,s,n,p;
printf( "give the number of terms: ");
scanf("%d",&n);
s=0;
for(i=1; i<=n;i++)
{
    p= pow((-1),(i));
    s= s-(i*p);


}
 printf("%d",s);
 }
