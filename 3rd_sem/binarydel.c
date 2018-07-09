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
	FILE *fp,*fp1;
	int account,position,recno;
	fp=fopen("bank.txt","rb");
	fp1=fopen("temp.dat","wb");
	scanf("%d",&account);
	fread(&cust,sizeof(cust),1,fp);
	while(!feof(fp))
	{
	
   if(cust.accno!=account)
	fwrite(&cust,sizeof(cust),1,fp1);
		fread(&cust,sizeof(cust),1,fp);
}
	fclose(fp);
	fclose(fp1);
	remove("bank.txt");
	rename("temp.dat","bank.txt");
	printf("one deleted");
	
}

