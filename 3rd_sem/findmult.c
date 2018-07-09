#include<stdio.h>
#include<string.h>
void main()
{
  char str[50],sub[50];
  int n1,n2,i,j,t,flag=0,location=0,count=0;
  gets(str);
  fflush(stdin);
  gets(sub);
  n1=strlen(str);
  n2=strlen(sub);
  
  for(i=0;i<n1;i++)
      {
	 t=i;
	 flag=0;
	  for(j=0;j<n2;j++)
	  {    
	     if(str[t]!=sub[j])
		 {
		 flag=1;
		 }
		 t++;
	     	 
	  
      }
      if(flag==0)
      {
      	printf("%d\n",i+1);
      	count++;
      	
	  }
      
}
  	printf("no of times %s appears is %d",sub,count);
}
