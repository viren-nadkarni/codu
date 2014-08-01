#include <stdlib.h>
#include <graphics.h>
#define ROUND(a) ((int)(a+0.5))
void ellipseplotpoint(int, int, int, int);
void ellipsemidpoint(int, int, int, int);
void ellipsemidpoint(int xc, int yc, int rx, int ry)
{
int rx2=rx*rx, ry2=ry*ry;
int tworx2=2*rx2, twory2=2*ry2;
int p,x=0,y=ry;
int px=0,py=tworx2*y;
ellipseplotpoint(xc,yc,x,y);
p=ROUND( ry2-(rx2*ry)+(0.25*rx2));
while(px<py)
{
x++;
px+=twory2;
if(p<0)
p+=ry2+px;
else
{
y--;
py-=twory2;
p+=ry2+px-py;
}
ellipseplotpoint(xc,yc,x,y);
}
p= ROUND( ry2*(x+0.5)*(x+0.5)+rx2*(y-1)*(y-1)-rx2*ry2 );
while(y>0)
{
y--;
py-=tworx2;
if(p>0)
p+=rx2-py;
else
{
x++;
px+=twory2;
p+=rx2-py+px;
}
ellipseplotpoint(xc,yc,x,y);
}
}
void ellipseplotpoint(int xc, int yc, int x, int y)
{
putpixel(xc+x, yc+y, WHITE);
putpixel(xc-x, yc+y, WHITE);
putpixel(xc+x, yc-y, WHITE);
putpixel(xc-x, yc-y, WHITE);
}
int main(int argc, char * argv[])
{
initwindow(400,400,"window");
ellipsemidpoint(100,100,80,50);
ellipsemidpoint(100,80,40,20);
//tyres
ellipsemidpoint(25,130,30,30);
ellipsemidpoint(175,130,30,30);
while(!kbhit())
delay(50);
return EXIT_SUCCESS;
}