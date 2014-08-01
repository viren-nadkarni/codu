//tsp nearest neigbour
#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 100

int **cost,n,s,visited[20],*h,o,*travel,c;

void input()
{
cout<<"Enter the no of cities:";
cin>>n;
h=(int*)malloc(sizeof(int)*n);
travel=(int*)malloc(sizeof(int)*n);
*cost=(int*)malloc(sizeof(int)*n);
for(int i=0;i<n;i++)
cost[i]=(int*)malloc(sizeof(int)*n);
cout<<"\nEnter the cost matrix:"; //-1 if der is no edge
for(i=0;i<n;i++)
{	visited[i]=0;
	for(int j=0;j<n;j++)
	{
	 if(i!=j)
	  { cout<<"Cost["<<i<<"]["<<j<<"]";
	  cin>>cost[i][j];
	  }
	 }
}

cout<<"\nEnter the starting city(0-"<<n-1<<":";
cin>>s;
visited[s]=1;
}
void heuristic(int k)
{
int min=9999;
		for(int j=0;j<n;j++)
		{
			if(cost[k][j]<min && j!=k && visited[j]==0&&cost[k][j]!=-1)
			{
			min=cost[k][j];
			h[k]=j;
			}
		}


}

void display_path()
{
int i,j;
cout<<"\n";
c=cost[s][h[s]];
j=h[s]  ;

for(i=1;i<n-1;i++)
{
c+=cost[j][h[j]];
j=h[j];
}
c+=cost[j][s];
cout<<"COST MATRIX"<<endl;
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
if(i!= j)
cout<<cost[i][j]<<"\t"  ;
else
cout<<"0\t" ;
}
cout<<endl;
}
	for( i=0;i<o;i++)
		   cout<<travel[i]<<" -> ";
	 cout<<s<<endl;


cout<<"travelling cost"<<c
;
}
void TSP()
{

       //	for(int i=0;i<n;i++)
       //	heuristic(i);
      int	i=s;
	o=0;
	heuristic(i);
	travel[o++]=s;
	while(o!=n)
	{
		visited[h[i]]=1;
		heuristic(h[i]);
		i=h[i];
		travel[o++]=i;
	}


}

void main()
{
clrscr();
input();
TSP();
display_path();
getch();
}


