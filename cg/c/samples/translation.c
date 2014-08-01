#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void translate( int *, int, int, int);
void translate( int poly[], int vertex, int dx, int dy )
{
int i;
for(i=0; i<vertex; i++)
{
poly[2*i] += dx;
poly[2*i+1] += dy;
}
}
int main()
{
int poly[20], vertex, dx, dy, i;
initwindow(640, 480, "translation");
printf( "Number of vertex: " );
scanf( "%d", &vertex );
for(i=0; i < vertex; i++)
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
setbkcolor(WHITE);
setcolor(BLACK);
drawpoly( vertex, poly );
setfillstyle(1,GREEN);
fillpoly( vertex, poly );
translate(poly,vertex,dx,dy);
setcolor(BLACK);
drawpoly( vertex, poly );
setfillstyle(1,RED);
fillpoly( vertex, poly );
setcolor(BLACK);
circle(dx, dy, 5);
while( !kbhit() );
return EXIT_SUCCESS;
}