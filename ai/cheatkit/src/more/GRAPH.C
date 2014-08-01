#include<stdio.h>
//#include<conio.h>


void main()
{
 int arr[25];
 int visited[25];
 int a[25][25];
 int n,i=0,j=0,k=0;
 //clrscr();
 printf("\nENTER THE NUMBER OF ELEMENTS : ");
 scanf("%d",&n);
 for(i=0;i<25;i++)
  visited[i]=0;



 printf("\nENTER VALUES : ");
 for(i=0;i<n;i++)
   scanf("%d",&arr[i]);

   i=0;
   j=0;
   k=65;
   for(i=0;i<n;i++)
    {
      printf(" %c ",k);
      k++;
    }
     i=0;
   for(i=0;i<n;i++)
   {
     printf("\n");
     for(j=0;j<n;j++)
     {
       scanf("%d",&a[i][j]);

     }

   }





   i=0;
   j=0;
   printf("\n\n\n");
   printf("\n");
   printf("%d",arr[0]);
   visited[0]=1;
   for(i=0;i<n;i++)
    {
      if(visited[i]==0)
	continue;
      else
      {
	for(j=0;j<n;j++)
	{

	  if(a[i][j]==1)
	  {
	    if(visited[j]==0)
	    {
	      printf("\n");
	      printf(" %d ",arr[j]);
	      visited[j]=1;
	    }
	  }
	}
      }
     }



   //getch();

}