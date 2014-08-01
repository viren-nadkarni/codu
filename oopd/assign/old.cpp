//the main function
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstring>
#include <ncurses/curses.h>
#include <ncurses/menu.h>

#define MAXBOOKENTRIES 32
#define MAXMEMBERENTRIES 32


using namespace std;

static short int bookIndex=0, memberIndex=0;

void printTitle();
void printTitle()
{
	clear();
	attron(A_STANDOUT);
	mvprintw(0,20,"Welcome to library management app\n\n");
	attroff(A_STANDOUT);
	
}


//'Book' class and functions
class Book
{
	char name[32], author[32], publisher[32];
	short int bookId;
public:
	Book()
	{
		bookId=++bookIndex;
	};
	void initBook();
	
	friend int main(int, char **);
};

void Book::initBook()
{
	printw("\nBookID: %d\nBook name: ",bookId);
	getstr(name);
	
	printw("Author: ");
	getstr(author);
	
	printw("Publisher: ");
	getstr(publisher);
	
	bookIndex++;	
}




//'Member' class and functions
class Member
{
	char name[32], address[64];
	short int age, memberId, borrowedBook, borrowedDuration;
public:
	Member()
	{
		borrowedBook=0;
		borrowedDuration=0;
		memberId=++memberIndex;
	};
	void initMember();
	
	friend int main(int, char **);
};

void Member::initMember()
{
	printw("\nMemberID: %d\nName: ",memberId);
	getstr(name);
	
	printw("Age: ");
	scanw("%d,",&age);
	
	printw("Address: ");
	getstr(address);
	
	memberIndex++;
}


///////////////////////////////////////
///////////////////////////////////////
//main function
int main(int argc, char * argv[])
{
	initscr();	
	
	Book books[MAXBOOKENTRIES];
	Member members[MAXMEMBERENTRIES];
	bookIndex=0;
	memberIndex=0;
	
	char ch,dh;
	
	printTitle();
	raw();
	printw("\nWould you like to data from files? ");
	ch=getch();
	cbreak();
	
	if(ch=='Y' || ch=='y')
	{
		char bookDbFilename[16], memberDbFilename[16];
		ifstream bookDbStream, memberDbStream;
		
		printw("\n\tEnter filename for books database: ");
		getstr(bookDbFilename);
		
		bookDbStream.open(bookDbFilename);
		if(bookDbStream)
		{			
			int i=0;
			while(!bookDbStream.eof())
			{	
				bookDbStream.getline(books[i].name,30);
				bookDbStream.getline(books[i].author,30);
				bookDbStream.getline(books[i].publisher,30);
				bookIndex++;
				i++;
			}			
			attron(A_STANDOUT);
			printw("%d entries were loaded", i);
			attroff(A_STANDOUT);
		
		}
		else
		{
			attron(A_STANDOUT);
			printw("Failed to open file, check whether the file exists");
			attroff(A_STANDOUT);
		}
		
		printw("\n\tEnter filename for members database: ");
		getstr(memberDbFilename);
		memberDbStream.open(memberDbFilename);
		if(memberDbStream)
		{
			int i=0;
			while(!memberDbStream.eof() && i<2)
			{	
				memberDbStream.getline(members[i].name,30);
				memberDbStream >> members[i].age;
				memberDbStream.ignore();
				memberDbStream.getline(members[i].address,60);
				memberDbStream >> members[i].borrowedBook;
				memberDbStream >> members[i].borrowedDuration;
				memberDbStream.ignore();
				memberIndex++;
				i++;
			}			
			attron(A_STANDOUT);
			printw("%d entries were loaded", i);
			attroff(A_STANDOUT);		
		}
		else
		{
			attron(A_STANDOUT);
			printw("Failed to open file, check whether the file exists\n\n\n");
			attroff(A_STANDOUT);
		}
		getch();
	}
	
	printTitle();
	
	do
	{
		attron(A_STANDOUT);
		printw("MAIN MENU");
		attroff(A_STANDOUT);
		printw("\n1::Members\n2::Books\n3::Exit\nPress number key");
		ch=getch();
		switch(ch)
		{
			case '1':
			{
				do
				{
					printTitle();
					attron(A_STANDOUT);
					printw("MEMBERS");
					attroff(A_STANDOUT);
					printw("\n1::Add entry\n2::View entry info\n3::Go back\nPress number key");
					dh=getch();
					switch(dh)
					{
						case '1':
							printTitle();
							members[memberIndex].initMember();						
							break;
						case '2':
						{
							printTitle();
							attron(A_STANDOUT);
							printw("VIEW ENTRY INFO");
							attroff(A_STANDOUT);
							
							int tmpId;
							bool flag=false;
							printw("\nEnter MemberID: ");
							scanw("%d",&tmpId);
							
							for(int j=0;j<memberIndex;++j)
							{
								if(members[j].memberId==tmpId)
								{
									flag=true;
									printw("\nMemberID: %d\nName: %s",members[j].memberId,members[j].name);
									printw("\nAge: %d",members[j].age);
									printw("\nAddress: %s",members[j].address);								
									getch();
									break;
								}
								
							}
							if(!flag)
							{
								attron(A_STANDOUT);
								printw("MemberID does not exist");
								attroff(A_STANDOUT);
								getch();
								break;
							}
							break;
						}
						case '3':							
						default:
							break;
					}					
				}while(dh!='3');
				break;
			}
			case '2':
				
				
				break;
			default:
				break;
		}
		printTitle();
		
		
	}while(ch!='3');
	
	endwin();
	return 0;
}
