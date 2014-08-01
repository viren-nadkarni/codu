#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<graphics.h>
void tree(int x,int y)
{
     //circle(x,y-100,100);
    // circle(x+20,y-90,100);
    setfillstyle(SOLID_FILL, GREEN);
  ellipse(x+150,y+50,0,360,200,100);
   floodfill(x+120,y+10, WHITE);
    setfillstyle(SOLID_FILL, BROWN);
    int points[]={x+89,y+289,x+165,y+289,x+165,y+112,x+249,y+95,x+305,y+106,x+238,y+86,
    x+164,y+85,x+213,y+10,x+151,y+46,x+116,y+100,x+56,y+74,x+2,y+102,x+53,y+92,x+88,y+120,x+89,y+289};
    fillpoly(15,points);
    //floodfill(x+103,y+100, BROWN);
     //line(x+,y+,x+,y+);
     }
     void man1(int x,int y)
     {
          setfillstyle(SOLID_FILL,BLACK);
          circle(x+9,y+5,4);
          floodfill(x+9,y+5,WHITE);
          setfillstyle(SOLID_FILL,12);
          circle(x+15,y+9,13);
          floodfill(x+15,y+9,WHITE);
          setcolor(YELLOW);
          setfillstyle(SOLID_FILL, RED);
          rectangle(x+4,y+31,x+26,y+66);
          floodfill(x+10,y+55,YELLOW);
          delay(50);
          line(x+4,y+43,x+26,y+43);
          setcolor(WHITE);
          line(x+15,y+20,x+15,y+30);
         // line(x+13,y+67,x+13,y+89);
          line(x+15,y+42,x+15,y+60);
          line(x+15,y+66,x+15,y+90);
     }
     void man2(int x,int y)
     {
          setfillstyle(SOLID_FILL,BLACK);
          circle(x+9,y+5,4);
          floodfill(x+9,y+5,WHITE);
          setfillstyle(SOLID_FILL,12);
          circle(x+15,y+9,13);
          floodfill(x+15,y+9,WHITE);
          setcolor(YELLOW);
          setfillstyle(SOLID_FILL, RED);
          rectangle(x+4,y+31,x+26,y+66);
          floodfill(x+10,y+55,YELLOW);
          line(x+4,y+43,x+26,y+43);
          setcolor(WHITE);
          line(x+15,y+20,x+15,y+30);
         // line(x+13,y+67,x+13,y+89);
          line(x+15,y+42,x+15,y+60);
          line(x+15,y+66,x+5,y+88);
          line(x+15,y+66,x+22,y+88);
     }
      void man3(int x,int y)
     {
          setfillstyle(SOLID_FILL,BLACK);
          circle(x+19,y+5,4);
          floodfill(x+19,y+5,WHITE);
          setfillstyle(SOLID_FILL,12);
          circle(x+15,y+9,13);
          floodfill(x+15,y+9,WHITE);
          setcolor(YELLOW);
          setfillstyle(SOLID_FILL, RED);
          rectangle(x+4,y+31,x+26,y+66);
          floodfill(x+10,y+55,YELLOW);
          delay(50);
          line(x+4,y+43,x+26,y+43);
          setcolor(WHITE);
          line(x+15,y+20,x+15,y+30);
         // line(x+13,y+67,x+13,y+89);
          line(x+15,y+42,x+15,y+60);
          line(x+15,y+66,x+15,y+90);
     }
     void man4(int x,int y)
     {
          setfillstyle(SOLID_FILL,BLACK);
          circle(x+19,y+5,4);
          floodfill(x+19,y+5,WHITE);
          setfillstyle(SOLID_FILL,12);
          circle(x+15,y+9,13);
          floodfill(x+15,y+9,WHITE);
          setcolor(YELLOW);
          setfillstyle(SOLID_FILL, RED);
          rectangle(x+4,y+31,x+26,y+66);
          floodfill(x+10,y+55,YELLOW);
          line(x+4,y+43,x+26,y+43);
          setcolor(WHITE);
          line(x+15,y+20,x+15,y+30);
         // line(x+13,y+67,x+13,y+89);
          line(x+15,y+42,x+15,y+60);
          line(x+15,y+66,x+5,y+88);
          line(x+15,y+66,x+22,y+88);
     }
     void shrub(int x,int y)
     {//y+200
     int x1=x,y1=y+30,i;
     setcolor(GREEN);
         for(i=0;i<7;i++)
         {
          circle(x1+27,y1+253,10);
          circle(x1+30,y1+253,10);
          circle(x1+40,y1+253,10);
          circle(x1+47,y1+248,15);
          circle(x1+55,y1+248,15);
          circle(x1+60,y1+248,15);
          circle(x1+66,y1+252,11);
          circle(x1+80,y1+253,10);
          circle(x1+87,y1+253,10);
          y1-=i;
          }
          setcolor(WHITE);
          }
                 void elephant1(int x,int y)
                 {
                      setfillstyle(SOLID_FILL,7);
                      //body
                      circle(x+87,y+64,67);
                      floodfill(x+80,y+64,WHITE);
                      setfillstyle(SOLID_FILL,7);
                      //head
                      circle(x+168,y+56,40);
                      floodfill(x+168,y+56,WHITE);
                      setfillstyle(SOLID_FILL,12);
                      floodfill(x+152,y+66,WHITE);
                      //leg1
                      setfillstyle(SOLID_FILL,7);
                      line(x+42,y+111,x+42,y+151);
                      line(x+69,y+126,x+69,y+151);
                      line(x+42,y+151,x+69,y+151);
                      floodfill(x+57,y+141,WHITE);
                      //leg2
                      setfillstyle(SOLID_FILL,7);
                     line(x+143,y+151,x+143,y+100);
                     line(x+143,y+151,x+122,y+151);
                      line(x+122,y+117,x+122,y+151);
                      floodfill(x+130,y+140,WHITE);
                      setfillstyle(SOLID_FILL,7);
                      line(x+180,y+90,x+211,y+121);//trunk
                      line(x+199,y+78,x+222,y+116);
                      line(x+211,y+121,x+210,y+140);
                      line(x+222,y+116,x+220,y+140);
                      line(x+210,y+140,x+220,y+140);
                       floodfill(x+215,y+135,WHITE);
                      setfillstyle(SOLID_FILL,0);
                      //eye
                      circle(x+185,y+70,5);
                       floodfill(x+185,y+68,WHITE);
                      }
                      void elephant2(int x,int y)
                 {
                      setfillstyle(SOLID_FILL,7);
                      //body
                      circle(x+87,y+64,67);
                      floodfill(x+80,y+64,WHITE);
                      setfillstyle(SOLID_FILL,7);
                      //head
                      circle(x+168,y+56,40);
                      floodfill(x+168,y+56,WHITE);
                      setfillstyle(SOLID_FILL,12);
                      floodfill(x+152,y+66,WHITE);
                      //leg1
                      setfillstyle(SOLID_FILL,7);
                      line(x+42,y+111,x+42,y+151);
                      line(x+69,y+126,x+69,y+151);
                      line(x+42,y+151,x+69,y+151);
                      floodfill(x+57,y+141,WHITE);
                      //leg2
                      setfillstyle(SOLID_FILL,7);
                     line(x+143,y+151,x+143,y+100);
                     line(x+143,y+151,x+122,y+151);
                      line(x+122,y+117,x+122,y+151);
                      floodfill(x+130,y+140,WHITE);
                      setfillstyle(SOLID_FILL,7);
                      line(x+180,y+90,x+211,y+121);
                      line(x+211,y+121,x+235,y+106);
                      line(x+235,y+106,x+230,y+95);
                      line(x+230,y+95,x+219,y+106);
                      line(x+199,y+78,x+219,y+106);
                       floodfill(x+215,y+109,WHITE);
                      setfillstyle(SOLID_FILL,0);
                      //eye
                      circle(x+185,y+70,5);
                       floodfill(x+185,y+68,WHITE);
                      }
                      void giraffe1(int x, int y)
                      {
                           int pts[]={x+100,y+100,x+68,y+38,x+58,y+48,x+53,y+40,63+x,y+28,x+65,y+22,x+77,
                           y+32,x+120,y+80,x+160,y+100,x+170,y+150,x+156,y+120,x+115,y+109,x+110,y+148,x+100,y+100};
                           setfillstyle(INTERLEAVE_FILL,YELLOW);
                           fillpoly(14,pts);
                           //floodfill(x+103,y+100,WHITE);
                           }
                           void giraffe2(int x, int y)
                      {
                           int pts[]={x+100,y+100,x+58,y+108,x+62,y+118,x+53,y+120,44+x,y+108,x+41,y+102,x+28,y+98,x+120,y+80,
                           x+160,y+100,x+170,y+150,x+156,y+120,x+115,y+109,x+110,y+148,x+100,y+100};
                           setfillstyle(INTERLEAVE_FILL,YELLOW);
                           fillpoly(14,pts);
                           /*line(x+100,y+100,x+58,y+108);
                           line(x+58,y+108,x+62,y+118);
                           line(x+62,y+118,x+53,y+120);
                           line(x+53,y+120,44+x,y+108);
                           line(44+x,y+108,x+41,y+102);
                           line(x+41,y+102,x+28,y+98);
                           line(x+28,y+98,x+120,y+80);
                           line(x+120,y+80,x+160,y+100);
                           line(x+170,y+150,x+160,y+100);
                           line(x+170,y+150,x+156,y+120);
                           line(x+115,y+109,x+156,y+120);
                           line(x+115,y+109,x+110,y+148);
                           line(x+100,y+100,x+110,y+148);
                           */}
