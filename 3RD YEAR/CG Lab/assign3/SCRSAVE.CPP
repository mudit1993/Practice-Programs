#include<graphics.h>
#include<conio.h>
void main()
	{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"c:\\turboc3\\bgi");
	putpixel(100,100,RED);
	line(50,200,100,300);
	getch();
	closegraph();
	}