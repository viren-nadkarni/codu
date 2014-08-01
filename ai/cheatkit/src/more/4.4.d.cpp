#include<iostream.h>
#include<iomanip.h>
#include<graphics.h>
#include<conio.h>
#include<string.h>

int rules[5];

struct node
	{
	struct
		{
		int n_can;
		int n_mis;
		}side[2];
	int boat_position;
	}GOAL,CURRENT,NEXT,SUCCESSOR;

int Equal(struct node a,struct node b)
	{
	if(a.side[1].n_can!=b.side[1].n_can)
		return 0;
	if(a.side[1].n_mis!=b.side[1].n_mis)
		return 0;
	return 1;
	}

void Assign(struct node *a,struct node *b)
	{
	a->side[0].n_can=b->side[0].n_can;
	a->side[1].n_can=b->side[1].n_can;
	a->side[0].n_mis=b->side[0].n_mis;
	a->side[1].n_mis=b->side[1].n_mis;
	a->boat_position=b->boat_position;
	}

int GetRules(struct node a)
	{
	int i,j,n=0;
	for(i=0;i<5;i++)
		rules[i]=0;
	i=a.boat_position;
	if(i==0)
		j=1;
	else
		j=0;
	if(a.side[i].n_mis==2 || (a.side[i].n_mis>2 && a.side[i].n_mis-2>=a.side[i].n_can))
		{
		rules[0]=1;
		n++;
		}
	if(a.side[i].n_can>=2 && (a.side[j].n_mis==0 || a.side[j].n_mis>=a.side[j].n_can+2))
		{
		rules[1]=1;
		n++;
		}
	if(a.side[i].n_can>=1 && a.side[i].n_mis>=1 && a.side[j].n_mis>=a.side[j].n_can)
		{
		rules[2]=1;
		n++;
		}
	if(a.side[i].n_mis==1 || (a.side[i].n_mis>1 && a.side[i].n_mis-1>=a.side[i].n_can))
		{
		rules[3]=1;
		n++;
		}
	if(a.side[i].n_can>=1 && (a.side[j].n_mis==0 || a.side[j].n_mis>=a.side[j].n_can+1))
		{
		rules[4]=1;
		n++;
		}
	return n;
	}

void ApplyRule()
	{
	int i,j,k;
	for(k=0;k<5;k++)
		if(rules[k]==1)
			break;
	rules[k]=0;
	i=CURRENT.boat_position;
	if(i==0)
		j=1;
	else
		j=0;
	Assign(&NEXT,&CURRENT);
	NEXT.boat_position=j;
	switch(k)
		{
		case 0:
			NEXT.side[i].n_mis-=2;
			NEXT.side[j].n_mis+=2;
			return;
		case 1:
			NEXT.side[i].n_can-=2;
			NEXT.side[j].n_can+=2;
			return;
		case 2:
			NEXT.side[i].n_can--;
			NEXT.side[j].n_can++;
			NEXT.side[i].n_mis--;
			NEXT.side[j].n_mis++;
			return;
		case 3:
			NEXT.side[i].n_mis--;
			NEXT.side[j].n_mis++;
			return;
		default:
			NEXT.side[i].n_can--;
			NEXT.side[j].n_can++;
			return;
		}
	}

int Eval(struct node a)
	{
	int val=0;
	val+=a.side[0].n_can;
	val+=a.side[0].n_mis;
	return val;
	}

int SuccessorBetterThanCurrent()
	{
	int aval,bval;
	aval=Eval(SUCCESSOR);
	bval=Eval(CURRENT);
	if(aval<bval || SUCCESSOR.side[0].n_can>=CURRENT.side[0].n_can)
		return 1;
	return 0;
	}

int NextBetterThanSuccessor()
	{
	int aval,bval;
	aval=Eval(NEXT);
	bval=Eval(SUCCESSOR);
	if(aval<bval || (aval==bval && NEXT.side[1].n_mis>SUCCESSOR.side[1].n_mis))
			return 1;
	return 0;
	}

void display(struct node a)
	{
	int i;
	char M[5],C[5],B[5];
	M[2]='\0';   M[1]='M';
	C[2]='\0';   C[1]='C';
	B[4]='\0';   strcpy(B,"BOAT");
	settextstyle(0,0,3);

	  C[0]=a.side[0].n_can+48;
	  outtextxy(40,100,C);

	  M[0]=a.side[0].n_mis+48;
	  outtextxy(40,160,M);

	  if(a.boat_position==0)
		 outtextxy(100,130,B);
	  else
		 outtextxy(480,130,B);

	  C[0]=a.side[1].n_can+48;
	  outtextxy(580,100,C);

	  M[0]=a.side[1].n_mis+48;
	  outtextxy(580,160,M);

	  getch();
	  cleardevice();
	}


int SteepestAscentHillClimbing()
	{
	int k,f;
	if(Equal(CURRENT,GOAL))
		return 1;
	while(1)
		{
		f=0;
		display(CURRENT);
		k=GetRules(CURRENT);
		while(k>0)
			{
			ApplyRule();
			k--;
			if(Equal(NEXT,GOAL))
				{
				display(NEXT);
				return 1;
				}
			if(!f || NextBetterThanSuccessor())
				{
				Assign(&SUCCESSOR,&NEXT);
				f=1;
				}
			}
		if(SuccessorBetterThanCurrent())
			Assign(&CURRENT,&SUCCESSOR);
		else
			return 0;
		}
	}


void main()
	{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"c:\\tc\\bgi");

	CURRENT.side[0].n_can=3;
	CURRENT.side[0].n_mis=3;
	CURRENT.side[1].n_can=0;
	CURRENT.side[1].n_mis=0;
	CURRENT.boat_position=0;
	GOAL.side[0].n_can=0;
	GOAL.side[0].n_mis=0;
	GOAL.side[1].n_can=3;
	GOAL.side[1].n_mis=3;
	GOAL.boat_position=1;
	if(SteepestAscentHillClimbing())
		cout<<endl<<" ";
	}