int main()
{
    initwindow(1000, 700, "forest");
    //for( int i=0;i<180;i++)
    //{
	int i=9;
         //cleardevice();
         setbkcolor(11);
         settextstyle(6,HORIZ_DIR,0);
         outtextxy(100,50,"A peacefull walk through a forest.");
         setbkcolor(0);
    setfillstyle(SOLID_FILL,11);
    floodfill(10,10,WHITE);
    setfillstyle(SOLID_FILL,YELLOW);
    fillellipse(850,60,40,40);
    setfillstyle(SOLID_FILL,GREEN);
    
    line(0,490,1000,490);
    floodfill(5,500,WHITE);
    setcolor(WHITE);
     shrub(40,200);shrub(60,180);
    shrub(70,200);
    shrub(140,200);shrub(240,200);
    giraffe1(500,350);
/*    if(i%10==0)
    {
    giraffe1(290,350);
    }
    else
    {
    giraffe2(290,350);
    }
    i+=2;
    shrub(440,210);shrub(440,190); shrub(440,180);shrub(320,209);
    if(i%5<3)
            {
              man2(500-i*3,500);//delay(100);
              }
              else
              {
              man1(500-i*3,500);//delay(100);
              }
        tree(-100,200);
        
  */      
        //giraffe1(100,100);
       //delay(400);
      //}
    /*for(int i=0;i<1200;i++)
    {
    cleardevice();
    setbkcolor(11);
    setfillstyle(SOLID_FILL,YELLOW);
    fillellipse(850,60,40,40);
    setfillstyle(SOLID_FILL,GREEN);
    //setcolor(0);
    line(0,490,1000,490);
    floodfill(5,500,WHITE);
    setcolor(WHITE);
    setfillstyle(SOLID_FILL,YELLOW);
    fillellipse(850,60,40,40);
    setfillstyle(SOLID_FILL,GREEN);
    setcolor(0);
    line(0,490,1000,490);
    floodfill(5,500,0);
    setcolor(WHITE);
   // shrub(40,200);
    //shrub(70,200);shrub(240,200);shrub(140,200);
    tree(100,200);shrub(240,200);shrub(140,200);
    shrub(340,200);shrub(340,180);shrub(300,200);shrub(400,200);
    tree(520,200);
    shrub(440,200);shrub(510,200);
    shrub(620,200);shrub(610,180);shrub(500,180);shrub(550,190);
     shrub(740,200);shrub(750,200);
    shrub(640,200);shrub(700,200);
         if(i<300)
         {
            if(i%5<3)
            {
              man2(500-i,450);delay(100);
              }
              else
              {
              man1(500-i,450);delay(100);
              }
              i+=11;
         }
         else if(i<400)
         {
             settextstyle(6,HORIZ_DIR,0);
         outtextxy(100,50,"Until...terror strikes.");
             if(i%5<3)
            {
                      elephant2(i-522,340);
              man3(i-180,450);delay(50);
              }
              else
              {
                  elephant1(i-522,340);
              man4(i-180,450);delay(50);
              i+=21;
              }
        }
        else
        {   settextstyle(6,HORIZ_DIR,0);
         outtextxy(100,50,"Until...terror strikes.");
               if(i<450)
               {
                        elephant2(i-542,340);
                        if(i%5<3)
                        {
                                 man3(i-200,450);delay(50);
                                 }
                        else
                        {
                                 man4(i-200,450);delay(50);
                                 }
              }
              else
              {
                  settextstyle(6,HORIZ_DIR,0);
         outtextxy(100,50,"Until...terror strikes.");
                  if(i%5<3)
                           {
                                 elephant2(-50,340);
                           man3(i-200,450);delay(50);
                           }
                  else
                  {          elephant1(-50,340);
                           man4(i-200,450);delay(50);
                           }
                  }
              i+=21;
              }
     }
   cleardevice();
    setbkcolor(11);
    setfillstyle(SOLID_FILL,YELLOW);
    fillellipse(850,60,40,40);
    setfillstyle(SOLID_FILL,GREEN);
    //setcolor(0);
    line(0,490,1000,490);
    floodfill(5,500,WHITE);
    setcolor(WHITE);
    setfillstyle(SOLID_FILL,YELLOW);
    fillellipse(850,60,40,40);
    setfillstyle(SOLID_FILL,GREEN);
    setcolor(0);
    line(0,490,1000,490);
    floodfill(5,500,0);
    setcolor(WHITE);
   // shrub(40,200);
    //shrub(70,200);shrub(240,200);shrub(140,200);
    tree(100,200);shrub(240,200);shrub(140,200);
    shrub(340,200);shrub(340,180);shrub(300,200);shrub(400,200);
    tree(520,200);
    shrub(440,200);shrub(510,200);
    shrub(620,200);shrub(610,180);shrub(500,180);shrub(550,190);
     shrub(740,200);shrub(750,200);
    shrub(640,200);shrub(700,200);
    settextstyle(6,HORIZ_DIR,0);
         outtextxy(100,50,"Stay home.Stay safe.");
    elephant2(-50,340);*/
    getch();
}
