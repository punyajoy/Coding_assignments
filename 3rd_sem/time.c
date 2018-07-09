#include<time.h>
#include<stdio.h>

void main()
{
	clock_t t;
	t=clock();
	printf("hello");
	t=clock()-t;
	double timetaken=((double)t)/CLOCKS_PER_SEC;
	printf("%f",timetaken);
	
	
}
