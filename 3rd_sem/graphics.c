#include<stdio.h>
#include<graphics.h>
void main()
{
	int gd,gm;
	gd=DETECT;
	initgraph(&gd,&gm,"C:\\TC\\BGI");
	getch();
	closegraph();
	
	
}
