//N-Queen's Problem

#include <iostream.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

void check(int, int, char [100][100]);
void print(char [100][100]);

int no_of_queens, queen = 2, flagrow = 0, flagcol = 0;
int count = 1;
char ch, response_row, response_col;

int main(void)
{
   int row, col, i;
   char board[100][100], response;
   clrscr();
   printf("

@@    This is n-queen problem.
Enter the number of
queens(say n) 
and watch how computer places them 
in (n x n) matrix
such that none can 
meet another moving along horizontally, 
vertically
or digonally.

");
   printf("
Enter the number of queens : ");
   scanf("%d", &no_of_queens);
   if(no_of_queens > 23)
   {
      printf("

@@    Thought the program is OK 
for any queen value.But
due the 
configuration of the output screen 
the output will be
tranketed 
(A very large queen number may cause 
the system stack
overflow).
So it is highly 
recommended that you run the program 
with
maximum queen number 23...");
      printf("

Want to continue(Y/N)?");
      fflush(stdin);
      scanf("%c", &response);
      if(toupper(response) == 'N')
         return (0);
   }
   else if(no_of_queens < 3)
   {
      printf("The number of Queen must be greater than 3.");
      getch();
      return (0);
   }

   printf("Want a row number below the board(Y/N) : ");
   fflush(stdin);
   response_row = (char)getchar();
   if(toupper(response_row) == 'Y')
      flagrow = 1;
   printf("Want a column number below the board(Y/N) : ");
   fflush(stdin);
   response_col = (char)getchar();
   if(toupper(response_col) == 'Y')
      flagcol = 1;

   clrscr();
   printf("M/c in work ! Please Wait...");

   // This for-loop is used for checking all the columns of row 0 only...
   _setcursortype(_NOCURSOR);
   for(col = 0; col < no_of_queens; col++)
   {
      memset(board, '-', sizeof(board));
      check( 0, col, board );
   }
   clrscr();
   printf("Thank you for seeing this program through.");
   getch();
   return (0);
}

void check( int r, int c, char board[100][100] )
{
   int i, j;

   // Terminating condition for the recursion...
   if ( ( r == no_of_queens )  && ( c == 0 ))
   {
      clrscr();
      printf(" (%d-Queen) Set : %d 
", no_of_queens, count++);
      print( board );
      fflush(stdin);
      ch = (char)getch();
      clrscr();
      if(ch == 'e')
         exit (0);
      printf("M/c in work ! Please Wait...");
   }

   // Vertical check...
   for(i = 0; i < r; i++)
   {
      if ( board[i][c] == queen)
         return;
   }

   // Horizontal check...
   for(j = 0; j < c; j++)
   {
      if ( board[r][j] == queen)
         return;
   }

   // Left-Diagonal check...
   i = r; j = c;
   do
   {
      if ( board[i][j] == queen )
         return;
      i--; j--;
   }
   while( i >= 0 && j >= 0 );

   // Right-Diagonal check...
   i = r; j = c;
   do
   {
      if ( board[i][j] == queen )
         return;
      i--; j++;
   }
   while( i >= 0 && j < no_of_queens );

   // Placing the queen if the ckecked position is OK...
   board[r][c] = queen;
   r++;

   // This for-loop is used for checking all the columns for each row
   //starting from 1 upto the end...
   for(int p = 0; p < no_of_queens; p++)
      check(r, p, board);
   for(int h = 0; h < no_of_queens; h++)
      board[r - 1][h] = '-';


}

void print(char board[100][100])
{

   for(int i = 0; i < no_of_queens; i++)
   {
      if(flagrow == 1)
         printf("%3d", i + 1);

      for(int j = 0; j < no_of_queens; j++)
      {
         if(board[i][j] == queen)
         {
            textcolor(RED);
            cprintf("%3c", queen);
         }
         else
         {
            textcolor(8); //dark gray
            cprintf("%3c", 22);
         }
      }
      printf("
");
   }
   textcolor(7);
   if(flagcol == 1)
   {
      if(flagrow)
         printf("   ");
      for(i = 0; i < no_of_queens; i++)
         printf("%3d", i + 1);
   }

   gotoxy(62, 1);
   printf("Press E to exit.");
   textcolor(7);
}
