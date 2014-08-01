//FILE:header.h
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ncurses/curses.h>

using namespace std;

void printMenu(WINDOW *,char **,int,int);
int menuControl(WINDOW *,char **,int);

static int bookIndex=0,memberIndex=0;

class Book
{
	char name[32], author[32], publisher[32];
	short int bookId;
public:
	Book()
	{
		bookId=++bookIndex;
	};
	void readBook();
	
	friend int main();
};

class Member
{
	char name[32], address[64];
	short int age, borrowedBook, borrowedDuration;
	int memberId;
public:
	Member()
	{
		borrowedBook=0;
		borrowedDuration=0;
		memberId=++memberIndex;
	};
	void readMember();
	
	friend int main();
};

