#include<stdio.h>
#include<conio.h>
 
#define V 8         // Number of vertices in the graph
 
void printSolution(int color[]);
 
bool isSafe (int v, bool graph[V][V], int color[], int c)
{
    for (int i = 0; i < V; i++)
        if (graph[v][i] && c == color[i])
            return false;
    return true;
}

bool graphColoringUtil(bool graph[V][V], int m, int color[], int v)
{
    if (v == V)
        return true;

    for (int c = 1; c <= m; c++)
    {
        if (isSafe(v, graph, color, c))
        {
           color[v] = c;
 
           if (graphColoringUtil (graph, m, color, v+1) == true)
             return true;
 
           color[v] = 0;
        }
    }
 
    return false;
}
 
bool graphColoring(bool graph[V][V], int m)
{
    // Initialize all color values as 0
    int *color = new int[V];
    for (int i = 0; i < V; i++)
       color[i] = 0;
    
    color[6]=1; //Initially colored RED; As given in the problem definition
    color[7]=2; //Initially colored GREEN; As given in the problem definition
    
    if ( graphColoringUtil(graph, m, color, 0) == false )
    {
      printf("Solution does not exist");
      return false;
    }
 
    printSolution(color);
    return true;
}
 
void printSolution(int color[])
{
    printf ("\t````````````````````````````````````"
    "`````````\n\t\tSOLUTION EXITS\n\t\t--------------\n");
    
    for (int i = 0; i < V; i++)
    {   if (color[i]==1)
           printf("VERTEX V%d = RED\n\n",i+1);
        else if (color[i]==2)
           printf("VERTEX V%d = GREEN\n\n",i+1);
        else
           printf("VERTEX V%d = BLUE\n\n",i+1);
    }
}
 
int main()
{
    printf(" \tGRAPH COLORING USING CONSTRAINT SATISFACTION \n\n");
    bool graph[V][V] = {{0, 0, 0, 0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1, 1, 0, 0},
        {0, 1, 0, 1, 0, 1, 0, 0},
        {0, 0, 1, 0, 0, 1, 0, 1},
        {1, 1, 0, 0, 0, 1, 0, 1},
        {0, 1, 1, 1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1, 0, 0, 1},
        {0, 0, 0, 1, 1, 1, 1, 0},
    };
    int m = 3; // Number of colors R,G,B
    graphColoring (graph, m);
    
    getch();
    return 0;
}
