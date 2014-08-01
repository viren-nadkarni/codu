#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
void bezier(int, int, int, int, int, int, int, int);
void bezier(int x0,int y0,int x1,int y1,int x2,int y2,int x3,int y3)
{
int i, j, n=4 ;
float t, tinc, ts, d1t, d1ts, c0, c1, c2, c3;
float cx[25], cy[25];
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
int x0=150, y0=100, x1=200, y1=200, x2=400, y2=300, x3=480, y3=170, k, count=0;
initwindow(700,400);
bezier(x0,y0,x1,y1,x2,y2,x3,y3);
while(!kbhit())
delay(50);
closegraph();
return EXIT_SUCCESS;
}