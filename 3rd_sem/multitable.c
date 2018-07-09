/*display multiplication*/
#include <stdio.h>
#include <math.h>
void main()
{
	char c;
	do{
	int i ,no;
	printf("\n Which no table you want?");
	scanf("%d",&no);
	printf("\tTABLE\n");
	printf("number\t factor\t\tproduct");
	for(i=1;i<=10;++i)
	printf("\n  %d    x    %2d          %d",no,i,no*i);
    scanf("%c",c);
	}while(c=='y');
    
	
	
	
}
