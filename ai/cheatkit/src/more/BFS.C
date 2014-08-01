#include<stdio.h>
#include<malloc.h>
#define true 1
#include<conio.h>
int *visited,*G;
struct queue
{
int a[10];
    int front;
    int rear;
}que;
void add(struct queue *q,int x)
{
	 if(q->rear<9)
	 {
		 q->rear++;
	 q->a[q->rear]=x;
	 }
}
int deleteq(struct queue *q)
{
	int info;
    if(q->rear<q->front)
	{
		return -1;
	}
    info=q->a[q->front];
    q->a[q->front]=0;
    q->front++;
    return info;
}

int isempty(struct queue *q)
{
	if(q->rear<q->front)
		return -1;
    else
	  return 0;
}

void bfs(int v,int n)
{
	int i,j,u,w,q;
    u=v;
    visited[v]=1;
    printf("\t%d",u);
    do
	{
		for(i=0;i<n;i++)
		{
		 for(j=0;j<n;j++)
		 {
			w=*(G+u*n+i);
			    if(w==1)
			{
		   w=i;
		if(visited[w]==0)
			   {
				   add(&que,w);
		       visited[w]=1;
		       printf("\t%d",w);
			   }
			}
		 }
		}
	q=isempty(&que);
	if(q!=0)
	return;
	u=deleteq(&que);
	}while(true);
}
void main()
{
    int i,n,e,v,k,m;
    clrscr();
    que.front=0;
    que.rear=-1;
    printf("\nEnter the no. of vertices:");
    scanf("%d",&n);
    G=(int*)calloc(sizeof(int),n*n);
    visited=(int *)calloc(sizeof(int),n);
    printf("\nEnter the no.of edges:");
    scanf("%d",&e);
    printf("\nEnter the adjacent vertices:");
    for(i=0;i<e;i++)
    {
		scanf("%d %d",&m,&k);
	*(G+m*n+k)=1;
	}
    printf("\nEnter a source vertex:");
    scanf("%d",&v);
    bfs(v,n);    
getch();
}





