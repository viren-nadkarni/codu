#include<stdio.h>
#include<conio.h>
#include<graphics.h>


int bd[9]={2,2,2,2,2,2,2,2,2},a,b,c,d,e,f,g,h;
/*bd[0]=2;
bd[1]=2;
bd[2]=2;
bd[3]=2;
bd[4]=2;
bd[5]=2;
bd[6]=2;
bd[7]=2;
bd[8]=2;
*/

int oppw()
{int v=18;

  if(v==a)
  {  if(bd[0]==2)
      return 0;
      if(bd[1]==2)
      return 1;
      if(bd[2]==2)
      return 2;
  }
  if(v==b)
  {  if(bd[3]==2)
      return 3;
      if(bd[4]==2)
      return 4;
      if(bd[5]==2)
      return 5;
  }
  if(v==c)
  {  if(bd[6]==2)
      return 6;
      if(bd[7]==2)
      return 7;
      if(bd[8]==2)
      return 8;
  }
  if(v==d)
  {  if(bd[0]==2)
      return 0;
      if(bd[3]==2)
      return 3;
      if(bd[6]==2)
      return 6;
  }
  if(v==e)
  {  if(bd[1]==2)
      return 1;
      if(bd[4]==2)
      return 4;
      if(bd[7]==2)
      return 7;
  }

  if(v==f)
  {  if(bd[2]==2)
      return 2;
      if(bd[5]==2)
      return 5;
      if(bd[8]==2)
      return 8;
  }
  if(v==g)
  {  if(bd[0]==2)
      return 0;
      if(bd[4]==2)
      return 4;
      if(bd[8]==2)
      return 8;
  }
  if(v==h)
  {  if(bd[2]==2)
      return 2;
      if(bd[4]==2)
      return 4;
      if(bd[6]==2)
      return 6;
  }

  return -1;


}

int iwin()
{int v=50;

  if(v==a)
  {  if(bd[0]==2)
      return 0;
      if(bd[1]==2)
      return 1;
      if(bd[2]==2)
      return 2;
  }
  if(v==b)
  {  if(bd[3]==2)
      return 3;
      if(bd[4]==2)
      return 4;
      if(bd[5]==2)
      return 5;
  }
  if(v==c)
  {  if(bd[6]==2)
      return 6;
      if(bd[7]==2)
      return 7;
      if(bd[8]==2)
      return 8;
  }
  if(v==d)
  {  if(bd[0]==2)
      return 0;
      if(bd[3]==2)
      return 3;
      if(bd[6]==2)
      return 6;
  }
  if(v==e)
  {  if(bd[1]==2)
      return 1;
      if(bd[4]==2)
      return 4;
      if(bd[7]==2)
      return 7;
  }

  if(v==f)
  {  if(bd[2]==2)
      return 2;
      if(bd[5]==2)
      return 5;
      if(bd[8]==2)
      return 8;
  }
  if(v==g)
  {  if(bd[0]==2)
      return 0;
      if(bd[4]==2)
      return 4;
      if(bd[8]==2)
      return 8;
  }
  if(v==h)
  {  if(bd[2]==2)
      return 2;
      if(bd[4]==2)
      return 4;
      if(bd[6]==2)
      return 6;
  }

  return -1;


}

  void drow(int pos,int m)
  { char *p;
  int i;
    if(m%2==1)
     p="x";
    else
    p="o";
    i=pos+1;
   switch(i)
   {

//row1
case 1:  outtextxy(30,10,p); break;
case 2:  outtextxy(55,10,p);break;
case 3:  outtextxy(80,10,p);break;
  //row2
case 4:  outtextxy(30,33,p);break;
case 5:  outtextxy(55,33,p);break;
case 6:  outtextxy(80,33,p);break;
   //row3
case 7:  outtextxy(30,55,p);break;
case 8:  outtextxy(55,55,p);break;
case 9:  outtextxy(80,55,p);break;

}



  }

void main()
{
 int m,t,x,y,j;
 /* request auto detection */
   int gdriver = DETECT, gmode, errorcode;

   /* initialize graphics and local variables */
   initgraph(&gdriver, &gmode, "");


  cleardevice();

  line(50,10,50,60);
  line(70,10,70,60);
  line(  30, 24 ,90  ,24);
  line(30,48,90,48);

  printf("\n\n\n\n\n\n");
  a=bd[0]*bd[1]*bd[2];
b=bd[3]*bd[4]*bd[5];
c=bd[6]*bd[7]*bd[8];
d=bd[0]*bd[3]*bd[6];
e=bd[1]*bd[4]*bd[7];
f=bd[2]*bd[5]*bd[8];
g=bd[0]*bd[4]*bd[8];
h=bd[2]*bd[4]*bd[6];




  m=1;
  for(m=1;m<=9;m++)
  {  x=oppw();
    if(x==27)
    {
      printf("\nyou win I loose");
      exit(0);
    }

   if(m%2==1)
   {

     printf("\nenter your move");
     scanf("%d",&t);
     bd[t]=3;
     drow(t,m);
   }

   else
   {
     if(m==2)
     {
	  if(bd[4]==3)
	   {
	    bd[0]=5;

	    printf("\ncomp move is 0");
	    drow(0,m);

	   }
	   else
	   {
	    bd[4]=5;
	    printf("\ncomp move is 4");
	    drow(4,m);

	   }
     // printf("\n\ncomp move is %d",m);
     }
     else
     { x=iwin();
     //printf("%d",x);


     if(x==-1)
     {
      y=oppw();
      if(y==-1)
      {
       for( j=0;j<=8;j++)
      { if(f!=1)
       {
	if(bd[j]==2)
	{bd[j]=5;
	drow(j,m);
	f=1;
	}
       }
      }
      }	    else
      {
      bd[y]=5;
      printf("\ncomp move is %d",y);
      drow(y,m);
      }
     }
     else
     {
      bd[x]=5;
      printf("\ncomp move s %d",x);
      printf("\nI won");
      drow(x,m);
      getch();
      exit(0);
     }



  }
}
   a=bd[0]*bd[1]*bd[2];
b=bd[3]*bd[4]*bd[5];
c=bd[6]*bd[7]*bd[8];
d=bd[0]*bd[3]*bd[6];
e=bd[1]*bd[4]*bd[7];
f=bd[2]*bd[5]*bd[8];
g=bd[0]*bd[4]*bd[8];
h=bd[2]*bd[4]*bd[6];


  }




getch();
}
