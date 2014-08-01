//FILE:menuhandler.c
#include "header.h"

void printMenu(WINDOW *w, char * menu[], int num, int highlight)
{
	werase(w);
	int i;
	for(i=0;i<num;++i)
	{
		if(i==highlight)
		{
			wattron(w,A_STANDOUT);
			wprintw(w,"%s\n",(menu[i]));
			wattroff(w,A_STANDOUT);
		}
		else
			wprintw(w,"%s\n",(menu[i]));
	}
	wrefresh(w);
}

int menuControl(WINDOW *w, char **menu, int numOfOptions)
{
	char ch;
	int current=0;
	
	keypad(w, TRUE);
	noecho();
	cbreak();
	
	while(1)
	{
		printMenu(w, menu, numOfOptions, current);
		ch=getch();
		switch(ch)
		{
			case 3:				
				if(current!=0)
					printMenu(w,menu, numOfOptions, --current);
				break;
				
			case 2:
				if(current+1!=numOfOptions)
					printMenu(w, menu, numOfOptions, ++current);
				break;
				
			case 10:
				return (current+1);
				
			default:
				break;
		}
		wrefresh(w);
		werase(w);
	}
}
