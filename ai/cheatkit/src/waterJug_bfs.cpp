#include<iostream.h>
#include<conio.h>
#include<stdlib.h>

//To Implement Water Jug problem using Breadth First Search
int g1,g2,target;

int ns=0;
struct rule
{	int r1,r2;	};
struct rule store[30];

struct node
{       int n1,n2;
	struct node * next;
}*alist[20];

node *front=NULL,*rear=NULL;

void storenode(int a,int b)
{       store[ns].r1=a;
	store[ns].r2=b;
	ns++;
}

int search(int a,int b)
{    for(int i=0;i<ns;i++)
     {   if(store[i].r1==a && store[i].r2==b)
	 return 1;
     }
     return 0;
}

node *getnode(int n1,int n2)
{       node *n=NULL;
	n=(node *)malloc(sizeof(node));
	if(n==NULL)
	{	cout<<"\nNot Enough Memory.";
	getch();
	exit(0);
	}
	n->n1=n1;
	n->n2=n2;
	n->next=NULL;
	return n;
}

void add(int i,int x,int y)            //Add node to alist of Vertex i
{  node *link;
   node *aux=NULL;
   link=getnode(x,y);
   if(alist[i]==NULL)
	alist[i]=link;
   else
   {    aux=alist[i];
	while(aux->next!=NULL)
	aux=aux->next;
	aux->next=link;
   }
}

void insert(int x,int y)
{       if(rear==NULL)
	{  rear=getnode(x,y);
	   front=rear;
	}
	else
	{   rear->next=getnode(x,y);
	    rear=rear->next;
	}
}

void deleteq(node **temp)
{      if(front==NULL)
       {	cout<<"QUEUE EMPTY";
       exit(0);
       }
       else
       {	if(front==rear)
		{  *temp=front;
		   front=NULL;
		   rear=NULL;
		}
		else
		{
		   *temp=front;
		   front=front->next;
		}
       }
}


int findrulex(int i,node *n)
{       int x,y;
	x=n->n1;
	y=n->n2;
	if(x==target)
	return 1;

	if(x<g1)                			//fill 4g jug
	{  if(search(g1,y)==0)
	   {    add(i,g1,y);
		insert(g1,y);
		storenode(g1,y);
	   }
	}

	if(x>0)           			//empty 4g
	{   if(search(0,y)==0)
	    {   add(i,0,y);
		insert(0,y);
		storenode(0,y);
	    }
	}
	return 0;
}


int findruley(int i,node *n)
{       int x,y;
	x=n->n1;
	y=n->n2;
	if(x==target)
	return 1;
	if(y<g2)                        		//fill 3g
	{
	   if(search(x,g2)==0)
	   {    add(i,x,g2);
		insert(x,g2);
		storenode(x,g2);
	   }
	}

	if(y>0)          			//empty 3g
	{  if(search(x,0)==0)
	  {   	add(i,x,0);
		insert(x,0);
		storenode(x,0);
	  }
	}
	return 0;
}

int findrulexy(int i,node *n)
{       int x,y,r1,r2;
	x=n->n1;
	y=n->n2;

	if(x==target)
	return 1;

	if(x+y >=g2 && x>0) 	//pour water from 4 to 3 until full
	{  r1=x-(g2-y);
	   r2=g2;
	   if(r1==target)
	   {    add(i+1,r1,r2);
		return 1;
	   }
	   else
	   {   if(search(r1,r2)==0)
	       {        add(i,r1,r2);
			insert(r1,r2);
			storenode(r1,r2);
	       }
	   }
	}

	if(x+y>=g1 && y>0)   	//pour water from 3 to 4 until full
	{    r1=g1;
	r2=y-(g1-x);
	     if(search(r1,r2)==0)
	     {  add(i,r1,r2);
		insert(r1,r2);
		storenode(r1,r2);
	     }
	}

	if(x+y<g1 && y>0)  	//pour all water from 3 to 4
	{  r1=x+y;	r2=0;
	   if(r1==target)
	   {    add(i+1,r1,r2);
		return 1;
	   }
	   else
	   {   if(search(r1,r2)==0)
	       {      	add(i,r1,r2);
			insert(r1,r2);
			storenode(r1,r2);
	       }
	   }
	}

	if(x+y<g2 && x>0)
	{    r1=0;	r2=x+y;
	     if(search(r1,r2)==0)
	     {  add(i,r1,r2);
		insert(r1,r2);
		storenode(r1,r2);
	     }
	}
	return 0;
}


int main()
{
      int i,n1;
      int a=0;

      for(int k=0;k<20;k++)
      alist[k]=NULL;

      //clrscr();
      cout<<"\nEnter the capacities of 2 jugs and the amount of water to be measured";
      cin>>g1>>g2>>target;

      node *temp=NULL,*aux=NULL;

      insert(0,0);
      storenode(0,0);


      i=-1;
      while(front!=NULL && a!=1)
      { deleteq(&aux);
	i=i+1;
	add(i,aux->n1,aux->n2);
	a=findrulex(i,aux);
	if(a) break;
	a=findruley(i,aux);
	if(a) break;
	a=findrulexy(i,aux);
      }

      if(a)
      {	i++;
      cout<<endl<<"Solution Found:"<<endl;   }
      else
      cout<<endl<<"Cannot Find Solution."<<endl;

      n1=i;
      for(i=0;i<=n1 && a==1;i++)
      {  for(temp=alist[i];temp!=NULL;temp=temp->next)
	 cout<<"("<<temp->n1<<","<<temp->n2<<")->";
	 cout<<"NULL"<<endl<<endl;
	 getch();
      }
     getch();
     return 0;
}
