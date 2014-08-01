#include <stdio.h>
//#include <conio.h>

/*

{
0,1,1,1,1,1,0,1,0,1,
0,1,0,0,0,0,1,1,0,1,
0,0,0,1,1,0,1,0,0,1,
1,1,1,1,1,0,1,1,0,1,
0,1,0,1,1,0,1,0,0,1,
0,0,1,1,0,0,1,1,1,0,
1,1,0,1,0,1,0,0,1,1,
1,1,1,0,0,1,0,1,0,1,
1,0,1,0,1,1,1,1,1,1,
1,0,1,0,0,0,0,0,0,0
}
			 
{
0,1,1,1,1,1,0,1,0,1,
0,1,0,0,1,0,1,1,0,1,
0,1,0,1,1,0,1,0,0,1,
0,1,0,1,1,0,1,1,0,1,
0,1,0,1,1,0,1,0,0,1,
0,1,0,1,0,0,1,1,1,0,
0,1,0,1,0,1,0,0,1,1,
0,1,1,0,0,1,0,1,0,1,
0,1,1,1,1,1,1,1,1,1,
0,0,0,0,0,0,0,0,0,0
}
			 
*/

static int path[100][2], count=0, maze[10][10]={0,1,1,1,1,1,0,1,0,1,
												0,1,0,0,0,0,0,1,0,1,
												0,0,0,1,1,0,1,0,0,1,
												1,1,1,1,1,0,1,1,0,1,
												0,1,0,1,1,0,1,0,0,1,
												0,0,0,1,0,0,1,1,1,0,
												1,1,0,1,0,1,0,0,1,1,
												1,1,0,0,0,1,0,1,0,1,
												1,0,1,0,1,1,1,1,1,1,
												1,0,1,0,0,0,0,0,0,0};

int solve(int, int, int, int);
int solve(int i, int j, int m, int n)
{
	if(i==9 && j==9)						//trivial condition
		return (1);	
	
	else if(i>9 || j>9)						//no solution
		return (0);

	int w=0,x=0,y=0,z=0;

	if(i-1>=0 && j-1>=0)					//condition check for moving from 0 0
	{
		if(maze[i-1][j]==0 && (i-1!=m) )	//move north
			w=solve(i-1,j,i,j);
		if(maze[i][j-1]==0 && (j-1!=n))		//move west
			x=solve(i,j-1,i,j);
	}
	
	if(maze[i+1][j]==0 && (i+1!=m))			//move south
		y=solve(i+1,j,i,j);
	
	if(maze[i][j+1]==0 && (j+1!=n))			//move east
		z=solve(i,j+1,i,j);
		
	if(w || x || y || z)	
	{
		path[count][0]=i;
		path[count][1]=j;		
		count++;
		return (1);
	}
	else 
		return (0);
}

int main()
{
	int i=0,j=0;

	if(solve(i,j,0,0))
	{
		printf("Follow the coordinates from 0 0 to 9 9: \n");
		for(i=count-1;i>=0;--i)
			printf("%d %d\n", path[i][0], path[i][1]);
	}
	else
		printf("No solution was found\n");

	//getch();
	return 0;
}
