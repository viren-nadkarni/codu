#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void shortestpath(int *,int);
int min(int a,int b);
void main()
{
	int *cost;
	char y='y';
	int n,i,j;
	printf("\nEnter the no. of nodes:");
	scanf("%d",&n);
	cost=(int*)malloc(sizeof(int)*n*n);
    for(i=0;i<n;i++)
	{
      for(j=0;j<n;j++)
	  {
	   if(i==j)
	   	*(cost+n*i+j)=0;
	   else
		*(cost+n*i+j)=9999;
	  }
	}
	printf("\nEnter the cost matrix:");
    while(y=='y')
	{
	 printf("\nEnter the adjacent vertices:");
	 scanf("%d %d",&i,&j);
	 printf("\nEnter the weight associated:");
	 scanf("%d",(cost+n*i+j));
     printf("\nDo you want to continue (y/n):");
	 y=getch();
	}
    for(i=0;i<n;i++)
	{
		printf("\n");
        for(j=0;j<n;j++)
		{
	     printf("\t%d",*(cost+n*i+j));
		}
	}
    shortestpath(cost,n);
    getch();
}
int min(int a,int b)
{
	if(a<b)
		return(a);
	else
		return(b);
}
void shortestpath(int *cost,int n)
{
   int *s,i,*dist,*t,mincost,k=1,u,z;
   s=(int*)malloc(sizeof(int)*n);
   t=(int*)malloc(sizeof(int)*n);
   
   for(i=0;i<n;i++)
     s[i]=0;
   dist=(int*)malloc(sizeof(int)*n);
   t[0]=0;
   s[0]=1;
   dist[0]=0;
   mincost=*(cost+1);
   u=1;
   for(i=1;i<=n;i++)
   {
	if(mincost>*(cost+i))
	{
		mincost=*(cost+i);
		u=i;
	}
	dist[i]=*(cost+i);
   }
   t[1]=u;
   s[u]=1;
   do
   {
 	for(i=0;i<n;i++)
      if(s[i]!=1)
	  {
        z=*(cost+n*t[k]+i);
	    dist[i]=min(dist[i],dist[t[k]]+z);
	  }
    for(i=0;i<n;i++)
	{
	  if(s[i]!=1)
		mincost=*(dist+i);
	}
    for(i=0;i<n;i++)
	{
	  if((s[i]!=1)&&(mincost>=dist[i]))
	  {
		mincost=dist[i];
		u=i;
	  } 
	}
   k++;
   s[u]=1;
   *(t+k)=u;
   }while(k<n-1);
   printf("\nThe shortest path:");
   for(i=0;i<n;i++)
	printf(" %d",t[i]+1);
}