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
	fp=fopen("bank.txt","wb");
	for(;;)
	{
		printf("accno:");
		scanf("%d",&cust.accno);
		if (cust.accno==0)
		{
			break;
		}
        scanf("%d",&cust.id);
		scanf("%f",&cust.balance);
		fwrite(&cust,sizeof(cust),1,fp);		
	}
	printf("your dat file is created");
	int recsize=sizeof(cust);
	fseek(fp,0,SEEK_END);
	long int filesize=ftell(fp);
	float recordno=filesize/(float)recsize;
	printf("\n%ld",filesize);
	printf("\n%d",recsize);
	printf("\nnno of record=%f",recordno);
	fclose(fp);
}

