#include<stdio.h>
#include<conio.h>

void init(int x[9][9],int ansr[9][9])
{
     int i,j;
     
     ansr[0][0] = 9;
     ansr[0][1] = 1;     
     ansr[0][2] = 7;     
     ansr[0][3] = 5;     
     ansr[0][4] = 4;     
     ansr[0][5] = 8;     
     ansr[0][6] = 2;     
     ansr[0][7] = 3;     
     ansr[0][8] = 6;          
     
     ansr[1][0] = 4;     
     ansr[1][1] = 2;     
     ansr[1][2] = 6;     
     ansr[1][3] = 7;     
     ansr[1][4] = 9;     
     ansr[1][5] = 3;     
     ansr[1][6] = 1;     
     ansr[1][7] = 8;     
     ansr[1][8] = 5;     
     
     ansr[2][0] = 3;     
     ansr[2][1] = 8;     
     ansr[2][2] = 5;     
     ansr[2][3] = 1;     
     ansr[2][4] = 6;     
     ansr[2][5] = 2;     
     ansr[2][6] = 9;     
     ansr[2][7] = 4;     
     ansr[2][8] = 7;     
     
     ansr[3][0] = 8;     
     ansr[3][1] = 4;     
     ansr[3][2] = 3;     
     ansr[3][3] = 6;     
     ansr[3][4] = 5;     
     ansr[3][5] = 1;     
     ansr[3][6] = 7;     
     ansr[3][7] = 2;     
     ansr[3][8] = 9;     
     
     ansr[4][0] = 2;     
     ansr[4][1] = 6;     
     ansr[4][2] = 9;     
     ansr[4][3] = 4;     
     ansr[4][4] = 3;     
     ansr[4][5] = 7;     
     ansr[4][6] = 5;     
     ansr[4][7] = 1;     
     ansr[4][8] = 8;     
     
     ansr[5][0] = 5;     
     ansr[5][1] = 7;     
     ansr[5][2] = 1;     
     ansr[5][3] = 2;     
     ansr[5][4] = 8;     
     ansr[5][5] = 9;     
     ansr[5][6] = 3;     
     ansr[5][7] = 6;     
     ansr[5][8] = 4;     
     
     ansr[6][0] = 1;     
     ansr[6][1] = 5;     
     ansr[6][2] = 4;     
     ansr[6][3] = 3;     
     ansr[6][4] = 7;     
     ansr[6][5] = 6;     
     ansr[6][6] = 8;     
     ansr[6][7] = 9;     
     ansr[6][8] = 2;     
     
     ansr[7][0] = 7;     
     ansr[7][1] = 9;     
     ansr[7][2] = 2;     
     ansr[7][3] = 8;     
     ansr[7][4] = 1;     
     ansr[7][5] = 4;     
     ansr[7][6] = 6;     
     ansr[7][7] = 5;     
     ansr[7][8] = 3;     
     
     ansr[8][0] = 6;     
     ansr[8][1] = 3;     
     ansr[8][2] = 8;     
     ansr[8][3] = 9;     
     ansr[8][4] = 2;     
     ansr[8][5] = 5;     
     ansr[8][6] = 4;     
     ansr[8][7] = 7;     
     ansr[8][8] = 1;     
     
     for(i = 0;i < 9;i++)
       for(j = 0;j < 9;j++)
         x[i][j] = 0;
     
}

void print(int x[9][9],int ansr[9][9])
{
     int i,j;
     
     printf("\n\nAnswer: \n");     
     
     for(i = 0;i < 9;i++)
     {  
           for(j = 0;j < 9;j++)
             printf("%d ",ansr[i][j]); 
     
           printf("\n");
     }  
     
     printf("\n\n\n");
     
     printf("\n\nSolution: \n");     
     
     for(i = 0;i < 9;i++)
     {  
           for(j = 0;j < 9;j++)
             printf("%d ",x[i][j]); 
     
           printf("\n");
     }  
     
}

void printx(int x[9][9])
{
     int i,j;
     
     printf("\n\nGrid so far: \n");     
     
     for(i = 0;i < 9;i++)
     {  
           for(j = 0;j < 9;j++)
             printf("%d ",x[i][j]); 
     
           printf("\n");
     }  
     
     
}

