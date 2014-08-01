#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>

void floodfill4(int, int, int, int);
void floodfill8(int, int, int, int);
void boundaryfill4(int, int, int, int);
void boundaryfill8(int, int, int, int);

void floodfill4(int x, int y, int fill_color, int old_color)
{
if(getpixel(x,y) == old_color)
{
	delay(50);
putpixel(x,y,fill_color);
floodfill4(x+1,y,fill_color,old_color);
floodfill4(x-1,y,fill_color,old_color);
floodfill4(x,y+1,fill_color,old_color);
floodfill4(x,y-1,fill_color,old_color);
}
}

void floodfill8(int x, int y, int fill_color, int old_color)
{
if(getpixel(x,y) == old_color)
{
putpixel(x,y,fill_color);
floodfill8(x+1,y,fill_color,old_color);
floodfill8(x-1,y,fill_color,old_color);
floodfill8(x,y+1,fill_color,old_color);
floodfill8(x,y-1,fill_color,old_color);
floodfill8(x+1,y+1,fill_color,old_color);
floodfill8(x+1,y-1,fill_color,old_color);
floodfill8(x-1,y+1,fill_color,old_color);
floodfill8(x-1,y-1,fill_color,old_color);
}
}

void boundaryfill4(int x, int y, int fill, int boundary)
{
int current;delay(50);
current = getpixel(x,y);
if(current!=boundary && current!=fill)
{
putpixel(x,y,fill);
boundaryfill4(x+1,y,fill,boundary);
boundaryfill4(x-1,y,fill,boundary);
boundaryfill4(x,y+1,fill,boundary);
boundaryfill4(x,y-1,fill,boundary);
//delay(50);
}
}

void boundaryfill8(int x, int y, int fill, int boundary)
{
int current;
current = getpixel(x,y);
if(current!=boundary && current!=fill)
{
putpixel(x,y,fill);
boundaryfill8(x+1,y,fill,boundary);
boundaryfill8(x-1,y,fill,boundary);
boundaryfill8(x,y+1,fill,boundary);
boundaryfill8(x,y-1,fill,boundary);
boundaryfill8(x+1,y+1,fill,boundary);
boundaryfill8(x-1,y+1,fill,boundary);
boundaryfill8(x-1,y-1,fill,boundary);
boundaryfill8(x+1,y-1,fill,boundary);
}
}

int main()
{
initwindow(400,400,"window");
//setbkcolor(WHITE);
//setcolor(BLACK);
//FLOOD FILL 4
rectangle(10,10,50,50);
floodfill4(30,30,BLUE,BLACK);
//FLOOD FILL 8
rectangle(110,10,150,50);
floodfill8(130,30,GREEN,BLACK);
//BOUNDARY FILL 4
circle(50,200,30);
boundaryfill4(50,200,RED,WHITE);
//BOUNDARY FILL 8
rectangle(200,20,250,50);
boundaryfill8(230,30,YELLOW,WHITE);
while(!kbhit())
delay(50);
return EXIT_SUCCESS;
}
