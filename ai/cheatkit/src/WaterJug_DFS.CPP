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
int p,q,r,i;

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

void WJ_BFS (node *start)
{   node *temp,*curr;
   curr=start;
     i++;

   if(start->jug1==r||start->jug2==r)
   {
   printf("\n\nsol found");
   exit(0);
   }





    // fill jug 1
    temp = ( struct node* ) malloc ( sizeof ( struct node ) );
    temp -> jug1 = p;
    temp -> jug2 = curr -> jug2;
    if ( check( temp -> jug1 , temp -> jug2 , i ) )
     {
      // temp -> link = curr;
      array[i++] = temp;
      // if ( temp -> jug1 == r )
      printf("\n\n%d %d",temp->jug1,temp->jug2);
      start->link=temp;


      WJ_BFS(temp);
     }
    else
     free(temp);


    // fill jug 2
    temp = ( struct node* ) malloc ( sizeof ( struct node ) );
    temp -> jug2 = q;
    temp -> jug1 = curr -> jug1;
    if ( check( temp -> jug1 , temp -> jug2 , i ) )
     {
      // temp -> link = curr;
      array[i] = temp;
       //if ( temp -> jug2 == r )
	  //display(temp);
	  // temp -> link = curr;
      // array[i++] = temp;
      // if ( temp -> jug1 == r )
      printf("\n\n%d %d",temp->jug1,temp->jug2);

      WJ_BFS(temp);
     }
    else
     free(temp);


    // empty jug 1
    temp = ( struct node* ) malloc ( sizeof ( struct node ) );
    temp -> jug1 = 0;
    temp -> jug2 = curr -> jug2;
    if ( check( temp -> jug1 , temp -> jug2 , i ) )
     {   array[i]=temp;
      printf("\n\n%d %d",temp->jug1,temp->jug2);

      WJ_BFS(temp);
       //temp -> link = curr;
       //array[i++] = temp;
       //if ( temp -> jug1 == r )
	  //display(temp);
     }
    else
     free(temp);


    // empty jug 2
    temp = ( struct node* ) malloc ( sizeof ( struct node ) );
    temp -> jug2 = 0;
    temp -> jug1 = curr -> jug1;
    if ( check( temp -> jug1 , temp -> jug2 , i ) )
     {  array[i]=temp;
      printf("\n\n%d %d",temp->jug1,temp->jug2);

      WJ_BFS(temp);
       //temp -> l







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
     { array[i]=temp;
      printf("\n\n%d %d",temp->jug1,temp->jug2);

      WJ_BFS(temp);

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
     { array[i]=temp;
     printf("\n\n%d %d",temp->jug1,temp->jug2);

      WJ_BFS(temp);



     }
    else
     free(temp);


    //curr = array[j++];




}




void main()
{
 clrscr();

   i=0;
 cout<<"\n\n Enter the capacity of jug 1 : ";
 cin>>p;

 cout<<"\n\n Enter the capacity of jug 2 : ";
 cin>>q;

 cout<<"\n\n Enter the capacity of water required : ";
 cin>>r;
 start = ( struct node* ) malloc ( sizeof ( struct node ) );

 start -> jug1 = 0;
 start -> jug2 = 0;
 start -> link = NULL;


 WJ_BFS(start);
 array[0]=start;
}