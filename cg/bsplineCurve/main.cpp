#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>

void bspline(int, int, int, int, int, int, int, int, int, int);
void bezier(int, int, int, int, int, int, int, int);

void bspline(int x0,int y0,int x1,int y1,int x2,int y2,int x3,int y3,int k,int count)
{
	int i, j, n=4;
	float t, tinc, ts, d1t, d1ts, c0, c1, c2, c3,tc;
	float  cx[25], cy[25];
	t = 0.0; tinc =0.25;
	for(i=0; i <= n; ++i)
	{
		ts = t*t;
		tc=ts*t; 
		d1t = 1.0 - t; 
		d1ts = d1t*d1t;
		c0 = d1ts*d1t/6.0;
		c1 = tc/2-ts+.66;	 
		c2 = -tc/2.0+ts/2.0+t/2.0+.167; 
		c3 = tc/6.0;
		cx[i] = c0*x0 + c1*x1 + c2*x2 + c3*x3;
		cy[i] = c0*y0 + c1*y1 + c2*y2 + c3*y3;
		t = t + tinc; 
	}
	
	setcolor(12);
	circle(x0,y0,3); 
	circle(x1,y1,3); 
	circle(x2,y2,3); 
	circle(x3,y3,3);
	
	setcolor(14);
	line(x0,y0, x1,y1); 
	line(x1,y1, x2,y2);	 
	line(x2,y2, x3,y3);

	setcolor(k);
	for(i=0; i < n; ++i)
	{
		line(cx[i],cy[i],cx[i+1],cy[i+1]);
		delay(200);
	}
	if(count!=4)
	{
		setcolor(7);
		circle(cx[i],cy[i],3);
	}
	return;
}

void bezier(int x0,int y0,int x1,int y1,int x2,int y2,int x3,int y3)
{
	int i, j, n=4 ;
	float t, tinc, ts, d1t, d1ts, c0, c1, c2, c3;
	float  cx[25], cy[25];
	t = 0.0; tinc =0.25;
	for(i=0; i <= n; ++i)
	{
		ts = t*t; 
		d1t = 1.0 - t; 
		d1ts = d1t*d1t;
		c0 = d1ts*d1t; 
		c1 = 3.0*d1ts*t;	
		c2 = 3.0*d1t*ts;	
		c3 = ts*t;
		cx[i] = c0*x0 + c1*x1 + c2*x2 + c3*x3;
		cy[i] = c0*y0 + c1*y1 + c2*y2 + c3*y3;
		t = t + tinc; 
	}
	setcolor(12);
   
	circle(x0,y0,3); 
	circle(x1,y1,3); 
	circle(x2,y2,3); 
	circle(x3,y3,3);
	
	setcolor(14);
	line(x0,y0, x1,y1); 
	line(x1,y1, x2,y2);	 
	line(x2,y2, x3,y3);
	
	setcolor(10);
	for(i=0; i < n; ++i)
	{
		line(cx[i],cy[i],cx[i+1],cy[i+1]);
		delay(200);
	}
	return;
}

int main()
{	
	int x0=150, y0=100, x1=200, y1=200, x2=400, y2=300, x3=480, y3=170;
	int x4=300, y4=120, x5=400, y5=50, x6=600, y6=120, x7=480, y7=180, k, count=0;
	
	initwindow(700,400);
/*	
	k=11;
	count++;
	bspline(x0,y0,x1,y1,x2,y2,x3,y3,k,count);
	
	k=12;
	count++;
	bspline(x1,y1,x2,y2,x3,y3,x4,y4,k,count);
	
	k=13;
	count++;
	bspline(x2,y2,x3,y3,x4,y4,x5,y5,k,count);
	
	k=10;
	count++;
	bspline(x3,y3,x4,y4,x5,y5,x6,y6,k,count);
*/	
	bezier(x0,y0,x1,y1,x2,y2,x3,y3);
	bezier(x3,y3,x4,y4,x5,y5,x6,y6);
	
	while(!kbhit())
		delay(50);
		
	closegraph();
	
	return EXIT_SUCCESS;
}
