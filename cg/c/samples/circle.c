#include<graphics.h>
#include<iostream.h>

void circlePlotPoints(int,int,int,int,int);
void midcircle(int,int,int,int);

void midcircle(int xc,int yc,int r,int cr)
{
	int x = 0, y = r, p = 1 - r;
	circlePlotPoints(xc,yc,x,y,cr);
	while( x < y )
	{
		x++;
		if(p<0) 
			p+=2*x+1;
		else
		{
			y--;
			p+=2*(x-y)+1;
		}
		circlePlotPoints(xc,yc,x,y,cr);
	}
}

void circlePlotPoints(int xc,int yc,int x,int y,int co)
{
	putpixel(xc+x,yc+y,co);
	putpixel(xc-x,yc+y,co);
	putpixel(xc+x,yc-y,co);
	putpixel(xc-x,yc-y,co);
	putpixel(xc+y,yc+x,co);
	putpixel(xc-y,yc+x,co);
	putpixel(xc+y,yc-x,co);
	putpixel(xc-y,yc-x,co);
}

int main()
{
	int gd,gm,r=5,c=15;
	detectgraph(&gd,&gm);
	initgraph(&gd,&gm," ");
	while(!kbhit())
	{
		setcolor(c++);
		midcircle(300,240,r,c);
		r=r+4;
		if(r>200)
			r=5;
	}
	closegraph();

	while(!kbhit())
	delay(100);

	return 0;
}
