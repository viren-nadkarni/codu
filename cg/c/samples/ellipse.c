#include<conio.h>
#include<graphics.h>
#include<math.h>
#include<iostream.h>

void elli(float xc,float yc,float rx,float ry)
{
float p,px,py,x,y;
float ry2,rx2,tworx2,twory2;

putpixel(xc+x,yc+y,1);
putpixel(xc-x,yc+y,1);
putpixel(xc+x,yc-y,1);
putpixel(xc-x,yc-y,1);

ry2=ry*ry;
rx2=rx*rx;
twory2=2*ry2;
tworx2=2*rx2;

//region 1
x=0;
y=ry;

putpixel(xc+x,yc+y,1);
putpixel(xc-x,yc+y,1);
putpixel(xc+x,yc-y,1);
putpixel(xc-x,yc-y,1);

p=(ry2-rx2*ry+(0.25*rx2));
px=0;
py=tworx2*y;

while (px<py)
{
x=x+1;
px=px+twory2;

if(p>=0)
{
y=y-1;
py=py-tworx2;
}

if(p<0)
p=p+ry2+px;
else
p=p+ry2+px-py;

putpixel(xc+x,yc+y,1);
putpixel(xc-x,yc+y,1);
putpixel(xc+x,yc-y,1);
putpixel(xc-x,yc-y,1);
}

//region2
p=(ry2*(x+0.5)*(x+0.5)+rx2*(y-1)*(y-1)-rx2*ry2);

while(y>0)
{
y=y-1;
py=py-tworx2;

if(p<=0)
{
x=x+1;
px+px+twory2;
}

if(p>0)
p=p+rx2-py;
else
p=p+rx2-py+px;

putpixel(xc+x,yc+y,1);
putpixel(xc-x,yc+y,1);
putpixel(xc+x,yc-y,1);
putpixel(xc-x,yc-y,1);
}
}

int main()
{
int gd=DETECT,gm;
initgraph(&gd,&gm,"..\\bgi");

cleardevice();

elli(250,200,150,150);
while(!kbhit())
delay(100);

return 0;
}