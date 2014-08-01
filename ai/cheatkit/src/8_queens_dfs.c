#include <stdio.h>
#include <stdlib.h>
int QUEENS = 8;
 
int is_safe(int rows[QUEENS], int x, int y)  
{
    int i;
 
    for (i=1; i <= y; ++i) 
	{
       if (rows[y-i] == x || rows[y-i] == x-i || rows[y-i] == x+i)
            return 0;
    }
 
    return 1;
}
 
void putboard(int rows[QUEENS])  
{
    static int s = 0;
    int x, y;
 
    printf("\nSolution #%d:\n---------------------------------\n", ++s);
    for (y=0; y < QUEENS; ++y) 
	{
        for (x=0; x < QUEENS; ++x)
            printf(x == rows[y] ? "| Q " : "|   ");
        printf("|\n---------------------------------\n");
    }
}
 
void eight_queens_helper(int rows[QUEENS], int y)
{
    int x;
 
    for (x=0; x < QUEENS; ++x) 
	{
        if (is_safe(rows, x, y)) 
		{
            rows[y] = x;
            if (y == 7)
              putboard(rows);
            else
              eight_queens_helper(rows, y+1);
        }
    }
}
 
int main(int argc, char * argv[])
{
	if(argc > 1)
		QUEENS = atoi(argv[1]);
    int rows[QUEENS];
 
    eight_queens_helper(rows, 0);
 
    return 0;
}