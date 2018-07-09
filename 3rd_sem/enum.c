#include<stdio.h>
void main()
{
	enum months{Jan,Feb,Mar,Apr,May,Jun};
	char *name[]={"January","February","March","April","May","June"};
	int days[] ={31,28,31,30,31,30};
	enum months m;
	for(m=Jan;m<=Jun;m++)
	printf("%s %d\n",name[m],days[m]);
	
}
