#include<stdio.h>
struct customer
{
	int accno;
	int id;
	float balance;
};
void main()
{
	
	struct customer cust;
	FILE *fp;
	int account,position,recno;
	fp=fopen("bank.txt","rb");
	scanf("%d",&account);
	recno=account-1000;
	position=(recno-1)*(sizeof(cust));
	printf("%ld",ftell(fp));
	fseek(fp,position,SEEK_SET);
		fread(&cust,sizeof(cust),1,fp);
		fprintf(stdout,"\n%d %d %f",cust.accno,cust.id,cust.balance);		
		printf("your dat file is created");
	fclose(fp);
}

