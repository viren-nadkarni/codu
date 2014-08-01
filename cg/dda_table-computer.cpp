#include <stdlib.h>
#include <math.h>
#include "graphics.h"

/*
sub dda(x1, xn, y1, yn)
	set m = (yn - y1) / (xn - x1)
	repeat for i = x1 to xn
		if (m <= 1) then
			set dx = 1
			set dy = m * dx
		else
			set dy = 1
			set dx = dy / m
		endif
		set x1 = x1 + dx
		set y1 = y1 + dy
		call putpixel(x1, y1)
	endfor
	exit
endsub
*/

void dda_line(int, int, int, int);
void dda_line(int x1, int y1, int x2, int y2)
{
	float x, y, xinc, yinc, dx, dy;
	int k, step;

	dx = x2 - x1;
	dy = y2 - y1;

	if(abs(dx) > abs(dy))
		step = abs(dx);
	else
		step = abs(dy);

	xinc = dx / step;
	yinc = dy / step;

	x = x1;
	y = y1;

	putpixel(x, y, WHITE);

	for(k = 1; k <= step; k++)
	{
		x = x + xinc;
		y = y + yinc;
		putpixel(x, y, WHITE);
	}
}

int main()
{
	initwindow(400, 400, "DDA - computer table");

	//top surface
	dda_line(75,50,300,50);
	dda_line(50,150,325,150);
	dda_line(75,50,50,150);
	dda_line(300,50,325,150);

	//top thickness
	dda_line(50,160,325,160);

	//legs
	dda_line(50,150,50,300);		//left
	dda_line(60,160,60,300);
	dda_line(50,300,60,300);
	dda_line(75,245,75,160);		//left inner vert surface
	dda_line(75,245,60,285);

	dda_line(315,160,315,300);		//right
	dda_line(325,150,325,300);
	dda_line(315,300,325,300);
	dda_line(300,245,300,160);		//right inner vert surface
	dda_line(300,245,315,285);


	//bottom thickness
	dda_line(60,295,315,295);
	dda_line(60,285,315,285);

	//vert separator
	dda_line(255,285,255,180);
	dda_line(265,285,265,180);
	dda_line(265,180,255,180);
	dda_line(261,160,265,180);		//thickness from top
	dda_line(251,160,255,180);
	dda_line(251,160,251,245);		//inner vert left surface
	dda_line(251,245,255,285);

	//bottom surface
	dda_line(265,245,300,245);
	dda_line(75,245,251,245);
	
	//keyboard surface
	dda_line(85,173,85,180);
	dda_line(250,173,250,180);
	dda_line(85,180,250,180);
	dda_line(85,173,250,173);
	dda_line(93,160,85,173);
	dda_line(245,160,250,173);
	dda_line(85,160,85,180);

	while ( !kbhit() )
		delay(100);

	return EXIT_SUCCESS;
}