void printansr(int ansr[9][9])
{
     int i,j;
     
     printf("\n\nAnswer: \n");     
     
     for(i = 0;i < 9;i++)
     {  
           for(j = 0;j < 9;j++)
             printf("%d ",ansr[i][j]); 
     
           printf("\n");
     }  
     
     
}



void step_sol(int x[9][9],int ansr[9][9])
{
     int r,c,val,i,j,cont,ans;
     
     do
     {
                  printf("\nEnter Row: ");     
                  scanf("%d",&r);
                  printf("\nEnter Column: ");
                  scanf("%d",&c);
     
                  r--;
                  c--;
     
                  printf("\nEnter Value: ");
                  scanf("%d",&val);
     
                  if(val == ansr[r][c])
                  {
                         printf("\nCorrect Choice!");
                         x[r][c] = val;       
                  }
                  else
                  {
                         printf("\nWrong Choice!");    
                  }
     
                  printx(x);
                  
                  printf("\n\nContinue? (1/0):  ");
                  scanf("%d",&cont);
     
     }while(cont);
     
     for(i = 0;i < 9;i++)
       for(j = 0;j < 9;j++)
       {
             if(x[i][j] != ansr[i][j])      
             { 
                        printf("\n\nWrong Solution!\n");
                        print(x,ansr);
                        exit(1);
             }
       }        
                 
      printf("\n\nCorrect Solution!\n");           
      printf("\n\n");
      
      printf("Reveal Answer? (1/0): ");
      scanf("%d",&ans);
      if(ans == 1)
      {
             printansr(ansr);         
      }
      
}//end function


void full_sol(int x[9][9],int ansr[9][9])
{
     int i,j;
     
     printf("\n\nEnter the full matrix: \n");     
     
     for(i = 0;i < 9;i++)
       for(j = 0;j < 9;j++)
         scanf("%d",&x[i][j]);      
                 
     for(i = 0;i < 9;i++)
       for(j = 0;j < 9;j++)
       {
             if(x[i][j] != ansr[i][j])      
             { 
                        printf("\n\nWrong Solution!\n");
                        print(x,ansr);
                        exit(1);
             }
       }        
                 
      printf("\n\nCorrect Solution!\n");           
      printf("\n\n");
      print(x,ansr);         
}

void display_puzzle(int x[9][9])
{
     x[0][2] = 7;     
     x[0][3] = 5;
     x[0][6] = 2;
     x[0][7] = 3;
     
     x[1][0] = 4;
     x[1][2] = 6;
     x[1][3] = 7;
     x[1][7] = 8;
     x[1][8] = 5;
     
     x[2][0] = 3;
     x[2][4] = 6;
     x[2][5] = 2;
     x[2][8] = 7;
     
     x[3][2] = 3;
     x[3][3] = 6;
     x[3][4] = 5;
     x[3][7] = 2;
     
     x[4][1] = 6;
     x[4][2] = 9;
     x[4][6] = 5;
     x[4][7] = 1;
     
     x[5][1] = 7;
     x[5][4] = 8;
     x[5][5] = 9;
     x[5][6] = 3;
     
     x[6][0] = 1;
     x[6][3] = 3;
     x[6][4] = 7;
     x[6][8] = 2;
     
     x[7][0] = 7;
     x[7][1] = 9;
     x[7][5] = 4;
     x[7][6] = 6;
     x[7][8] = 3;
     
     x[8][1] = 3;
     x[8][2] = 8;
     x[8][5] = 5;
     x[8][6] = 4;
     
     int i,j;
     
     printf("\n\nPuzzle: \n");     
     
     for(i = 0;i < 9;i++)
     {  
           for(j = 0;j < 9;j++)
             printf("%d ",x[i][j]); 
     
           printf("\n");
     }  
     
}


int main()
{
    int x[9][9],ansr[9][9];
    int choice;
    
    init(x,ansr);
    display_puzzle(x);
    
    printf("\nChoose mode: \n");
    printf("Enter full solution -> Press 1\n");
    printf("Enter each cell and check -> Press 2\n");
    scanf("%d",&choice);
    
    switch(choice)
    {
                  case 1:
                         full_sol(x,ansr);
                         break;
                  case 2:
                         step_sol(x,ansr);
                         break;
                  default:
                          printf("\nInvalid Choice!\n");
    }//end switch       
                                    
    getch();
    getch();    
    
    return 0;
}
