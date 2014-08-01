#include "header.h"

void Book::readBook()
{
	nocbreak();
	echo();
	
	bookId=(++bookIndex);
	
	mvprintw(10,0,"\n BookID: %d\n Book name: ",bookId);
	getstr(name);
	
	printw(" Author: ");
	getstr(author);
	
	printw(" Publisher: ");
	getstr(publisher);
	
	cbreak();
	noecho();
	
	refresh();
}



void Member::readMember()
{
	nocbreak();
	echo();
	
	memberId=(++memberIndex);
	
	mvprintw(10,0,"\n MemberID: %d\n Name: ",memberId);
	getstr(name);
	
	printw(" Age: ");
	scanw("%d,",&age);
	
	printw(" Address: ");
	getstr(address);
	
	cbreak();
	noecho();
}
