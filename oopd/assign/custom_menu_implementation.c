#include <ncurses/curses.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void printMenu(char **,int,int);
void printMenu(char * menu[], int num, int highlight)
{
	clear();
	int i;
	for(i=0;i<num;++i)
	{
		if(i==highlight)
		{
			attron(A_STANDOUT);
			printw("%s\n",(menu[i]));
			attroff(A_STANDOUT);
		}
		else
			printw("%s\n",(menu[i]));
	}
	refresh();
}

int menuControl(char **,int);
int menuControl(char **menu, int numOfOptions)
{
	char ch;
	int current=0;
	
	noecho();
	cbreak();
	keypad(stdscr, TRUE);
	
	while(1)
	{
		printMenu(menu, numOfOptions, current);
		ch=getch();
		switch(ch)
		{
			case 3:				
				if(current!=0)
					printMenu(menu, numOfOptions, --current);
				break;
				
			case 2:
				if(current+1!=numOfOptions)
					printMenu(menu, numOfOptions, ++current);
				break;
				
			case 10:
				printw("enter");
				return current;
				
			default:
				break;
		}
		refresh();
		clear();
	}
}



int main()
{
	int ch;
	char *mn[]={"option 1","option 2"};
	
	initscr();
	
	if(menuControl(mn,2));	
	
	getch();
	endwin();
	return 0;
}