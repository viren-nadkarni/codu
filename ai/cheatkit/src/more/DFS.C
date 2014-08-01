#include<stdio.h>
#include<conio.h>
#include<malloc.h>
int *visited ,*G;
void dfs(int v,int n)
{
    int i,j,w;
    w=v;
    visited[v]=1;
    printf("%d\t",v);
    for(i=0;i<n;i++)
	{
	     for(j=0;j<n;j++)
	     {
		 w=*(G+v*n+i);
		 if(w==1)
		  {
		    w=i;
		    if(visited[w]==0)
			dfs(w,n);

		  }
	    }
	}
 }

 void main()
 {
  int i,n,k,m,e,v;
  clrscr();
  printf("\nEnter the no. of vertices:");
  scanf("%d",&n);
  G=(int*)calloc(sizeof(int),n*n);
  visited=(int *)calloc(sizeof(int),n);
  printf("\nEnter the no. of edges:");
  scanf("%d",&e);
  printf("\nEnter the adjacent vertices:");
  for(i=0;i<e;i++)
  {
    scanf("%d %d",&m,&k);
    *(G+m*n+k)=1;
  }
  printf("\nEnter the source vertex:");
  scanf("%d",&v);
  dfs(v,n);
  getch();
  }