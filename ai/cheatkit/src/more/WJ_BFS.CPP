#include<stdio.h>
#include<conio.h>
#include<iostream.h>
#include<stdlib.h>

struct node
{
 int jug1;
 int jug2;
 struct node *link;
};

node *start;
node *array[1000];

void display ( node *t )
{
 int a[100][2];
 int i = 0;

 cout<<"\n\n The Solution is : ";
 cout<<"\n\n    Jug 1      Jug 2  ";

 do
  {
   if ( t -> link == NULL )
      break;
   a[i][0] = t -> jug1;
   a[i][1] = t -> jug2;
   t = t -> link;
   i++;
  }while ( t != NULL );

 for ( int j = i-1 ; j >= 0 ; j-- )
   cout<<"\n\n    "<<a[j][0]<<"          "<<a[j][1];

 getch();
 exit(0);

}

int check ( int p , int q , int n )
{
 int i;

 for ( i = 0 ; i < n ; i++ )
  {
   if ( array[i] -> jug1 == p && array[i] -> jug2 == q )
     return 0;
  }

 return 1;
}

void WJ_BFS ( int p , int q , int r )
{
 int i = 0 , j = 0;

 start = ( struct node* ) malloc ( sizeof ( struct node ) );

 start -> jug1 = 0;
 start -> jug2 = 0;
 start -> link = NULL;

 node *curr = start , *temp;
 array[i++] = start;

 while ( curr -> jug1 != r || curr -> jug2 != r )
  {
    if ( j >= i )
      break;

    // fill jug 1
    temp = ( struct node* ) malloc ( sizeof ( struct node ) );
    temp -> jug1 = p;
    temp -> jug2 = curr -> jug2;
    if ( check( temp -> jug1 , temp -> jug2 , i ) )
     {
       temp -> link = curr;
       array[i++] = temp;
       if ( temp -> jug1 == r )
	  display(temp);
     }
    else
     free(temp);


    // fill jug 2
    temp = ( struct node* ) malloc ( sizeof ( struct node ) );
    temp -> jug2 = q;
    temp -> jug1 = curr -> jug1;
    if ( check( temp -> jug1 , temp -> jug2 , i ) )
     {
       temp -> link = curr;
       array[i++] = temp;
       if ( temp -> jug2 == r )
	  display(temp);
     }
    else
     free(temp);


    // empty jug 1
    temp = ( struct node* ) malloc ( sizeof ( struct node ) );
    temp -> jug1 = 0;
    temp -> jug2 = curr -> jug2;
    if ( check( temp -> jug1 , temp -> jug2 , i ) )
     {
       temp -> link = curr;
       array[i++] = temp;
       if ( temp -> jug1 == r )
	  display(temp);
     }
    else
     free(temp);


    // empty jug 2
    temp = ( struct node* ) malloc ( sizeof ( struct node ) );
    temp -> jug2 = 0;
    temp -> jug1 = curr -> jug1;
    if ( check( temp -> jug1 , temp -> jug2 , i ) )
     {
       temp -> link = curr;
       array[i++] = temp;
       if ( temp -> jug2 == r )
	  display(temp);
     }
    else
     free(temp);


    // empty jug 1 in jug 2 till jug 2 is full or jug 1 is empty
    temp = ( struct node* ) malloc ( sizeof ( struct node ) );
    if ( curr -> jug1 <= q - curr -> jug2 )
      {
	temp -> jug2 = curr -> jug1 + curr -> jug2;
	temp -> jug1 = 0;
      }
    else
      {
	temp -> jug1 = curr -> jug1 - ( q - curr -> jug2 );
	temp -> jug2 = q;
      }

    if ( check( temp -> jug1 , temp -> jug2 , i ) )
     {
       temp -> link = curr;
       array[i++] = temp;
       if ( temp -> jug1 == r || temp -> jug2 == r)
	  display(temp);
     }
    else
     free(temp);


    // empty jug 2 in jug 1 till jug 1 is full or jug 2 is empty
    temp = ( struct node* ) malloc ( sizeof ( struct node ) );
    if ( curr -> jug2 <= p - curr -> jug1 )
      {
	temp -> jug1 = curr -> jug1 + curr -> jug2;
	temp -> jug2 = 0;
      }
    else
      {
	temp -> jug2 = curr -> jug2 - ( p - curr -> jug1 );
	temp -> jug1 = p;
      }

    if ( check( temp -> jug1 , temp -> jug2 , i ) )
     {
       temp -> link = curr;
       array[i++] = temp;
       if ( temp -> jug1 == r || temp -> jug2 == r)
	  display(temp);
     }
    else
     free(temp);


    curr = array[j++];

  }

 if (  curr -> jug1 == r || curr -> jug2 == r )
    display(curr);
 else
   cout<<"\n\n No Solution ";

 getch();
 exit(0);

}

void main()
{
 clrscr();

 int j1;
 int j2;
 int req;

 cout<<"\n\n Enter the capacity of jug 1 : ";
 cin>>j1;

 cout<<"\n\n Enter the capacity of jug 2 : ";
 cin>>j2;

 cout<<"\n\n Enter the capacity of water required : ";
 cin>>req;

 WJ_BFS(j1,j2,req);
}