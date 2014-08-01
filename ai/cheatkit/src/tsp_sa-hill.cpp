#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define V 5       //Given 5 vertices
#define TRUE 1
#define FALSE 0

typedef struct node* NODEPTR;

struct node
{      int city;
       struct node *next;
};

int check[V]={1,1,1,1,1};    //to check whether the node was visited

void insend(NODEPTR *plist,int pos)
{
     NODEPTR a,b;
     a=(NODEPTR)malloc(sizeof(struct node));
     a->city=pos;
     a->next=NULL;
     if (*plist==NULL)
        *plist=a;
     else
     {
         for (b=*plist;b->next!=NULL;b=b->next);
         b->next=a;
     }
     
     return;
}

int checknext(bool g[V][V],int w[V][V],int current)
{   int val=9999,i,temp;  //some maximum value
    for (i=0;i<V;i++)
    {   if (g[current][i]==1 &&  w[current][i]<val && check[i]==TRUE)
        {   val=w[current][i];
            temp=i;
        }
    }

    check[temp]=FALSE;
    return temp;
}

int main()
{   NODEPTR list=NULL,b;
    int succ,count=0,init=0;      //Assume salesman to be initially at A
    bool graph[V][V]={{0, 1, 1, 1, 1},
         {1, 0, 1, 1, 1},
         {1, 1, 0, 1, 1},
         {1, 1, 1, 0, 1},
         {1, 1, 1, 1, 0},
         };
    int wt[V][V]={{0, 100, 300, 100, 75},
         {100, 0, 50, 75, 125},
         {300, 50, 0, 100, 125},
         {100, 75, 100, 0, 50},
         {75, 125, 125, 50, 0},
         };
         
    insend(&list,init);
    check[0]=FALSE;   
    while (count<5)
    {
          succ=checknext(graph,wt,init);
          insend(&list,succ);
          init=succ;
          count++;
    }
    
    printf("\tTRAVELLING SALESPERSON PROBLEM\n"
           "\t= = = = = = = = = = = = = = = =\n\nSolution Found\n");
           
    for (b=list;b->next!=NULL;b=b->next)
    {   switch (b->city)
        {      case 0:printf("A -> ");break;
               case 1:printf("B -> ");break;
               case 2:printf("C -> ");break;
               case 3:printf("D -> ");break;
               case 4:printf("E -> ");break;
        }
    }
    printf("A");    //Back to initial position
    getch();
    return 0;
}
