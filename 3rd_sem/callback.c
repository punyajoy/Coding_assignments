#include<stdio.h>
#include<string.h>
 float ap(float salesamnt){
	return salesamnt*0.25;
}
 float kr(float salesamnt){
	return salesamnt*0.15;
}
float calc_tax(float salesamnt,float(*fp)(float))
{
	return (*fp)(salesamnt);
	
}
void main()
 {  float (*fp)(float salesamnt);
	int salesamnt;
	char state[29];
    scanf("%f",&salesamnt);
    printf("enter the state ap/kr:\n");
    fflush(stdin);
	gets(state);
	float tax=calc_tax(salesamnt,state);
	printf("%f",tax);
}

