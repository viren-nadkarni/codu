#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#define RNO 6
#define smax 40
//To Implement River Crossing Problem using DFS.

typedef struct state
{  int m,n,b;
   int cost;
   char path[smax];
}state;

state generated[smax];
int sct;

typedef struct gnode
{	state data;
	struct gnode* nextv;
	struct gnode* alist;
}gnode;
gnode *graph;

int equal(state p,state q)
{	return (p.m==q.m && p.n==q.n && p.b==q.b);	}

int unique(state s)
{	int i;
	for(i=0;i<sct;i++)
	if(equal(generated[i],s))
	return 0;
	return 1;
}

gnode* getnode(state d)
{	gnode* temp;
	temp=(gnode*) malloc(sizeof(gnode));
	temp->data=d;	temp->nextv=NULL;	temp->alist=NULL;
	return temp;
}

void disp(gnode* g)
{	gnode* temp;	gnode* aux;
	if(g==NULL)
	{	printf("\nEmpty Graph.");
		return;
	}
	printf("\n\n\tG\n\n\t|\n\n");
	for(temp=g;temp!=NULL;temp=temp->nextv)
	{	printf("\t(%d,%d,%d)",temp->data.m,temp->data.n,temp->data.b);
		for(aux=temp->alist;aux!=NULL;aux=aux->alist)
		printf("\t-> (%d,%d,%d)",aux->data.m,aux->data.n,aux->data.b);
		printf("\n\n\t|\n\n");
		getch();
	}
}


gnode* addvert(gnode* graph,state v)
{       gnode* temp;          	gnode* x;
	x=getnode(v);
	if(graph==NULL)		{ 	graph=x;	return graph;	}
	temp=graph;
	while(temp->nextv!=NULL)	temp=temp->nextv;
	temp->nextv=x;
	return graph;
}


gnode* addedge(gnode* graph,state ivert,state fvert)
{	gnode* temp;	gnode* prev;
	gnode* ivt;    	gnode* fvt;
	if(graph==NULL)
	{	printf("\nGraph is Empty.");	getch();  return graph;	}

	temp=graph;	ivt=NULL;
	while(temp!=NULL && equal(temp->data,ivert)==0)
	temp=temp->nextv;

	if(temp==NULL)
	{	printf("\nVertex Not present in Graph.");
		getch();	return graph;
	}
	else	ivt=temp;

	fvt=getnode(fvert);
	if(ivt->alist==NULL)
	{	ivt->alist=fvt;		return graph;	}
	temp=ivt->alist;
	while(temp->alist!=NULL)
	{	if(equal(temp->data,fvert))
		{	free(fvt);	return graph;	}
		temp=temp->alist;
	}
	temp->alist=fvt;
	return graph;
}

gnode* rmvedge(gnode* graph,state ivert,state fvert)
{       gnode* temp;	gnode* ivt;  gnode *prev;

	if(graph==NULL)
	{	printf("\nGraph is Empty.");	getch(); return graph;	}

	temp=graph->nextv;	ivt=NULL;
	while(temp!=NULL && equal(temp->data,ivert)==0)
	temp=temp->nextv;

	if(temp==NULL)
	{	printf("\nVertex Not present in Graph.");
		getch();	return graph;
	}
	if(ivt->alist==NULL)
	{	printf("\nEdge Does Not Exits.");  getch();	return graph;	}

	if(equal(ivt->alist->data,fvert))
	{	temp=ivt->alist;
		ivt->alist=temp->alist;
		free(temp);	return graph;
	}
	temp=prev=ivt->alist;
	while(temp!=NULL && equal(temp->data,fvert)==0)
	{	prev=temp;	temp=temp->alist;    }

	if(temp==NULL)
	{	printf("\nEdge Does Not Exit.");  getch();	return graph;	}
	prev->alist=temp->alist;
	free(temp);
	return graph;
}

gnode* rmvvert(gnode* graph,state v)
{       gnode* temp;	gnode* prev;	gnode* x;

	if(equal(graph->data,v))
	{	x=graph;	graph=graph->nextv;
	}
	else
	{       temp=graph;	prev=NULL;
		while(temp!=NULL && equal(temp->data,v)==0)
		{	prev=temp;	temp=temp->nextv;	}
		 if(temp==NULL)
		 {	printf("\nVertex Not Present in Graph");
			getch();	return graph;
		 }
		 prev->nextv=temp->nextv;
		 x=temp;
	}

	while(x->alist!=NULL)
	{	temp=x->alist;	x->alist=temp->alist;
		free(temp);
	}
	x->alist=NULL;
	free(x);
	return graph;
}

