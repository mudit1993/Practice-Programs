#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<graphics.h>
int main()
{
int gd=0,gm,x=86,y=286,i,j;
initgraph(&gd,&gm,"C:\\turboc3\\bgi");
while(!kbhit())
{ x=86;
y=286;
for(i=100,j=300;i<=200,j>=200;i=i+2,j=j-2)
{
clearviewport();
circle(x,y,20);
  x=x+2;
  y=y-2;
line(100,300,200,200);
line(200,200,300,300);
line(100,300,300,300);
delay(30);
}
x=214;
y=186;
for(i=200,j=200;i<=300,j<=300;i=i+2,j=j+2)
{
clearviewport();
circle(x,y,20);
  x=x+2;
  y=y+2;
line(100,300,200,200);
line(200,200,300,300);
line(100,300,300,300);
delay(30);
}
x=300;
y=320;
for(i=300;i>=100;i=i-2)
{
clearviewport();
circle(x,y,20);
x=x-2;

line(100,300,200,200);
line(200,200,300,300);
line(100,300,300,300);
delay(30);
}
}
getch();
closegraph();
return 0;
}