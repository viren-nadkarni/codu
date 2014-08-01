#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>

void circlef3plot(int, int, int, int);
void circlef3(int, int, int);

void circlef2plot(int xc,int yc,int x,int y);
void circlef2(int xc,int yc,int r);

void circlef1plot(int xc,int yc,int x,int y);
void circlef1(int xc,int yc,int r);

void circlearc(int xc,int yc,int r);
void circlearcplot(int xc,int yc,int x,int y);

void circleplot(int, int, int, int);
void cmp(int, int, int);

void circleplot1(int, int, int, int);
void cmp1(int, int, int);

void circleplot(int xc, int yc, int x, int y)
{ 
	int def=YELLOW;

	putpixel(xc+x, yc+y, def);
	putpixel(xc-x, yc+y, def);
	putpixel(xc+x, yc-y, def);
	putpixel(xc-x, yc-y, def);
	putpixel(xc+y, yc+x, def);
	putpixel(xc-y, yc+x, def);
	putpixel(xc+y, yc-x, def);
	putpixel(xc-y, yc-x, def);
}

void cmp(int xc, int yc, int r)
{
	int x=0, y=r, p=1-r;

	while(x<y)
	{
		x++;
		if(p<0)
			p+=2*x+1;
		else
		{
			y--;
			p+=2*(x-y)+1;
		}
		circleplot(xc, yc, x, y);
	}
}

void circleplot1(int xc, int yc, int x, int y)
{ 
	int def=WHITE;
	
	putpixel(xc+x, yc+y, def);
	putpixel(xc-x, yc+y, def);
/*	putpixel(xc+x, yc-y, def;
	putpixel(xc-x, yc-y, def);*/
	putpixel(xc+y, yc+x, def);
	putpixel(xc-y, yc+x, def);
	putpixel(xc+y, yc-x, def);
	putpixel(xc-y, yc-x, def);
}

void cmp1(int xc, int yc, int r)
{
	int x=0, y=r, p=1-r;

	while(x<y)
	{
		x++;
		if(p<0)
			p+=2*x+1;
		else
		{
			y--;
			p+=2*(x-y)+1;
		}
		circleplot1(xc, yc, x, y);
	}
}


void circlearcplot(int xc, int yc, int x, int y)
{
	putpixel(xc+x, yc+y, 7);
	putpixel(xc-x, yc+y, 7);
}


void circlearc(int xc, int yc, int r)
{
	int x=0, y=r, p=1-r;
	while(x < y)
	{
		x++;
		if(p<0)
			p+=2*x+1;
		else
		{
			y--;
			p+=2*(x-y)+1;
		}
		circlearcplot(xc, yc, x, y);
	}
}

void circlef1plot(int xc, int yc, int x, int y)
{
	putpixel(xc+y, yc-x, 2);
}

void circlef1(int xc, int yc, int r)
{
	int x=0, y=r, p=1-r;
	while(x<y)
	{
		x++;
		if(p<0)
			p+=2*x+1;
		else
		{
			y--;
			p+=2*(x-y)+1;
		}
		circlef1plot(xc, yc, x, y);
	}
}

void circlef2plot(int xc, int yc, int x, int y)
{
	putpixel(xc-y, yc-x, 2);
}

void circlef2(int xc, int yc, int r)
{
	int x=0, y=r, p=1-r;
	while(x<y)
	{
		x++;
		if(p<0)
			p+=2*x+1;
		else
		{
			y--;
			p+=2*(x-y)+1;
		}
		circlef2plot(xc, yc, x, y);
	}
}

void circlef3plot(int xc, int yc, int x, int y)
{
	putpixel(xc+x, yc-y, 2);
}

void circlef3(int xc, int yc, int r)
{
	int x=0, y=r, p=1-r;
	while(x<y)
	{
		x++;
		if(p<0)
			p+=2*x+1;
		else
		{
			y--;
			p+=2*(x-y)+1;
		}
		circlef3plot(xc, yc, x, y);
	}
}

int main()
{
	int i, j = 0;
	initwindow(800, 600, "flower");
	cleardevice();

	//flowers
	for(i=3; i<20; i+=3)
		cmp(210, 250, i);

	for(i=3; i<20; i+=3)
		cmp(265, 100, i);

	for(i=3; i<20; i+=3)
		cmp(190, 170, i);

	for(i=3; i<20; i+=3)
		cmp(325, 220, i);

	for(i=3; i<20; i+=3)
		cmp(340, 120, i);

	for(i=3; i<20; i+=3)
		cmp(255, 180, i);

	for(i=3; i<20; i+=3)
		cmp(395, 190, i);

	//pot
/*	for(i=0; i<=130; i+=5)			//pot decorations
		cmp(235+i, 340, 5);
*/

	cmp1(300, 340, 70);				//pot
	line(0,412,800,412);				//base

/* 
	cmp(210, 340, 20);
	cmp(390, 340, 20);
	cmp(300, 420, 10);
	cmp(280, 420, 10);
	cmp(320, 420, 10);
*/	
	circlearc(300, 240, 65);			//pot opening

	circlef1(160, 300, 156);			//branches
	circlef1(85, 290, 175);
	circlef2(470, 290, 130);
	circlef2(490, 295, 225);
	circlef2(380, 300, 100);
	circlef3(230, 370, 120);
	circlef1(230, 160, 80);

	while( !kbhit() )
		delay(50);
	
	return EXIT_SUCCESS;
}

