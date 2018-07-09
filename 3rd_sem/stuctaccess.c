#include<stdio.h>
#include<string.h>
#include<conio.h>
void main()
{
	struct ebill{
		int mno;
		char name[20];
		int previous;
		int units;
		float charge;
	};
    struct ebill eb;
	struct ebill *ptr;	
    	(*ptr).mno=1006;
		strcpy((*ptr).name,"pola");
		(*ptr).previous=123;
		(*ptr).units=90;
		(*ptr).charge=78.00;
		eb.mno=1009;
		strcpy(eb.name,"therrir");
		eb.previous= 995;
		eb.units=8585;
		eb.charge=757;
		printf("\n%d",eb.mno);
		printf("\n%s",eb.name);
		printf("\n%d",eb.previous);
		printf("\n%d",eb.charge);
		printf("\n%d",eb.units); 
        printf("\n");
        getch();
		}
