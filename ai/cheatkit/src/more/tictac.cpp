#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<graphics.h>


//using namespace std;

//To Implement TicTacToe  Game using Minimax

struct gameboard
{	int cell[9];
	int player;                 //who's move is next X or O
	int score;
};
typedef struct gameboard gameboard;

struct tnode
{	gameboard board;
	int turn;                   //Minimizing or Maximizing
	struct tnode *son;
	struct tnode *next;
};
typedef struct tnode tnode;

tnode* getnode(int *b,int p)
{	tnode *t=NULL;    int i;
	t=(tnode*)malloc(sizeof(tnode));
	if(t==NULL)
	{	cout<<"\nMemory Allocation Error.";
		getch();	exit(1);		}
	for(i=0;i<9;i++)
	t->board.cell[i]=b[i];
	t->board.score=0;
	t->board.player=p;
	t->turn=1;
	t->son=NULL;	t->next=NULL;
	return t;
}

void printboard(int *b)
{	int l,t,dx,i,j,k;
	char c[2];
	l=getmaxx()/4;	t=getmaxy()/4;	dx=240;
	rectangle(l,t,l+dx,t+dx);
	for(i=1;i<3;i++)
	{	line(l+(i*dx)/3,t,l+(i*dx)/3,t+dx);
		line(l,t+(i*dx)/3,l+dx,t+(i*dx)/3);
	}
	settextstyle(5,0,2);
	for(i=0;i<3;i++)
	for(j=0;j<3;j++)
	{       k=b[3*i+j];
		switch(k)
		{
		case 2:c[0]=3*i+j+49;  	break;
		case 3:c[0]='X';        setcolor(4);	break;
		case 5:c[0]='O';        setcolor(14);	break;
		}
		c[1]='\0';
		outtextxy(l+(j*dx)/3+dx/6-5,t+(i*dx)/3+dx/6-10,c);
		setcolor(15);
	}

}




void printtree(tnode *root)
{	if(root)
	{       getch();
		cleardevice();  	clrscr();
		cout<<endl;
		for(int i=0;i<3;i++)
		{	for(int j=0;j<3;j++)
			cout<<"\t"<<root->board.cell[3*i+j];
			cout<<endl;
		}
		cout<<"Score:"<<root->board.score;
		getch();
		if(root->next)		printtree(root->next);
		if(root->son)		printtree(root->son);
	}
}

int swapplayer(int p1)
{	if(p1==3)	return 5;
	else		return 3;
}

tnode* genmove(tnode *move)
{       tnode *mlist=NULL;	tnode *p,*t;
	int i;
	for(i=0;i<9;i++)
	if(move->board.cell[i]==2)                      //Check for Blank
	{      	move->board.cell[i]=move->board.player;
		p=getnode(move->board.cell,swapplayer(move->board.player));
		if(mlist==NULL)			mlist=p;
		else
		{	for(t=mlist;t->next!=NULL;t=t->next);
			t->next=p;
		}
		move->board.cell[i]=2;
	}
	return mlist;
}

void buildtree(tnode *tree,int tlvl,int depth)
{       tnode *temp;
	if(tlvl < depth)
	{	temp=genmove(tree);                    //Generate List of Moves Possible
		tree->son=temp;

		while(temp!=NULL)
		{       if(tree->turn==1)
				temp->turn=-1;
			else    temp->turn=1;
			temp->son=NULL;
			buildtree(temp,tlvl+1,depth);
			temp=temp->next;
		}
	}
}

int evaluate(int *board,int player)                      //+ve for O, -ve for X
{	int i,j,k,ct;	
    int values[8];
	int rp,cp,ldp,rdp;
	rp=cp=ldp=rdp=1;
    k=0;
	for(i=0;i<3;i++)
	{       rp=cp=1;
		for(j=0;j<3;j++)
		{	rp*=board[3*i+j];
			cp*=board[i+3*j];
			if((3*i+j)%2==0)
			{	if(i==j)
				ldp*=board[3*i+j];
				if((3*i+j)/2>0 && ((3*i+j)/2)<4)
				rdp*=board[3*i+j];
			}
		}
		values[k]=rp;      k++;       
        values[k]=cp;      k++;
	}
    values[k]=ldp;         k++;
    values[k]=rdp;
    k=0;          j=0;     ct=0;
    for(i=0;i<8;i++)
    {               if(values[i]==125)                return 50;
                    if(values[i]==27)                 return -50;
    }
    for(i=0;i<8;i++)
    {		    if(values[i]==50 && player==5)    return 40;
		    if(values[i]==18 && player==3)    return -40;
    }
    for(i=0;i<8;i++)
    {               if(values[i]==18 && player==5)    k++;
		    if(values[i]==50 && player==3)    j++;
		    if(values[i]==20 && board[5]==player)   ct+=4;
                    if(values[i]==12 && board[5]==player)   ct-=4;
                    if(values[i]==20)                 ct+=2;
		    if(values[i]==12)                 ct-=2;
    }
    if(k==1)         return 30;
    if(j==1)         return -30;
    return ct;
}



