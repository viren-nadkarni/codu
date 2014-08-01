#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
#define NQ 8


//To Implement 8-Queens Problem Using Breadth First Search.



struct state
{	int fpos[NQ];	int qct;	};
typedef struct state state;


struct qnode
{	state	data;
	struct qnode *next;
};
typedef struct qnode qnode;


class queue
{	qnode	*start;
public:
	queue()		{	start=NULL;		};
	int empty() 	{	return  start==NULL;	};
	void push(state s);
	state pop();
}que;


void queue::push(state s)
{	qnode *link=NULL,*temp;
	link=new qnode;
	if(link==NULL)
	{	cout<<"\nNot Enough Memory.";	getch();	exit(1);  }
	link->data=s;
	link->next=NULL;

	if(this->empty())
	{	start=link;   return;	}

	for(temp=start;temp->next!=NULL;temp=temp->next);
	temp->next=link;
}

state queue::pop()
{	state s;      qnode *temp;
	if(this->empty())
	{	cout<<"\nStack Underflow.";	getch();	exit(1);  }
	s=start->data;
	temp=start;	start=start->next;
	delete(temp);
	temp=NULL;
	return s;
}

int isvalid(int r1,int c1,int r2,int c2)      //To Check if Q(r1,c1) Attacks
{   if(c1==c2)			return 0;     //Q(r2,c2)
    if(abs(r1-r2)==abs(c1-c2))	return 0;
    return 1;
}


void printstate(state s,int n)
{       int i,j;
	cout<<endl<<endl;
	for(i=0;i<n;i++)
	{	for(j=0;j<n;j++)
		if(s.fpos[i]==j)
		cout<<" Q";
		else
		cout<<" -";
		cout<<endl;
	}
}


int generate(state current,int n,int ch)      //Generate All Valid Successors
{	int i,j,vct;                          //from Current State
	state temp;
	if(current.qct==n)	return 1;

	for(i=0;i<n;i++)
	{       if(current.qct==0)
		{  	temp=current;
			temp.fpos[current.qct]=i;
			temp.qct+=1;
			que.push(temp);
			if(ch==2)	printstate(temp,n);
		}
		else
		{       vct=0;
			for(j=0;j<current.qct;j++)
			if(isvalid(j,current.fpos[j],current.qct,i))
			vct++;
			if(vct==current.qct)
			{  	temp=current;
				temp.fpos[current.qct]=i;
				temp.qct+=1;
				que.push(temp);
				if(ch==2)	printstate(temp,n);
				if(temp.qct==n && ch!=3)
				{	cout<<endl<<"Solution Found:"<<endl;
					printstate(temp,n);
					getch();
					return 1;
				}
			}

		}
	}
	return 0;
}

void solve(int n,int ch)
{	state current,initial;       	int final;

	for(int i=0;i<n;i++)
	initial.fpos[i]=-1;
	initial.qct=0;

	while(que.empty()==0)
	que.pop();

	que.push(initial);

	final=0;
	while(que.empty()==0)
	{       if(ch==2)	clrscr();
		current=que.pop();
		if(ch==2)
		{
		cout<<"\nCurrent State:\n\n";
		printstate(current,n);
		cout<<"Qct="<<current.qct;
		getch();
		cout<<endl<<"\nPossibilities:\n\n";
		}
		final=generate(current,n,ch);
		if(ch==1 && final==1)
		break;
		if(final==1 && ch==3)
		{       cout<<endl<<"{";
			for(i=0;i<n;i++)
			cout<<current.fpos[i]+1;
			cout<<"}";
		}
		if(ch==2)	getch();
	}

	if(!final)
	cout<<endl<<"Unable to find Solution.";

}


int main()
{       clrscr();
	int ch;
	do
	{
	clrscr();
	cout<<"\n\n1.To View Solution.\n\n2.To Trace Solution."<<
	"\n\n3.To Generate All Possible Solutions.\n\nAnything Else to Exit\n:";
	cin>>ch;
	if(ch==3)
	cout<<endl<<"Solutions:"<<endl;
	solve(NQ,ch);
	getch();
	}while(ch==1 || ch==2 || ch==3);
	return 0;
}
