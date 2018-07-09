#include<stdio.h>
#include<stdlib.h>
struct report{
	int region;
	int id;
	int procode;
	int quantity;
	
};


void main()
{
	int i;
    struct report r1;
	FILE *fp1,*fp2;
	float cost;
	char product[5][100];
    printf("Enter product \n");
    for (i = 0; i < 5 ;i++)  
    {scanf("%100s", product[i]);
	printf(" this product has product id %d\n", i+1);} 
	fp1=fopen("report.txt","wb");
	fp2=fopen("rate.txt","w");
	if(fp1==NULL || fp2==NULL)
	{
		printf(" please try again, file not found");
		exit(0);
	}
	printf("give zero as region to stop taking input\n");
	for(;;)
	{
		printf("region:");
		scanf("%d",&r1.region);
		
		if (r1.region==0)
		{
			break;
		}
		printf(" give the id of the individual:\n");
        scanf("%d",&r1.id);
        printf("give the product code according to the following table: \n");
        for(i=0;i<5;i++)
        {
        printf("product code of %s is %d\n", product[i], i+1);	
        	
		}
		scanf("%d",&r1.procode);
		printf(" give no of items of that type sold:");
		scanf("%d",&r1.quantity);
		fwrite(&r1,sizeof(r1),1,fp1);		
				
	}
	printf("your dat file is created");
	int recsize=sizeof(r1);
	fseek(fp1,0,SEEK_END);
	long int filesize=ftell(fp1);
	float recordno=filesize/(float)recsize;
	printf("\n%ld",filesize);
	printf("\n%d",recsize);
	printf("\nnno of record=%f",recordno);
	fclose(fp1);
	for(i=0;i<5;i++)
    {printf("give rate of %s:\n",product[i]);	
	scanf("%f", &cost);
	fprintf(fp2,"%f\n",cost);
 }
	
	fclose(fp2);	
	
	
	
	
}
