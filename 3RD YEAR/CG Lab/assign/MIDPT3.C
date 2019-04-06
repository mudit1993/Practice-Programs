#include<graphics.h>
#include<conio.h>
#include<stdio.h>
void main()
	{
	int gd=DETECT,p0,pk,gm,r,x1,y1,x,y,y2,x2;
	initgraph(&gd,&gm,"c:\\turboc3\\bgi");
	printf("Enter Radius of the circle");
	scanf("%d",&r);
	printf("Enter center of the circle");
	scanf("%d%d",&x1,&y1);
	x2=x1+(2*r);
	 y2=y1+(2*r);
	x=0;
	y=r;
	p0=1-r;
	pk=p0;
	while(x<=y)
	{
		if(p0>=0)
		{
		p0=-1;
		y=y-1;
		}
		x+=1;
		putpixel(y+y1,x+x1,RED);
		putpixel(x+x1,y+y1,RED);
		putpixel(x+x1,-y+y2,RED);
		putpixel(y+y1,-x+x2,RED);
		putpixel(-y+y1,-x+x2,RED);
		putpixel(-x+x1,-y+y2,RED);
		putpixel(-x+x1,y+y1,RED);
		putpixel(-y+y1,x+x1,RED);

		if(pk<0)
		{
		pk=pk+(2*x)+1;
		}
		else
		{
		pk=pk+(2*x)+1-(2*y);
		y-=1;
		}
		delay(10);
	}
	getch();
	closegraph();
	}