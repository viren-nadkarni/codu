/* 
 * File:   main.c
 * Author: viren
 *
 * Created on November 3, 2012, 7:20 PM
 */
 
#include <ncurses/curses.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* a page replacement policy simulator
 * currently has fifo, lru algorithms
 */

struct page_
{
	int lastAccess, entryTime;
	
} page[6][2];

void print_menu(WINDOW *, char **, int, int);
int menu_control(WINDOW *, char **, int, int);
void panel_ctrl();
void disp_ctrl();
void random_disp_ctrl();

WINDOW * inp1, * inp2, * disp;
char *mode_str[]={"Least Recently Used","First In First Out"};
int mode=0,seed=2;

int main(int argc, char * argv[])
{
	initscr();
	
	char title[]="Page Replacement Simulator",ch;
	int i,j;
	
	attron(A_STANDOUT);
	printw("%s",title);
	for(i=strlen(title);i<COLS;++i)
		printw(" ");
	printw("\n");
	attroff(A_STANDOUT);
	
	attron(A_STANDOUT);
	mvprintw(LINES-2,0," A ");
	attroff(A_STANDOUT);
	printw(" Request page\t\t");
	
	attron(A_STANDOUT);
	printw(" R ");
	attroff(A_STANDOUT);
	printw(" Reset\t");
	
	attron(A_STANDOUT);
	mvprintw(LINES-1,0," M ");
	attroff(A_STANDOUT);
	printw(" Replacement policy\t\t");
	
	attron(A_STANDOUT);
	printw(" Q ");
	attroff(A_STANDOUT);
	printw(" Quit");
	
	panel_ctrl();
	disp=newwin(13,COLS-2,3,1);
	box(disp,0,0);
	srand(time(NULL));
	random_disp_ctrl();
	refresh();
	wrefresh(disp);
	
	
	curs_set(0);
	cbreak();
	noecho();
	keypad(stdscr, TRUE);
	while((ch=getch())!='Q' && ch!='q')
	{
		switch(ch)
		{
			case 'A':
			case 'a':
			{
				int foundFreeFrame=0,m,n;
				
				for(m=0;m<6;m++)
				{
					for(n=0;n<2;n++)
					{
						if(page[m][n].entryTime<0 && page[m][n].lastAccess<0)
						{
							foundFreeFrame=1;
							break;
						}
					}
					if(foundFreeFrame)
						break;
				}
				
				if(foundFreeFrame)
					mvprintw(LINES-5,0,"MESSAGE: An empty frame was found at %d%d    ",m,n);
				
				if(mode==0)
				{
					if(foundFreeFrame)
					{
						page[m][n].entryTime=time(NULL)%10000;
						page[m][n].lastAccess=time(NULL)%10000;
					}
					else
					{
						int t=page[0][0].lastAccess,x=0,y=0;
						for(m=0;m<6;++m)
						{
							for(n=0;n<2;++n)
							{
								if(page[m][n].lastAccess<t)
								{
									t=page[m][n].lastAccess;
									x=m;
									y=n;									
								}
							}
						}
						page[x][y].entryTime=time(NULL)%10000;
						page[x][y].lastAccess=time(NULL)%10000;
						mvprintw(LINES-5,0,"MESSAGE: Page with ID %d%d was replaced      ",x,y);
					}
				}
				else if(mode==1)
				{
					if(foundFreeFrame)
					{
						page[m][n].entryTime=time(NULL)%10000;
						page[m][n].lastAccess=time(NULL)%10000;
					}
					else
					{
						int t=page[0][0].entryTime,x=0,y=0;
						for(m=0;m<6;++m)
						{
							for(n=0;n<2;++n)
							{
								if(page[m][n].entryTime<t)
								{
									t=page[m][n].entryTime;
									x=m;
									y=n;									
								}
							}
						}
						page[x][y].entryTime=time(NULL)%10000;
						page[x][y].lastAccess=time(NULL)%10000;
						mvprintw(LINES-5,0,"MESSAGE: Page with ID %d%d was replaced      ",x,y);
					}
				}
				delwin(disp);
				disp=newwin(13,COLS-2,3,1);
				box(disp,0,0);
				disp_ctrl();
				wrefresh(disp);
				break;
			}
			
			case 'R':
			case 'r':
			{	
				delwin(disp);
				disp=newwin(13,COLS-2,3,1);
				box(disp,0,0);
				random_disp_ctrl();
				wrefresh(disp);
				break;
			}
			
			case 'M':
			case 'm':
			{
				inp1=newwin(4,COLS/3,(LINES/2)+(LINES/5),(COLS-COLS/4)/2);
				inp2=newwin(2,(COLS/3)-2,(LINES/2)+(LINES/5)+1,((COLS-COLS/4)/2)+1);
				box(inp1,0,0);
				wrefresh(inp1);
				
				mode=menu_control(inp2,mode_str,2,mode);
				mode--;
				
				wborder(inp1, ' ', ' ', ' ',' ',' ',' ',' ',' ');
				wrefresh(inp1);
				wrefresh(inp2);
				delwin(inp1);
				delwin(inp2);
				
				mvprintw(LINES-5,0,"MESSAGE: Replacement policy changed to %s    ",mode_str[mode]);
				panel_ctrl();
				refresh();
				
				break;
			}
			
			default:
				break;
		}
		panel_ctrl();
		
	}	
	endwin();
	return (EXIT_SUCCESS);
}

