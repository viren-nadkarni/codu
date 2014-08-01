#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void scale( int *, int, int, int, int, int);
void scale( int poly[], int vertex, int dx, int dy, int cx, int cy)
{
int i;
for(i=0; i < vertex; i++)
{
poly[2*i] = (poly[2*i] - cx) * dx + cx;
poly[2*i+1] = (poly[2*i+1] - cy) * dy + cy;
}
}
int main()
{
int poly[20], vertex, i, dx, dy, cx=0, cy=0;
printf( "Number of vertex: " );
scanf( "%d", &vertex );
for( i=0; i<vertex; i++)
{
printf( "Enter vertex (x%d,y%d) : ", i , i );
scanf( "%d %d", &poly[2*i], &poly[2*i+1] );
}
poly[2*i] = poly[0];
poly[2*i+1] = poly[1];
vertex += 1;
printf( "Enter dx: ");
scanf( "%d", &dx);
printf( "Enter dy: ");
scanf( "%d", &dy);
printf( "Enter the centre of scaling: ");
scanf( "%d %d", &cx, &cy);
setbkcolor(WHITE);
setcolor(GREEN);
setlinestyle(SOLID_LINE, 0, 3);
drawpoly( vertex, poly );
scale(poly,vertex,dx,dy,cx,cy);
setcolor(RED);
setlinestyle(SOLID_LINE, 0, 3);
drawpoly( vertex, poly );
setcolor(BLACK);
circle(cx, cy, 5);
while( !kbhit() );
return EXIT_SUCCESS;
}