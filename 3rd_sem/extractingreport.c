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
    float employee[4][6];
	float cost[5];
	int p;
	struct report r2;
	FILE *fp1,*fp2;
    fp1=fopen("report.txt","rb");
	fp2=fopen("rate.txt","r");
	if(fp1==NULL || fp2==NULL)
	{
		printf(" please try again, file not found");
		exit(0);
	}
	int position=0,i=0;
	for(i=0;i<5;i++)
	{
		fscanf(fp2,"%f\n",&cost[i]);
	}
	i=0;
	while(!feof(fp1))
	{
	position=(i)*sizeof(r2);
	fseek(fp1,position,SEEK_SET);
	fread(&r2,sizeof(r2),1,fp1);
	if(!feof(fp1))
	fprintf(stdout,"\n%d %d %d %d",r2.region,r2.id,r2.procode,r2.quantity);
    employee[r2.region-1][r2.id-1]+=r2.quantity*cost[r2.procode-1];    
	i++;
    }
	fclose(fp1);
	fclose(fp2);
	printf("\ngive the region whose report is needed:\n");
	printf("if want to stop seeing report give 5\n");
	scanf("%d",&p);
	while(p<5)
	{
		printf("            ABC COMPANY\n");
		printf("Employee                   cost of total sold items\n");
		for(i=0;i<6;i++)
		{
			printf("employee %d                        %f\n",i+1,employee[p-1][i]);
			
		}
	    scanf("%d",&p);	
	   		
	}
	
}
