#include <stdlib.h>
#include <math.h>
#include "graphics.h"
void b_line(int, int, int, int);

/*
void b_line(int xa,int xb,int ya,int yb)
{
	int dx=abs(xa-xb), dy=abs(ya-yb);
	int p=2*dy-dx;
	int twody = 2*dy, twodydx=2*(dy-dx);
	int x,y,xend;
	
	if(xa > xb)
	{
		x=xb;
		y=yb;
		xend=xa;
	}
	
	else
	{
		x=xa;
		y=ya;
		xend=xb;
	}
	putpixel(x,y,WHITE);
	while(x<xend)
	{
		x++;
		if(p<0)
			p+=twody;
		else
		{
			y++;
			p+=twodydx;
		}
		putpixel(x,y,WHITE);
	}
}
*/


///*


void b_line(int x0, int y0, int x1, int y1)
{
	int dx, dy, x, y;
	float err = 0, d_err = 0, tmp;

	dx = x1 - x0;
	dy = y1 - y0;

	tmp = dy / dx;
	
	d_err = fabs(tmp);
	
	y = y0;
	
	for(x = x0; x <= x1; x++)
	{
		putpixel(x, y, WHITE);
		err = err + d_err;
		if(err >= 0.5)
		{
			y = y + 1;
			err = err - 1.0;
		}
	}
}
//*/

int main()
{
	initwindow(640, 360, "DDA - railway");
	
	b_line(12,12,300,300);
	
	while ( !kbhit() )
		delay(100);

	return EXIT_SUCCESS;
}
