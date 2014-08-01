#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
void main()
{


   /* request auto detection */
   int gdriver = DETECT, gmode, errorcode;
   int cell[9],i;


   /* initialize graphics and local variables */
   initgraph(&gdriver, &gmode, "c:\\tc\\bgi");

   /* read result of initialization */
   errorcode = graphresult();
   if (errorcode != grOk)  /* an error occurred */
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1); /* terminate with an error code */
   }


   line(450,150,450,300);
   line(500,150,500,300);
   line(400,200,550,200);
   line(400,250,550,250);
   for(i=0;i<9;i++)
   cell[i]=0;

   int toss=0,pos;
  // toss=random(10);
 //  printf("%d",toss);
//   if(toss==1)
   printf("1.COMPUTER\n");
   printf("2.PLAYER\n");
   scanf("%d",&toss);


   switch(toss)

   {

	case 1:
		if(cell[4]!=1 && cell[4]!=2)
		{
		outtextxy(475,225,"X");
		cell[4]=1;
		goto player;
		}

	  comp: if((cell[2]==2 && cell[5]==2 && cell[8]==2) || (cell[0]==2 && cell[1]==2 && cell[2]==2) || (cell[3]==2 && cell[4]==2 && cell[5]==2) || (cell[6]==2 && cell[7]==2 && cell[8]==2) || (cell[0]==2 && cell[3]==2 && cell[6]==2) || (cell[0]==2 && cell[4]==2 && cell[8]==2) || (cell[0]==2 && cell[4]==2 && cell[6]==2) || (cell[1]==2 && cell[4]==2 && cell[7]==2))
		   goto res;
		if((cell[0]==1 || cell[0]==2) && (cell[1]==1 || cell[1]==2) &&(cell[2]==1 || cell[2]==2) &&(cell[3]==1 || cell[3]==2) &&(cell[4]==1 || cell[4]==2) &&(cell[5]==1 || cell[5]==2) &&(cell[6]==1 || cell[6]==2) &&(cell[7]==1 || cell[7]==2) &&(cell[8]==1 || cell[8]==2))
		  goto drw;
		if((cell[2]==2 && cell[8]==2) && (cell[5]!=1 && cell[5]!=2))
		{
		 cell[5]=1;
		 outtextxy(525,225,"X");
		 goto player;

		}

		if((cell[2]==2 && cell[0]==2) && (cell[1]!=2 && cell[1]!=1))
		{
		 cell[1]=1;
		 outtextxy(475,175,"X");
		 goto player;

		}

		if((cell[2]==2 && cell[6]==2) && (cell[4]!=2 && cell[4]!=1))
		{
		 cell[4]=1;
		 outtextxy(475,225,"X");
		 goto player;

		}
		if((cell[5]==2 && cell[3]==2) && (cell[4]!=2 && cell[4]!=1))
		{
		 cell[4]=1;
		 outtextxy(475,225,"X");
		 goto player;

		}
		if((cell[0]==2 && cell[6]==2) && (cell[3]!=2 && cell[3]!=1))
		{
		 cell[3]=1;
		 outtextxy(425,225,"X");
		 goto player;

		}
		if((cell[1]==2 && cell[7]==2) && (cell[4]!=2 && cell[4]!=1))
		{
		 cell[4]=1;
		 outtextxy(475,225,"X");
		 goto player;

		}
		if((cell[3]==1 && cell[4]==1) && (cell[5]!=1 && cell[5]!=2))
		{
		  cell[5]=1;
		  outtextxy(525,225,"X");
		  goto player;

		}

		if((cell[1]==1 && cell[4]==1) && (cell[7]!=1 && cell[7]!=2))
		{
		  cell[7]=1;
		  outtextxy(475,275,"X");
		  goto player;

		}


		if(cell[3]!=2 && cell[3]!=1)

		{
		 cell[3]=1 ;
		 outtextxy(425,225,"X");
		 goto player;
		}

		if(cell[1]!=2 && cell[1]!=1)
		{
		 cell[1]=1 ;
		 outtextxy(475,175,"X");
		 goto player;
		}

		if(cell[2]!=2 && cell[2]!=1)
		{
		 cell[2]=1 ;
		 outtextxy(475,175,"X");
		 goto player;
		}


		if(cell[0]!=2 && cell[0]!=1)
		{
		 cell[0]=1 ;
		 outtextxy(425,175,"X");
		 goto player;
		}




		if(cell[4]!=2 && cell[4]!=1)
		{
		 cell[4]=1 ;
		 outtextxy(475,225,"X");
		 goto player;
		}



		if(cell[5]!=2 && cell[5]!=1)
		{
		 cell[5]=1 ;
		 outtextxy(525,225,"X");
		 goto player;
		}

		if(cell[6]!=2 && cell[6]!=1)
		{
		 cell[6]=1 ;
		 outtextxy(425,275,"X");
		 goto player;
		}

		if(cell[7]!=2 && cell[7]!=1)
		{
		 cell[7]=1 ;
		 outtextxy(475,275,"X");
		 goto player;
		}

		if(cell[8]!=2 && cell[8]!=1)
		{
		 cell[8]=1 ;
		 outtextxy(525,275,"X");
		 goto player;
		}




	      break;



       case 2: player:
		     if((cell[2]==1 && cell[5]==1 && cell[8]==1) || (cell[0]==1 && cell[1]==1 && cell[2]==1) || (cell[3]==1 && cell[4]==1 && cell[5]==1) || (cell[6]==1 && cell[7]==1 && cell[8]==1) || (cell[0]==1 && cell[3]==1 && cell[6]==1) || (cell[0]==1 && cell[4]==1 && cell[8]==1) || (cell[0]==1 && cell[4]==1 && cell[6]==1) || (cell[1]==1 && cell[4]==1 && cell[7]==1))
		     goto res1;
		     if((cell[0]==1 || cell[0]==2) && (cell[1]==1 || cell[1]==2) &&(cell[2]==1 || cell[2]==2) &&(cell[3]==1 || cell[3]==2) &&(cell[4]==1 || cell[4]==2) &&(cell[5]==1 || cell[5]==2) &&(cell[6]==1 || cell[6]==2) &&(cell[7]==1 || cell[7]==2) &&(cell[8]==1 || cell[8]==2))
		     goto drw;
		     printf("Enter the position:");
		     scanf("%d",&pos);
		     if(cell[pos]==1 && cell[pos]==2)
		     printf("cell is already occupied");
		     if(pos==1)
		     {
		      outtextxy(425,175,"0");
		      cell[pos-1]=2;
		     goto comp;
		     }
		     if(pos==2)
		     {
		      outtextxy(475,175,"0");
		      cell[pos-1]=2;
		     goto comp;
		     }

		     if(pos==3)
		     {
		      outtextxy(525,175,"0");
		      cell[pos-1]=2;
		     goto comp;
		     }

		     if(pos==4)
		     {
		      outtextxy(425,225,"0");
		      cell[pos-1]=2;
		     goto comp;
		     }

		     if(pos==5)
		     {
		      outtextxy(475,225,"0");
		      cell[pos-1]=2;
		     goto comp;
		     }

		     if(pos==6)
		     {
		      outtextxy(525,225,"0");
		      cell[pos-1]=2;
		      goto comp;

		     }


		     if(pos==7)
		     {
		      outtextxy(425,275,"0");
		      cell[pos-1]=2;
		     goto comp;
		     }


		     if(pos==8)
		     {
		      outtextxy(475,275,"0");
		      cell[pos-1]=2;
		     goto comp;
		     }

		     if(pos==9)
		     {
		      outtextxy(525,275,"0");
		      cell[pos-1]=2;
		     goto comp;
		     }


		     break;


   }
    res1: printf("\ncomputer wins");
   res: printf("\nplayer wins");
    drw:printf("\ndraw");









   getch();

}