#include<graphics.h>
#include<conio.h>
#include<stdio.h>
void main()
	{
	int gd=DETECT,p0,pk,gm,r,x1,y1,x,y;
	initgraph(&gd,&gm,"c:\\turboc3\\bgi");
	printf("Enter Radius of the circle");
	scanf("%d",&r);
	printf("Enter center of the circle");
	scanf("%d%d",&x1,&y1);
	x=0;
	y=ry;
	p0=(ry*ry)-(ry*rx*rx)+(0.25*rx*rx);
	pk=p0;
	while((2*ry*ry*x)<(2*rx*rx*y))
	{
		if(p0>=0)
		{
		p0=-1;
		y=y-1;
		}
		x+=1;
		putpixel(y+y1,x+x1,RED);
		putpixel(x+x1,y+y1,RED);
		putpixel(x+x1,-y+y1,RED);
		putpixel(y+y1,-x+x1,RED);
		putpixel(-y+y1,-x+x1,RED);
		putpixel(-x+x1,-y+y1,RED);
		putpixel(-x+x1,y+y1,RED);
		putpixel(-y+y1,x+x1,RED);
		if(pk<0)
		{
		pk=pk+(ry*ry)+(2*ry*ry*x);
		}
		else
		{
		pk=pk+(ry*ry)+(2*x*ry*ry)-(2*y*rx*rx);
		y-=1;
		}
		delay(10);
	}
	getch();
	closegraph();
	}