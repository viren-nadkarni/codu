#include<stdio.h>
#include<conio.h>
#include<iostream.h>
#include<stdlib.h>

struct node
{
  int grid[3][3];
  struct node *next;
  struct node *parent;
}*list=NULL,goal,initial,succ,*pd=NULL,*dlist=NULL;

int rules[2][2],val=0;


void input()
{
  int i,j;//c=1;
  cout<<"\nEnter the initial state of the problem <0 for space> :";
  for(i=0;i<3;i++)
    for(j=0;j<3;j++)

     cin>>initial.grid[i][j];
  cout<<"\nEnter the final state :";
  for(i=0;i<3;i++)
   for(j=0;j<3;j++)
     cin>>goal.grid[i][j];

}
node *getnode(node state)
{
    int i,j;
    node *t;
    clrscr();
    val++;
    printf("count=%d",val);
    t=new node;
    for(i=0;i<3;i++)
     for(j=0;j<3;j++)
      t->grid[i][j]=state.grid[i][j];
      t->next=NULL;
      t->parent=pd;
      return t;
}

void push(node state)
{
  node *temp;
  temp=getnode(state);
  if(list==NULL)
   list=temp;

   else
   {
     temp->next=list;
     list=temp;
   }
 }
   void display_path(node succ)
  {
    int i,j,count=0;
    clrscr();

    printf("\n\nGOAL\n\n") ;

      for(i=0;i<3;i++)
       {	 for(j=0;j<3;j++)
		      printf("%d",succ.grid[i][j]);
		 printf("\n");
	}
		   count++;
	// printf("\n");
	 printf(" ^");
	 printf("\n |\n");


      while(pd!=NULL)
      {    for(i=0;i<3;i++)
	    {  for(j=0;j<3;j++)
		  printf("%d",pd->grid[i][j]);

		  printf("\n");
	    }
	    pd=pd->parent;
	    count++;
	    if(count%9==0)
	    {printf("\nPRESS ENTER ...\n");getch(); }
	     printf(" ^");
	     printf("\n |\n");

       }
       printf("\nINITIAL\n\n");
  }

void create_dlist(node *t)
 {
   if(dlist==NULL)
     dlist=t;
   else
   {
    t->next=dlist;
    dlist=t;
    }
}

 node *pop()
 {
  node *temp;
  if(list==NULL)
  { cout<<"No node to delet";  exit (0);}

   temp=list;
   list=list->next;
   create_dlist(temp);
   return temp;

 }
 int chk_goal(node temp)
 {
   int i,j,count;
   for(i=0;i<3;i++)
     for(j=0;j<3;j++)
       if(goal.grid[i][j]==temp.grid[i][j])
	 count++;

    if(count==9)
    return 1;
    else return 0;
 }

