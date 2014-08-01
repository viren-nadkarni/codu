#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>

void scanline(int, int, int, int);
void scanline(int x, int y, int fill_color, int border)
{
	delay(1);
	putpixel(x,y,fill_color);
	printf("%d %d\n", x, y);
	
	if(getpixel(x+1,y) != border && getpixel(x+1,y) != fill_color)
		scanline(x+1,y,fill_color,border);
	
	if(getpixel(x,y+1) != border && getpixel(x,y+1) != fill_color)
		scanline(x,y+1,fill_color,border);
	
	if(getpixel(x-1,y) != border && getpixel(x-1,y) != fill_color)
		scanline(x-1,y,fill_color,border);
	
	if(getpixel(x,y-1) != border && getpixel(x,y-1) != fill_color) 
		scanline(x,y-1,fill_color,border);
	
	return;
}

int main()
{
	initwindow(320,240);
	
	rectangle(32, 24, 188, 216);
	circle(160, 120, 29);
	
	scanline(50, 40, BLUE, WHITE);
			
	while(!kbhit())
		delay(50);
	
	return EXIT_SUCCESS;
}