void bestbranch(tnode *root,tnode **bestson,int *bs)
{	tnode *temp,*aux;
	int v;

	if(root->son==NULL)                    //if leaf is found
	{    root->board.score=evaluate(root->board.cell,root->board.player);
		*bs=root->board.score;
		*bestson=root;
	}
	else
	{	temp=root->son;
		bestbranch(temp,bestson,bs);   	    //Call for son
		*bestson=temp;                     //Correctly Init bestson
		if(root->turn==-1)                  //Set Proper Score
			*bs=-*bs;

		temp=temp->next;

		while(temp!=NULL)                  //Eval next son
		{  	bestbranch(temp,&aux,&v);  //Get new Values
			if(root->turn==-1)
				v=-v;

			if(v>*bs)              	   //If better move is found
			{       *bs=v;
				*bestson=temp;
			}
			temp=temp->next;
		}
		if(root->turn==-1)
			*bs=-*bs;
		root->board.score=*bs;
	}
}

gameboard makemove(int *board,int player,int const depth)
{	tnode *ttree=NULL;
	tnode *nextmove=NULL;
	int i,bs;
	ttree=getnode(board,player);
	buildtree(ttree,0,depth);
	if(player==3)
	ttree->turn=-1;
	bestbranch(ttree,&nextmove,&bs);
	//getch();	printtree(ttree);	getch();
	return nextmove->board;
}


int movepossible(int *b)
{	int f=0;
	for(int i=0;i<9;i++)
	if(b[i]==2)
	f=1;
	return f;
}


void playgame(gameboard *current,int turn,int depth)
{       int gd,gm;
	int pos,draw;
	int endgame=draw=0;
	gd=DETECT;
	initgraph(&gd,&gm,"c:\\tc\\bgi");
	do
	{
	cleardevice();
	printboard(current->cell);
	outtextxy(50,50,"Enter Move");

	if(movepossible(current->cell)==0)
	{	draw=1;	break;	}
	if(turn==1)
	{
		cin>>pos;  cout<<"\b";
		if(pos>0 && pos<10 && current->cell[pos-1]==2)
		{	current->cell[pos-1]=current->player;
			current->score=evaluate(current->cell,current->player);
			if(abs(current->score)==50)
			{	outtextxy(getmaxx()-200,getmaxy()-100,"U WIN");
				endgame=1;    break;
			}
			turn=0;
		}
		else
		{	outtextxy(getmaxx()-200,getmaxy()-100,"Invalid Input");
			getch();
		}
	}
	else
	{
		*current=makemove(current->cell,swapplayer(current->player),depth);
		if(abs(current->score)==50)
		{       outtextxy(getmaxx()-200,getmaxy()-100,"I WIN");
			endgame=1;    break;
		}
		turn=1;
	}
	}while(endgame==0);
	if(draw)
	outtextxy(getmaxx()-200,getmaxy()-100,"Its A Draw");
	else printboard(current->cell);
	getch();
	closegraph();
	restorecrtmode();
}

int main()
{	int initboard[9]={2,2,2,2,2,2,2,2,2};
	gameboard current;
	int i,turn,ch,user=3,diff=1,op;
	int depth=2;
	do
	{
	clrscr();
	cout<<"\nWelcome To TIC TAC TOE Game."<<endl;
	cout<<"\nMAIN MENU\n\n\n";
	cout<<"1.Start New Game.\n\n2.Options.\n\n3.Help.\n\n4.Exit.\n\n:";
	cin>>ch;
	switch(ch)
	{
	case 1: for(i=0;i<9;i++)
		current.cell[i]=initboard[i];
		current.player=user;
		current.score=0;
		if(diff==0)	depth=1;
		else		depth=2;
		if(user==3)
		playgame(&current,1,depth);
		else
		playgame(&current,0,depth);
		break;
	case 2: do
		{
		clrscr();
		cout<<"\nCURRENT SETTINGS\n\n";
		cout<<"-----------------------------------------------------";
		if(diff==1)
			cout<<endl<<"\nCurrent Difficulty Level for X:Tough";
		else
			cout<<endl<<"\nCurrent Difficulty Level:Easy";
		if(user==3)
			cout<<endl<<"\nComputer Plays as:O";
		else
			cout<<endl<<"\nComputer Plays as:X";
		cout<<"\n\n-----------------------------------------------------";
		cout<<endl<<"\nDo You Wish To:\n\n1.Change Difficulty Level."<<
		"\n\n2.Change Sides.\n\n3.Return To Main Menu.\n\n:";
		cin>>op;
		switch(op)
		{
		case 1:diff=!diff;		break;
		case 2:user=swapplayer(user);	break;
		case 3: 			break;
		default:cout<<"\nInvaid Option Entered.";
		}
		}while(op!=3);
		break;
	case 3: cout<<"\n-The Objective of the Game is to Occupy 3 Cells along the same Row or Column or Diagonal.\n"<<
		"-You Play as X.\n-To Make a Move Enter cell position where you want to play.<1-9>\n"<<
		"-Go to Options Menu to Change Game Difficulty or Side\n\nPress Any Key to return to Main Menu";
		getch();	break;

	default:cout<<"\nInvaid Option Entered.";
	}
	}while(ch!=4);
	return 0;
}