void getrules()
	{
	int i,j,k,flag=1;
	for(i=0;i<2;i++)
	 for(j=0;j<2;j++)
	rules[i][j]=0;
	for(i=0;i<3;i++)
	{
	 for(j=0;j<3;j++)
	  if(pd->grid[i][j]==0)
	  {
	   flag=0;
	   break;
	  }
	  if(flag==0)
	  break;
	 }
				     // Rules 00-T,01-R,10-L,11-B
	if(i==0)
	{
	 rules[1][1]=1;
	  if((j==0)||(j==1))
	   rules[0][1]=1;
		if((j==2)||(j==1))
			rules[1][0]=1;
	  }
	else if(i==2)
		{
		rules[0][0]=1;
		if((j==0)||(j==1))
			rules[0][1]=1;
		if((j==2)||(j==1))
			rules[1][0]=1;
		}
	else
		{
		rules[0][0]=rules[1][1]=1;
		if((j==0)||(j==1))
			rules[0][1]=1;
		if((j==2)||(j==1))
			rules[1][0]=1;
		}
  }



  int comp(node succ)      //compares if that node already exists
  {
   node *temp=list;
   node *temp2=dlist;
   int count=0;
    int i,j;
    for(i=0;i<3;i++)
     for(j=0;j<3;j++)
      if(initial.grid[i][j]==succ.grid[i][j])
	 count++;
     if(count==9)
     return 0;


    while(temp!=NULL)
    { count=0;
    for(i=0;i<3;i++)
     for(j=0;j<3;j++)
       if(temp->grid[i][j]==succ.grid[i][j])
	 count++;
    if(count==9)
    return 0;

     temp=temp->next;
    }

     while(temp2!=NULL)
    {    count=0;
    for(i=0;i<3;i++)
     for(j=0;j<3;j++)
       if(temp2->grid[i][j]==succ.grid[i][j])
	 count++;
     if(count==9)
     return 0;

     temp2=temp2->next;
    }
    return 1;
   }

 void apply_rules()
  {
      int i,j,r,flag=0;
    getrules();

    if(rules[0][0]==1)
    {
     for(i=0;i<3;i++)
	for(j=0;j<3;j++)
	succ.grid[i][j]=pd->grid[i][j];
     for(i=0;i<3;i++)
       {	for(j=0;j<3;j++)
	 if(succ.grid[i][j]==0)
	 {  flag=1;
	 succ.grid[i][j]=succ.grid[i-1][j];     //movg space top
	 succ.grid[i-1][j]=0;
	 break;
	 }
	 if (flag)
	 { flag=0;break;}
	}

	r=chk_goal(succ);

	 if(r==1)
	{ display_path(succ);
	  cout<<"SUCCESS";
	 getch();
	  exit (1);
	}
	     if(comp(succ))
	    { push(succ);
     }


     if(rules[0][1]==1)
    {
     for(i=0;i<3;i++)
	for(j=0;j<3;j++)
	succ.grid[i][j]=pd->grid[i][j];
     for(i=0;i<3;i++)
       {	for(j=0;j<3;j++)
	 if(succ.grid[i][j]==0)
	 {flag=1;
	 succ.grid[i][j]=succ.grid[i][j+1];     //movg space right
	 succ.grid[i][j+1]=0;
	 break;
	 }
	 if(flag)
	{flag=0; break;}
       }

	 r=chk_goal(succ);

	 if(r==1)
	{ display_path(succ);
	  cout<<"SUCCESS";
	  getch();
	  exit (1);
	}
	  if(comp(succ))
	    push(succ);

       }

    if(rules[1][0]==1)
    {
     for(i=0;i<3;i++)
	for(j=0;j<3;j++)
	succ.grid[i][j]=pd->grid[i][j];
     for(i=0;i<3;i++)
       {	for(j=0;j<3;j++)
	 if(succ.grid[i][j]==0)
	 {    flag=1;
	 succ.grid[i][j]=succ.grid[i][j-1];     //movg space left
	 succ.grid[i][j-1]=0;
	 break;
	 }
	 if(flag)
	 {flag=0;break;}
	}

	 r=chk_goal(succ);

	 if(r==1)
	{  display_path(succ);
	   cout<<"SUCCESS";
	   getch();
	   exit (1);
	}

	if (comp(succ))
	   push(succ);
   }

    if(rules[1][1]==1)
    {
     for(i=0;i<3;i++)
	for(j=0;j<3;j++)
	succ.grid[i][j]=pd->grid[i][j];
     for(i=0;i<3;i++)
      {
	for(j=0;j<3;j++)
	 if(succ.grid[i][j]==0)
	 { flag=1;
	 succ.grid[i][j]=succ.grid[i+1][j];     //movg  space down
	 succ.grid[i+1][j]=0;
	 break;
	 }
	 if(flag)
	 { flag=0;break;  }
      }

	 r=chk_goal(succ);

	 if(r==1)
	{ display_path(succ);
	  cout<<"SUCCESS";
	  getch();
	  exit (1);
	}
	if(comp(succ))
	   push(succ);
     }
  }
 }
 void dfs()
 {
   push(initial);
   while(list!=NULL)
     {
      pd=pop();
      apply_rules();
     }
     printf("\n NO SOLUTION");
     getch();
     exit(1);
  }

 void main()
 {
   clrscr();
   input();
   dfs();
   getch();
}