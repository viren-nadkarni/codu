#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void rotate( int *, int, double, int, int);
void rotate( int figure[], int vertex, double angle, int cx, int cy )
{
double x, y;
int i;
angle = -1 * (angle * 3.14/180);
double cos_a = cos(angle);
double sin_a = sin(angle);
for(i=0; i<vertex; i++)
{
x = figure[2*i] - cx;
y = figure[2*i+1] - cy;
figure[2*i] = ceil( (x * cos_a) - (y * sin_a) + cx );
figure[2*i+1] = ceil( (x * sin_a)+(y * cos_a) + cy );
}
}
int main()
{
int figure[20], vertex, i;
double angle;
int cx=0, cy=0, max_y;
initwindow(640,480,"rotation");
max_y = 640;
printf( "Number of vertex: " );
scanf( "%d", &vertex );
for(i=0; i<vertex; i++)
{
printf( "Enter vertex (x%d,y%d) : ", i , i );
scanf( "%d %d", &figure[2*i], &figure[2*i+1] );
}
figure[2*i] = figure[0];
figure[2*i+1] = figure[1];
vertex += 1;
printf( "Enter angle of rotation in degrees: ");
scanf( "%lf", &angle);
printf( "Enter the centre of rotation: ");
scanf( "%d %d", &cx, &cy);
cy = max_y - cy;
setbkcolor(WHITE);
setcolor(GREEN);
setlinestyle(SOLID_LINE, 0, 3);
drawpoly(vertex, figure);
for(i=0; i < vertex; i++)
figure[2*i+1] = max_y - figure[2*i+1];
rotate(figure,vertex,angle,cx,cy);
for(int i=0; i < vertex; i++)
figure[2*i+1] = max_y - figure[2*i+1];
setcolor(RED);
setlinestyle(SOLID_LINE, 0, 3);
drawpoly( vertex, figure );
while( !kbhit() );
return EXIT_SUCCESS;
}
Number of edges: 3