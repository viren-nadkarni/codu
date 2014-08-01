#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define QUEENNO 8

void placequeen(int, int*);
int canbeplaced(int, int, int*);
void showboard(int*);

int main()
{

     int x[QUEENNO], i;

     printf("The 8 queens problem");
     placequeen(0, x);

     printf("End");
     getch();
     
     return 0;
}

void placequeen(int k, int *x)
{

     int i, j;
     char ch;

     for(i = 0; i < 8; i++)
     {
           if(canbeplaced(k, i, x))
           {
                     x[k] = i;
                     
                     if(k == 7)
                     {
                             showboard(x);
                             printf("\nMore Solutions?[n->stop, any-> continue]: ");
                             scanf(" %c ", &ch);
                             if(ch == 'n' || ch == 'N')
                             exit(0);
                     }
                     
                     if(k < 7)
                          placequeen(k + 1, x);
           }
     }

}


int canbeplaced(int k, int i, int *x)
{

           int j;
           
           for(j = 0; j < k; j++)
           {
                 if((abs(j - k) == abs(x[j] - i)) || (x[j] == i))
                 return 0;
           }

           return 1;
}


void showboard(int *x)
{

            int i, j;
            printf(" \n----------------------------------------------\n ");
            printf(" ");
            
            for(i = 0; i < 8; i++)
            {
                  printf(" %d ",(i + 1));
                  printf(" ");
            }

            for(i = 0; i < 8; i++)
            {
                  printf(" \n \n %d ",(i + 1));
                  for(j = 0; j < 8; j++)
                  {
                        if(j == x[i])
                             printf(" Q ");
                        else
                            printf(" - ");
                        
                        printf(" ");
                  }
            
                  printf(" ");

             }
             
             printf(" \n---------------------------------------------- ");
}
