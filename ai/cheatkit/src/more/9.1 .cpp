#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>


typedef struct graph
{
   int cost[10],flag;
}gnode;
gnode  g[10];

int tour[10];
int no=0;
int n;

int check(int x,int tour[10],int no)
{
  if(x==0)
   return 0;

  for(int i=0;i<no;i++)
    {
      if(x==tour[i])
	return 1;
    }

return 0;
}

int check1(int x,int tour[10],int no)
{

  for(int i=0;i<no;i++)
    {
      if(x==tour[i])
	return 1;
    }

return 0;
}

int present(int tour[10],int no,int n)
{

int cnt=0;
if(no==n)
{
 for(int i=0;i<no;i++)
   {
     for(int j=0;j<n;j++)
       {
	 if(tour[i]==j)
	   cnt=cnt+1;
       }
    }
 if(cnt==n)
   return 1;
}
return 0;
}

int tsp()
{
 int i,min,loc,j,mincost=0;
  cout<<"\nEnter the number of vertices:";
  cin>>n;
  for(i=0;i<n;i++)
   for(j=0;j<n;j++)
    {
      cout<<"a["<<i<<"]["<<j<<"]=";cin>>g[i].cost[j];
      cout<<endl;
     }
  for(i=0;i<n;i++)
   for(j=0;j<n;j++)
      {
	 if(i==j)
	   g[i].cost[j]=99;
       }
 i=0;j=0;
 tour[no]=j;
   no++;


 do
 {
//  if(check(i,tour,no)==0)
   {
      min=g[i].cost[i];
      loc=0;
     for(j=0;j<n;j++)
      {
	if(check1(j,tour,no)==0)
	{
	 if(min>g[i].cost[j] && j!=i)
	     {
	       min=g[i].cost[j];
	       loc=j;
	     }
	 }
      }
     mincost+=min;
     tour[no]=loc;
     no++;
     if(present(tour,no,n)==1)
	   {
	   mincost+=g[loc].cost[0];
	   return mincost;  }
   }
     i=loc;
 }while(1);
}


void main()
{
  int mincost;
  clrscr();
  mincost=tsp();
  clrscr();
  cout<<"\n\t\tLENGTH MATRIX\n\n\n";
   for(int i=0;i<n;i++)
    {
     cout<<" [ ";
      for(int j=0;j<n;j++)
       {
	 if(i==j)
	   cout<<"\t"<<"0";
	 else
	   cout<<"\t"<<g[i].cost[j];
	}
     cout<<"\t]"<<endl;
    }
  cout<<"\n\n\n\n\t\tSHORTEST PATH\n\n\n";
   for( i=0;i<no;i++)
     cout<<"CITY "<<tour[i]<<" -> ";
   cout<<"CITY 0";
  cout<<"\n\n\n\n\t\tCost of the tour: ";
  cout<<mincost;
  getch();
}