int isfinal(state s)
{	return (s.m==0 && s.n==0 && s.b==0);	}

int apply_rule(int rno,state &current,state &final,int M,int N)
{
switch(rno)
{
case 1:  if(current.m>0 && current.b==1)
	 {	final.m=current.m-1;	final.n=current.n;	final.b=0;
		final.cost=current.cost+7;
		strcpy(final.path,current.path);
		strcat(final.path,"1");
		return 1;
	 }
	 break;
case 2:  if(current.m<=M-1 && current.b==0)
	 {	final.m=current.m+1;	final.n=current.n;	final.b=1;
		final.cost=current.cost+7;
		strcpy(final.path,current.path);
		strcat(final.path,"2");
		return 1;
	 }
	 break;
case 3: if(current.n>0 && current.b==1)
	{	final.m=current.m;	final.n=current.n-1;	final.b=0;
		final.cost=current.cost+10;
		strcpy(final.path,current.path);
		strcat(final.path,"3");
		return 1;
	 }
	 break;
case 4: if(current.n<=N-1 && current.b==0)
	 {	final.m=current.m;	final.n=current.n+1;	final.b=1;
		final.cost=current.cost+10;
		strcpy(final.path,current.path);
		strcat(final.path,"4");
		return 1;
	 }
	 break;
case 5: if(current.n>1 && current.b==1)
	{	final.m=current.m;	final.n=current.n-2;	final.b=0;
		final.cost=current.cost+5;
		strcpy(final.path,current.path);
		strcat(final.path,"5");
		return 1;
	 }
	 break;
case 6: if(current.n<=N-2 && current.b==0)
	 {	final.m=current.m;	final.n=current.n+2;	final.b=1;
		final.cost=current.cost+5;
		strcpy(final.path,current.path);
		strcat(final.path,"6");
		return 1;
	 }
	 break;
}
return 0;
}

gnode* getvert(gnode *graph,state current)
{	gnode *temp;
	for(temp=graph;temp!=NULL;temp=temp->nextv)
	if(equal(temp->data,current))	return temp;
	return NULL;
}

gnode* generate(gnode *graph,state current,int m,int n) //Generates Successors
{       int i,f;  	state temp;
	for(i=1;i<=RNO;i++)
	{      	temp=current;	f=0;
		f=apply_rule(i,current,temp,m,n);
		if(f && unique(temp))
		{	graph=addedge(graph,current,temp);
			generated[sct]=temp;	sct++;
		}
	}
	return graph;
}



void dfs(state current, int *over,int m,int n)
{       gnode *temp,*aux;
	if(getvert(graph,current)!=NULL)   return;  //Check if Unexplored
	graph=addvert(graph,current);
	if(isfinal(current))
	{ printf("\nSolution Found:\nTotal Time=%d min\nPath=%s",current.cost,current.path);
	*over=1; return;}
	graph=generate(graph,current,m,n);         //Expand Node
	aux=getvert(graph,current);
	if(aux->alist==NULL)		graph=rmvvert(graph,current);
	else
	for(temp=aux->alist;temp!=NULL;temp=temp->alist)
	dfs(temp->data,over,m,n);
}


int main()
{       int m,n,i,ch;
	graph=NULL;
	sct=0;
	clrscr();
	printf("\nEnter Number of People who wish to cross the river:\n");
	printf("Men:");		scanf("%d",&m);
	printf("Boys:");        scanf("%d",&n);
	state initial;
	initial.m=m;	initial.n=n;	initial.b=1;
	initial.cost=0;	initial.path[0]='\0';
	generated[sct]=initial;	sct++;
	i=0;	dfs(initial,&i,m,n);
	if(i)
	{
	do{	printf("\n\nPress:\n1 To View Trace.\n0.To Exit.\n:");
		scanf("%d",&ch);
		switch(ch)
		{
		case 1:	clrscr();
			disp(graph);	break;
		case 0:break;
		default:printf("\nInvalid Option.");
		}
	}while(ch!=0);
	}
	else	printf("\nNo Solution Found");
	getch();
	return 0;
}