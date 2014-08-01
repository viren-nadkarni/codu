#include "header.h"
#define MAXENTRIES 32
using namespace std;

Book b[MAXENTRIES];
Member m[MAXENTRIES];

static int borrowPeriod=7;
static float finePerDay=1.0;

int main()
{
	WINDOW *w;
	
	initscr();
	keypad(stdscr, TRUE);
	cbreak();	
	curs_set(0);
	
	bookIndex=0;
	memberIndex=0;
	
	attron(A_STANDOUT);
	mvprintw(0,(COLS-33)/2,"Welcome to library management app\n");
	attroff(A_STANDOUT);
	refresh();
	
	char *mainmenu[]={"1::Members","2::Books","3::Options","<< Exit"},
		*membermenu[]={"1::View member entry","2::Add member","3::Remove member","<< Go back"},
		*bookmenu[]={"1::View book entry","2::Add book","3::Remove book","<< Go back"},
		*optionmenu[]={"1::Read entries from files","2::Set borrow period & fines","3::Advance date","<< Go back"};
	int menuSelec,subMenuSelec;
	
	w=newwin(20,COLS-10,4,1);
	wrefresh(w);
	
	do
	{
		mvprintw(3,1,"MAIN MENU                    ");
		
		menuSelec=menuControl(w,mainmenu,4);
		switch(menuSelec)
		{
			case 1:
				mvprintw(3,1,"MAIN MENU >> MEMBERS");
				subMenuSelec=menuControl(w,membermenu,4);
				switch(subMenuSelec)
				{	
					case 1:	//view member				
					{
						int tmpId,j;
						bool flag=false;
						
						echo();
						nocbreak();
						wprintw(w,"\nEnter MemberID: ");
						wscanw(w,"%d",&tmpId);
						noecho();
						
						for(j=0;j<memberIndex;++j)
						{
							if(m[j].memberId==tmpId)
							{								
								flag=true;
								wprintw(w,"\nMemberID: %d\nName: %s",m[j].memberId,m[j].name);
								wprintw(w,"\nAge: %d",m[j].age);
								wprintw(w,"\nAddress: %s",m[j].address);
								wprintw(w,"\nBorrowed book: ");
								wrefresh(w);
								if(m[j].borrowedBook==0)
									wprintw(w,"none");
								
								else
								{
									int v=0;
									for(v=0;v<bookIndex;++v)
									{
										if(m[j].borrowedBook==b[v].bookId)
											break;
										else if(v==bookIndex-1)
										{
											attron(A_STANDOUT);
											mvprintw(LINES-2,(COLS-31)/2,"Caution: Entry info is corrupt!");
											attroff(A_STANDOUT);
											break;
										}
									}
									wprintw(w,"%s",b[v].name);
									wprintw(w,"\nBorrowed for: %d days",m[j].borrowedDuration);
									wprintw(w,"\nFines pending: Rs. ");
									if(m[j].borrowedDuration<=borrowPeriod)
										wprintw(w,"0.0");
									else
										wprintw(w,"%.2f",( ((float)((m[j].borrowedDuration)-borrowPeriod))*finePerDay ));
									
								}
								wrefresh(w);
								char ct;
								cbreak();
								wprintw(w,"\n\nPress 'y' change borrowed book\nPress any other key to return to menu");
								ct=wgetch(w);
								
								if(ct=='y' || ct=='Y')
								{
									echo();
									wprintw(w,"\n\nEnter new BookID: ");
									wscanw(w,"%d",&(m[j].borrowedBook));
									m[j].borrowedDuration=0;
									noecho();
									
									attron(A_STANDOUT);
									mvprintw(LINES-2,(COLS-14)/2,"Entry modified");
									attroff(A_STANDOUT);
									getch();
								}
								
								refresh();
								wrefresh(w);
								break;
							}				
						}
						if(!flag)
						{
							attron(A_STANDOUT);
							mvprintw(LINES-2,(COLS-23)/2,"MemberID does not exist");
							attroff(A_STANDOUT);
						}
						refresh();
						wrefresh(w);
						noecho();
						getch();
						break;
					}
					case 2: //add member
					{
						m[memberIndex].readMember();
						attron(A_STANDOUT);
						mvprintw(LINES-2,(COLS-12)/2,"Member added");
						attroff(A_STANDOUT);
						++memberIndex;
						refresh();
						wrefresh(w);
						getch();
						break;
					}	
					case 3: //remove member
					{
						int tmpId;
						bool flag=false;
						
						echo();
						wprintw(w,"\nEnter MemberID: ");
						wscanw(w,"%d",&tmpId);
						noecho();
						
						for(int w=0;w<memberIndex;++w)
						{
							if(m[w].memberId==tmpId)
							{
								for(int x=w;x<memberIndex-1;++x)
									m[x]=m[x+1];
								memberIndex--;
								attron(A_STANDOUT);
								mvprintw(LINES-2,(COLS-12)/2,"Member removed");
								attroff(A_STANDOUT);
								
								flag=true;
								break;
							}
							
						}
						if(!flag)
						{
							attron(A_STANDOUT);
							mvprintw(LINES-2,(COLS-12)/2,"Member not found");
							attroff(A_STANDOUT);
						}
						getch();
						break;
					}
				}
				break;
			case 2:
				mvprintw(3,1,"MAIN MENU >> BOOKS");
				subMenuSelec=menuControl(w,bookmenu,4);
				switch(subMenuSelec)
				{
					case 1: //view book
					{
						int tmpId;
						bool flag=false;
						
						echo();
						wprintw(w,"\nEnter BookID: ");
						wscanw(w,"%d",&tmpId);
						
						for(int j=0;j<bookIndex;++j)
						{
							if(b[j].bookId==tmpId)
							{
								flag=true;
								wprintw(w,"\nBookID: %d",b[j].bookId);
								wprintw(w,"\nName: %s",b[j].name);
								wprintw(w,"\nAuthor: %s",b[j].author);
								wprintw(w,"\nPublisher: %s",b[j].publisher);
								wrefresh(w);
								break;
							}							
						}
						if(!flag)
						{
							attron(A_STANDOUT);
							mvprintw(LINES-2,(COLS-23)/2,"BookID does not exist");
							attroff(A_STANDOUT);
						}
						//refresh();
						wrefresh(w);
						noecho();
						getch();
						break;						
					}
					case 2: //add book
					{						
						b[bookIndex].readBook();
						
						attron(A_STANDOUT);
						mvprintw(LINES-2,(COLS-12)/2,"Book added");
						attroff(A_STANDOUT);
						
						++bookIndex;
						refresh();
						wrefresh(w);
						
						getch();
						break;
					}	
					case 3: //remove book
					{
						int tmpId;
						bool flag=false;
						
						
						echo();
						wprintw(w,"\nEnter BookId: ");
						wscanw(w,"%d",&tmpId);
						noecho();
						
						for(int w=0;w<bookIndex;++w)
						{
							if(b[w].bookId==tmpId)
							{
								for(int x=w;x<bookIndex-1;++x)
									b[x]=b[x+1];
								attron(A_STANDOUT);
								mvprintw(LINES-2,(COLS-12)/2,"Book removed");
								attroff(A_STANDOUT);
								memberIndex--;
								flag=true;
								break;
							}							
						}
						
						if(!flag)
						{
							attron(A_STANDOUT);
							mvprintw(LINES-2,(COLS-12)/2,"Member not found");
							attroff(A_STANDOUT);
						}
						getch();
						break;
					}
				}
				break;
			case 3: 
				mvprintw(3,1,"MAIN MENU >> OPTIONS");
				subMenuSelec=menuControl(w,optionmenu,4);
				switch(subMenuSelec)
				{
					case 1: //read from files
					{
						char bookDbFilename[16], memberDbFilename[16];
						bool flag=false;
						ifstream bookDbStream, memberDbStream;
						
						echo();
						wprintw(w,"\nEnter filename for books database: ");
						wscanw(w,"%s",bookDbFilename);
						
						bookDbStream.open(bookDbFilename);
						if(bookDbStream)
						{			
							int i=0;
							while(!bookDbStream.eof() && i<5)
							{	
								bookDbStream >> b[i].bookId;
								bookDbStream.ignore();
								bookDbStream.getline(b[i].name,30);
								bookDbStream.getline(b[i].author,30);
								bookDbStream.getline(b[i].publisher,30);
								++bookIndex;
								i++;
							}			
							attron(A_STANDOUT);
							mvprintw(LINES-2,(COLS-22)/2,"%d entries were loaded", i);
							attroff(A_STANDOUT);
							flag=true;
						}
						else
						{
							attron(A_STANDOUT);
							mvprintw(LINES-2,(COLS-50)/2,"Failed to open file, check whether the file exists");
							attroff(A_STANDOUT);
						}
						refresh();
						
						wprintw(w,"Enter filename for members database: ");
						wrefresh(w);
						refresh();
						wscanw(w,"%s",memberDbFilename);
						memberDbStream.open(memberDbFilename);
						if(memberDbStream)
						{
							int i=0;
							while(!memberDbStream.eof() && i<3)
							{	
								memberDbStream >> m[i].memberId;
								memberDbStream.ignore();
								memberDbStream.getline(m[i].name,30);
								memberDbStream >> m[i].age;
								memberDbStream.ignore();
								memberDbStream.getline(m[i].address,60);
								memberDbStream >> m[i].borrowedBook;
								memberDbStream >> m[i].borrowedDuration;
								++memberIndex;
								i++;
							}			
							attron(A_STANDOUT);
							mvprintw(LINES-2,(COLS-22)/2,"%d entries were loaded", i);
							attroff(A_STANDOUT);		
						}
						else
						{
							attron(A_STANDOUT);
							mvprintw(LINES-2,(COLS-50)/2,"Failed to open file, check whether the file exists");
							attroff(A_STANDOUT);
						}
						refresh();
						wrefresh(w);
						getch();
						noecho();
						break;
					}
					case 2: //change fines and borrow period
					{
						echo();
						wprintw(w,"\nEnter borrow period in days: ");
						wscanw(w,"%d",&borrowPeriod);
						wprintw(w,"Enter fine per day in Rs.: ");
						wscanw(w,"%f",&finePerDay);
						noecho();
						
						attron(A_STANDOUT);
						mvprintw(LINES-2,(COLS-14)/2,"Values changed");
						attroff(A_STANDOUT);
						getch();
						break;
					}
					case 3: //advance date
					{
						int date;
						echo();
						nocbreak();
						wprintw(w,"\nEnter no. of days to advance: ");
						wscanw(w,"%d",&date);
						for(int s=0;s<memberIndex;++s)
						{
							if(m[s].borrowedBook!=0)
								(m[s].borrowedDuration)+=date;
						}
						attron(A_STANDOUT);
						mvprintw(LINES-2,(COLS-30)/2,"Date was successfully advanced");
						attroff(A_STANDOUT);
						
						noecho();
						cbreak();
						getch();
						break;
					}
					
				}
				break;
			
			//default: for main menu
			default:
				break;
		}
		mvprintw(LINES-2,(COLS-55)/2,"                                                       ");
	}while(menuSelec!=4);
	
	endwin();
	return 0;
}
