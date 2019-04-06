#include<graphics.h>
#include<conio.h>
#include<stdio.h>
void main()
	{
	float p0,pk,rx,ry,l,r,x1,y1,x,y;
	int gm,gd=0;
	initgraph(&gd,&gm,"c:\\turboc3\\bgi");
	printf("Enter Rx,Ry of the ellipse");
	scanf("%f%f",&rx,&ry);
	printf("Enter center of the ellipse");
	scanf("%f%f",&x1,&y1);
	x=0;
	y=ry;
	p0=(ry*ry)-(ry*rx*rx)+(0.25*rx*rx);
	pk=p0;
	l=2*ry*ry*x;
	r=2*rx*rx*y;
	while(l<=r)
	{
		if(p0>=0)
		{
		p0=-1;
		y=y-1;
		}
		x+=1;
		putpixel(x+x1,y+y1,RED);
		putpixel(-x+x1,y+y1,RED);
		putpixel(-x+x1,-y+y1,RED);
		putpixel(x+x1,-y+y1,RED);
		if(pk<0)
		{
		pk=pk+(ry*ry)+(2*ry*ry*x);
		}
		else
		{
		y-=1;
		pk=pk+(ry*ry)+(2*x*ry*ry)-(2*y*rx*rx);
		}
		l=2*ry*ry*x;
		r=2*rx*rx*y;
		delay(50);
	}
	p0=((x+.5)*(x+0.5)*ry*ry)+((y-1)*(y-1)*rx*rx)-(rx*rx*ry*ry);
	pk=p0;
	while(y!=0)
	{
	if(p0<0)
	{
	x+=1;
	p0=1;
	}
	y-=1;
		putpixel(x+x1,y+y1,RED);
		putpixel(-x+x1,y+y1,RED);
		putpixel(-x+x1,-y+y1,RED);
		putpixel(x+x1,-y+y1,RED);
		if(pk<0)
		{
		x+=1;
		pk=pk+(rx*rx)-(2*rx*rx*y)+(2*ry*ry*x);
		}
		else
		{
		pk=pk+(rx*rx)-(2*rx*rx*y);
		}

    delay(50);
	}


	getch();
	closegraph();
	}