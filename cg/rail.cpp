#include <stdlib.h>
#include "graphics.h"

int main()
{
	initwindow(640, 360, "DDA - railway");

	int i = 0;

	while(i < 635)
	{
		cleardevice();
		
		line(1,280,639,280);
				
		rectangle(630 - i, 240, 640 - i, 260);
		line(620 - i, 260, 650 - i, 260);
		line(650 - i, 250, 650 - i, 260);
		line(650 - i, 250, 690 - i, 250);
		line(690 - i, 250, 690 - i, 275);
		line(690 - i, 275, 620 - i, 275);
		line(620 - i, 275, 620 - i, 260);
		circle(630 - i, 275, 5);
		circle(640 - i, 275, 5);
		circle(680 - i, 275, 5);
		circle(670 - i, 275, 5);

		rectangle(693 - i, 250, 763 - i, 275);
		circle(713 - i, 275, 5);
		circle(703 - i, 275, 5);
		circle(743 - i, 275, 5);
		circle(753 - i, 275, 5);

		rectangle(766 - i, 250, 836 - i, 275);
		circle(786 - i, 275, 5);
		circle(776 - i, 275, 5);
		circle(816 - i, 275, 5);
		circle(826 - i, 275, 5);

		rectangle(839 - i, 250, 909 - i, 275);
		circle(849 - i, 275, 5);
		circle(859 - i, 275, 5);
		circle(899 - i, 275, 5);
		circle(889 - i, 275, 5);

		i++;
				
		delay(50);
	}
	
	while ( !kbhit() )
		delay(100);

	return EXIT_SUCCESS;
}