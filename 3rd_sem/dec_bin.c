#include<stdio.h>
#include<math.h>
#include<conio.h>
void main()
  {int num,temp,sum=0,ctr=0;
    printf("\n Enter the number in decimal: ");
    scanf("%d",&num);
    while(num>0)
    { temp=num%2;
      sum=sum+(pow(10,ctr))*temp;
      num/=2;ctr++;
      }
    printf("\n THe number in binary is %d",sum);
    getch();
}