/*
 *
 *
 *
 *
 */
 
void random_disp_ctrl()
{
	int i,j,x;
	
	for(i=0;i<6;++i)
	{
		for(j=0;j<2;++j)
		{
			if(rand()%10>seed)
			{
				while((x=rand()%1000)>=(time(NULL)%10000))
				{}
				page[i][j].entryTime=x;
				
				while((x=rand()%1000)>=(time(NULL)%10000) || x<page[i][j].entryTime)
				{}
				page[i][j].lastAccess=x;
			}
			else
			{
				page[i][j].entryTime=-1;
				page[i][j].lastAccess=-1;
			}
		}
	}
	disp_ctrl();
}

void disp_ctrl()
{
	int width,height,i,j,k,l;
	height=13;
	width=COLS-2;
	
	//vertical lines
	for(i=0;i<height;++i)
	{		
		if(i==0)
			mvwaddch(disp,i,width/2,ACS_TTEE);
		else if(i==height-1)
			mvwaddch(disp,i,width/2,ACS_BTEE);
		else
			mvwaddch(disp,i,width/2,ACS_VLINE);
	}
	
	//horizontal
	for(i=2;i<height-1;i+=2)
	{
		for(j=0;j<width;++j)
		{
			if(j==0)
				mvwaddch(disp,i,j,ACS_LTEE);
			else if(j==width/2)
				mvwaddch(disp,i,j,ACS_PLUS);
			else if(j==width-1)
				mvwaddch(disp,i,j,ACS_RTEE);
			else
				mvwaddch(disp,i,j,ACS_HLINE);
		}
	}
	
	
	for(i=0;i<6;++i)
	{
		for(j=0;j<2;++j)
		{
			if(page[i][j].entryTime>0)
			{
				wattron(disp,A_STANDOUT);
				if(j==0)
				{	
					for(k=0;k<(width/2)-1;++k)
						mvwprintw(disp,(2*i)+1,1+k," ");
					mvwprintw(disp,(2*i)+1,1,"PageID:%d%d\tEntryTime:%d\tLastAccessTime:%d",i,j,page[i][j].entryTime,page[i][j].lastAccess);
				}
				else
				{
					for(k=0;k<(width/2)-2;++k)
						mvwprintw(disp,(2*i)+1,(width/2)+1+k," ");
					mvwprintw(disp,(2*i)+1,(width/2)+1,"PageID:%d%d\tEntryTime:%d\tLastAccessTime:%d",i,j,page[i][j].entryTime,page[i][j].lastAccess);
				}
				wattroff(disp,A_STANDOUT);
			}
		}
	}
} 

void panel_ctrl()
{
	mvprintw(LINES-1,COLS-30,"Mode: %s               ",mode_str[mode]);
	mvprintw(LINES-2,COLS-30,"Number of frames: %d   ",12);
	mvprintw(LINES-3,COLS-30,"Current time: %d       ",time(NULL)%10000);
}

void print_menu(WINDOW *w, char * menu[], int num, int highlight)
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

int menu_control(WINDOW *w, char **menu, int num_options, int current)
{
	char ch;
	
	keypad(w, TRUE);
	noecho();
	cbreak();
	
	while(1)
	{
		print_menu(w, menu, num_options, current);
		ch=getch();
		switch(ch)
		{
			case 3:				
				if(current!=0)
					print_menu(w,menu, num_options, --current);
				break;
				
			case 2:
				if(current+1!=num_options)
					print_menu(w, menu, num_options, ++current);
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



