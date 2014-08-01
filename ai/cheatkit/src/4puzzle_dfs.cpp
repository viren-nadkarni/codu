#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define LEFT -1
#define RIGHT 1

typedef struct tile
{
    char info[4];
    int pri;
    struct tile *left;
    struct tile *right;
    struct tile *parent;
}TILE;
//TILE *root=NULL;


char START[4]={'1','3','2','B'};
char GOAL[4]={'B','3','1','2'};

TILE * insert(TILE *root,char a[],int priority)
{
     TILE *p,*q,*par;
     int flag;
     p=(TILE *)malloc(sizeof(TILE));
           
     if(root == NULL)
     {
         root = p;
         root->info[0] = a[0];
         root->info[1] = a[1];
         root->info[2] = a[2];
         root->info[3] = a[3];
         root->pri=priority;
         root->left = NULL;
         root->right = NULL;
         root->parent=NULL;
     }
     else
     {
         q = root;
         do
         {
             par = q;
             flag = 0;
                    
             if(priority >= q->pri)
             {
                 q = q->right;
                 flag = RIGHT;
             }
             else
             {
                 q = q->left;
                 flag = LEFT;
             }
         }while(q != NULL);
               
         if(flag == LEFT)
         {
             par->left = p;
             p->info[0] = a[0];
             p->info[1] = a[1];
             p->info[2] = a[2];
             p->info[3] = a[3];
             p->pri=priority;
             p->left = NULL;
             p->right = NULL;
             p->parent=par;
         }
         if(flag == RIGHT)
         {
             par->right = p;
             p->info[0] = a[0];
             p->info[1] = a[1];
             p->info[2] = a[2];
             p->info[3] = a[3];
             p->pri=priority;
             p->left = NULL;
             p->right = NULL; 
             p->parent=par;
         }
     }
     //printf("in insert\n");
     return (root);
}

TILE* initialiserulelist(TILE *root)
{
     char a[4];
     int p;
     
     //1 {,'3','2','B'}
     a[0]='1';
     a[1]='3';
     a[2]='2';
     a[3]='B';
     p=5;
     root=insert(root,a,p);

     //2
     a[0]='1';
     a[1]='3';
     a[2]='B';
     a[3]='2';
     p=3;
     root=insert(root,a,p);
     
     //3
     a[0]='B';
     a[1]='3';
     a[2]='1';
     a[3]='2';
     p=1;
     root=insert(root,a,p);
     
     //4
     a[0]='1';
     a[1]='B';
     a[2]='2';
     a[3]='3';
     p=6;
     root=insert(root,a,p);
     
     //5
     a[0]='B';
     a[1]='1';
     a[2]='2';
     a[3]='3';
     p=7;
     root=insert(root,a,p);
     
     //6
     a[0]='2';
     a[1]='1';
     a[2]='B';
     a[3]='3';
     p=8;
     root=insert(root,a,p);
     
     //7
     a[0]='2';
     a[1]='1';
     a[2]='3';
     a[3]='B';
     p=9;
     root=insert(root,a,p);
     
     //8
     a[0]='2';
     a[1]='B';
     a[2]='3';
     a[3]='1';
     p=10;
     root=insert(root,a,p);
     
     //9
     a[0]='B';
     a[1]='2';
     a[2]='3';
     a[3]='1';
     p=11;
     root=insert(root,a,p);
     
     //10
     a[0]='3';
     a[1]='2';
     a[2]='B';
     a[3]='1';
     p=12;
     root=insert(root,a,p);
     
     //11
     a[0]='3';
     a[1]='2';
     a[2]='1';
     a[3]='B';
     p=13;
     root=insert(root,a,p);
     
     //12
     a[0]='3';
     a[1]='B';
     a[2]='1';
     a[3]='2';
     p=14;
     root=insert(root,a,p);
     
     //13
     a[0]='B';
     a[1]='3';
     a[2]='1';
     a[3]='2';
     p=15;
     root=insert(root,a,p);
     
     return(root);
}

void dfs(TILE *root)
{
      if(root != NULL)
     {
                dfs(root->left);
                if(root->info[0] == GOAL[0] && root->info[1] == GOAL[1] && root->info[2] == GOAL[2] && root->info[3] == GOAL[3])
                {
                    printf("\n%c|%c\n---\n%c|%c\n",root->info[0],root->info[1],root->info[2],root->info[3]);
                    printf("\nSolution Found\n");
                    return;
                } 
                else
                printf("\n%c|%c\n---\n%c|%c\n",root->info[0],root->info[1],root->info[2],root->info[3]);
                dfs(root->right);
     }
     
}

void dfsp(TILE *root)
{
      if(root != NULL)
     {
                if(root->info[0] == GOAL[0] && root->info[1] == GOAL[1] && root->info[2] == GOAL[2] && root->info[3] == GOAL[3])
                {
                    printf("\n%c|%c\n---\n%c|%c\n",root->info[0],root->info[1],root->info[2],root->info[3]);
                    printf("\nSolution Found\n");
                    return;
                } 
                else
                printf("\n%c|%c\n---\n%c|%c\n",root->info[0],root->info[1],root->info[2],root->info[3]);
                
                dfsp(root->left);
                dfsp(root->right);
     }
     
}


int main()
{
    TILE *root=NULL,*p;
    root=initialiserulelist(root);
    dfsp(root);
    getch();
}
