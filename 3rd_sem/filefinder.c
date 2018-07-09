#include<stdio.h>
#include<dir.h>
void main()
{
	struct ffblk file;
	int rec_code;
	rec_code=findfirst("*.*",&file,0);
	while(rec_code==0)
	{
		printf("\n%s",file.ff_name);
		rec_code=findnext(&file);
    }
	
	
	
}
