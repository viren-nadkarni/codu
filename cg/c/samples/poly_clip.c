#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <math.h>
#include <process.h>
#define TRUE 1
#define FALSE 0
typedef unsigned int outcode;
outcode CompOutCode(double x, double y);
enum { TOP = 0x1, BOTTOM = 0x2, RIGHT = 0x4, LEFT = 0x8 };
float xmin, xmax, ymin, ymax;
void clip(double x0, double y0, double x1, double y1)
{
outcode outcode0, outcode1, outcodeOut;
int accept = FALSE, done = FALSE;
outcode0 = CompOutCode(x0, y0);
outcode1 = CompOutCode(x1, y1);
do
{
if (!(outcode0 | outcode1))
{
accept = TRUE;
done = TRUE;
}
else if (outcode0 & outcode1)
done = TRUE;
else
{
double x, y;
outcodeOut = outcode0 ? outcode0 : outcode1;
if (outcodeOut & TOP)
{
x = x0 + (x1 - x0) * (ymax - y0) / (y1 - y0);
y = ymax;
}
else if (outcodeOut & BOTTOM)
{
x = x0 + (x1 - x0) * (ymin - y0) / (y1 - y0);
y = ymin;
}
else if (outcodeOut & RIGHT)
{
y = y0 + (y1 - y0) * (xmax - x0) / (x1 - x0);
x = xmax;
}
else
{
y = y0 + (y1 - y0) * (xmin - x0) / (x1 - x0);
x = xmin;
}
if (outcodeOut == outcode0)
{
x0 = x;
y0 = y;
outcode0 = CompOutCode(x0, y0);
}
else
{
x1 = x;
y1 = y;
outcode1 = CompOutCode(x1, y1);
}
}
} while (done == FALSE);
if (accept)
line(x0, y0, x1, y1);
rectangle(xmin, ymin, xmax, ymax);
}
outcode CompOutCode(double x, double y)
{
outcode code = 0;
if (y > ymax)
code |= TOP;
else if (y < ymin)
code |= BOTTOM;
if (x > xmax)
code |= RIGHT;
else if (x < xmin)
code |= LEFT;
return code;
}
int main()
{
double x1, y1, x2, y2;
int n, poly[14], i;
printf("Number of vertices: ");
scanf("%d", &n);
printf("Enter vertices:\n");
for (i = 0; i < 2 * n; i++)
scanf("%d", &poly[i]);
poly[2 * n] = poly[0];
poly[2 * n + 1] = poly[1];
printf("Window coordinates (min, max): ");
scanf("%f%f%f%f", &xmin, &ymin, &xmax, &ymax);
initwindow(640, 480);
drawpoly(n + 1, poly);
rectangle(xmin, ymin, xmax, ymax);
while( !kbhit() );
cleardevice();
for (i = 0; i < n; i++)
clip(poly[2 * i], poly[(2 * i) + 1], poly[(2 * i) + 2], poly[(2 * i) + 3]);
while( !kbhit() );
return EXIT_SUCCESS;
}