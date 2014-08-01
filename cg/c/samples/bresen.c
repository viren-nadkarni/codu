#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>

#define round(a) ((int)(a+0.5))

void bres(int x1,int y1,int x2,int y2,int c)
{
	int dx,dy,p,tdy,tdydx,x,y,temp,flag;

	flag=abs(y2-y1)>abs(x2-x1);

	if(flag)
	{
		temp=x1;
		x1=y1;
		y1=temp;
		temp=x2;
		x2=y2;
		y2=temp;
	}

	if(x1>x2)
	{
		temp=x1;
		x1=x2;
		x2=temp;
		temp=y1;
		y1=y2;
		y2=temp;
	}

	dx=abs(x2-x1);
	dy=abs(y2-y1);
	p=2*dy-dx;
	tdy=2*dy;
	tdydx=2*(dy-dx);
	x=x1;
	y=y1;

	if(flag)
		putpixel(y,x,c);
	else
		putpixel(x,y,c);
	while(x<x2)
	{
		x++;
		if(p<0)
			p+=tdy;
		else
		{
			if(y1<y2)
				y++;

			else
				y--;
			p+=tdydx;
		}
		if(flag)
			putpixel(y,x,c);
		else
			putpixel(x,y,c);
	}
}

void nit_rect(int left,int top,int right,int bottom)
{

/*rectangle(left,top,right,bottom);*/
bres(left,top,right,top,15);
bres(left,top,left,bottom,15);
bres(left,bottom,right,bottom,15);
bres(right,bottom,right,top,15);


bres(((right-left)/2)+left-1,top,((right-left)/2)+left-1,bottom,15);
bres(((right-left)/2)+left+1,top,((right-left)/2)+left+1,bottom,15);


bres(left,((bottom-top)/2)+top-1,right,((bottom-top)/2)+top-1,15);
bres(left,((bottom-top)/2)+top+1,right,((bottom-top)/2)+top+1,15);


}


void main()
{
int gd=DETECT,gm;
int left,top,right,bottom,cx,cy;
initgraph(&gd,&gm,"..\\bgi");

cleardevice();
setcolor(15);
setlinestyle(SOLID_LINE,0,THICK_WIDTH);
/*Border*/
bres(1,1,1,475,15);
bres(630,1,630,475,15);
bres(1,1,630,1,15);
bres(1,475,630,475,15);



/*vertical lines*/
/*left wing*/
bres(140,150,140,250,15);
bres(310,155,310,250,15);
bres(315,155,315,250,15);
/*right wing*/
bres(415,155,415,250,15);
bres(420,155,420,250,15);
bres(590,150,590,250,15);

bres(85,115,85,215,15);

/*Middle wing*/

bres(310,150,310,120,15);
bres(315,150,315,120,15);

bres(415,150,415,120,15);
bres(420,150,420,120,15);


bres(315,195,415,195,15);
bres(315,207,415,207,15);

bres(362,155,362,195,15);
bres(367,155,367,195,15);

bres(315,162,362,162,15);
bres(315,166,362,166,15);

bres(315,172,362,172,15);
bres(315,176,362,176,15);

bres(315,182,362,182,15);
bres(315,185,362,185,15);

bres(367,162,415,162,15);
bres(367,166,415,166,15);

bres(367,172,415,172,15);
bres(367,176,415,176,15);

bres(367,182,415,182,15);
bres(367,185,415,185,15);

bres(312,45,367,80,15);



bres(367,80,280,125,15);
bres(367,85,280,130,15);
bres(280,125,280,130,15);

bres(312,45,225,90,15);

bres(367,80,445,125,15);
bres(367,85,445,130,15);
bres(445,125,445,130,15);


bres(225,90,280,125,15);
bres(225,95,280,130,15);
bres(225,90,225,95,15);



/*ZIGZAG*/
bres(315,120,340,100,15);
bres(320,120,340,105,15);

bres(340,100,355,120,15);
bres(340,105,350,120,15);

bres(355,120,370,100,15);
bres(360,120,370,105,15);

bres(370,100,385,120,15);
bres(370,105,380,120,15);

bres(385,120,395,100,15);
bres(390,120,395,105,15);

bres(395,100,415,120,15);
bres(395,105,410,120,15);



/*Horizontal lines*/
bres(140,150,590,150,15);
bres(140,155,590,155,15);
bres(140,250,590,250,15);

bres(140,200,310,200,15);
bres(140,204,310,204,15);
bres(420,200,590,200,15);
bres(420,204,590,204,15);


bres(85,115,255,115,15);
bres(426,115,535,115,15);
bres(300,120,426,120,15);
bres(315,130,415,130,15);

/*slant lines*/
bres(85,215,140,250,15);
bres(85,115,140,150,15);
bres(85,165,140,200,15);
bres(535,115,590,150,15);


/*Front Part*/
bres(410,208,410,250,15);
bres(320,208,320,250,15);

/*Right front*/
bres(145,205,145,250,15);
bres(145,155,145,200,15);

bres(195,205,195,250,15);
bres(195,155,195,200,15);

bres(200,205,200,250,15);
bres(200,155,200,200,15);

bres(250,205,250,250,15);
bres(250,155,250,200,15);

bres(255,205,255,250,15);
bres(255,155,255,200,15);

bres(305,205,305,250,15);
bres(305,155,305,200,15);

bres(585,205,585,250,15);
bres(585,155,585,200,15);

bres(535,205,535,250,15);
bres(535,155,535,200,15);

bres(530,205,530,250,15);
bres(530,155,530,200,15);

bres(480,205,480,250,15);
bres(480,155,480,200,15);

bres(475,205,475,250,15);
bres(475,155,475,200,15);

bres(425,205,425,250,15);
bres(425,155,425,200,15);

/*Windows Right*/
nit_rect(150,165,165,190);
nit_rect(150,215,165,240);

nit_rect(175,165,190,190);
nit_rect(175,215,190,240);

nit_rect(205,165,220,190);
nit_rect(205,215,220,240);

nit_rect(230,165,245,190);
nit_rect(230,215,245,240);

nit_rect(260,165,275,190);
nit_rect(260,215,275,240);

nit_rect(285,165,300,190);
nit_rect(285,215,300,240);

/*Windows left*/

nit_rect(430,165,446,190);
nit_rect(430,215,446,240);

nit_rect(454,165,470,190);
nit_rect(454,215,470,240);

nit_rect(485,165,500,190);
nit_rect(485,215,500,240);

nit_rect(509,165,525,190);
nit_rect(509,215,525,240);

nit_rect(540,165,555,190);
nit_rect(540,215,555,240);

nit_rect(565,165,580,190);
nit_rect(565,215,580,240);

/*Foundation*/
bres(140,265,320,265,15);
bres(433,265,590,265,15);

bres(590,250,590,265,15);
bres(140,250,140,265,15);
bres(85,216,85,231,15);
bres(85,231,140,265,15);

bres(410,250,440,270,15);
bres(320,250,350,270,15);
bres(320,250,320,265,15);

bres(330,255,417,255,15);
bres(335,260,425,260,15);
bres(342,265,432,265,15);
bres(350,270,439,270,15);

bres(320,265,350,271,15);



settextstyle(SMALL_FONT, HORIZ_DIR,3);
outtextxy(320,197,"GOA ENGINEERING COLLEGE");

/*Road*/
bres(140,300,340,300,15);
bres(340,300,350,270,15);
bres(490,300,630,300,15);
bres(490,300,440,270,15);

bres(408,340,550,475,15);
bres(510,340,630,460,15);

//bres(140,300,2,210,15);
bres(80,315,2,265,15);



bres(140,340,407,340,15);
bres(510,340,630,340,15);


bres(140,340,100,475,15);
bres(80,315,30,475,15);

/*Compound*/
for(cx=140;cx<408;cx=cx+15)
{
bres(cx,320,cx,340,15);
bres(cx+3,320,cx+3,340,15);
}
bres(408,320,408,340,15);
bres(135,323,412,323,15);
bres(135,325,412,325,15);
bres(135,332,412,332,15);
bres(135,334,412,334,15);

for(cx=510;cx<620;cx=cx+15)
{
bres(cx,320,cx,340,15);
bres(cx+3,320,cx+3,340,15);
}
bres(507,323,630,323,15);
bres(507,325,630,325,15);
bres(507,332,630,332,15);
bres(507,334,630,334,15);

for(cx=140;cx<340;cx=cx+15)
{
bres(cx,300,cx,280,15);
bres(cx+3,300,cx+3,280,15);
}
bres(135,283,342,283,15);
bres(135,286,342,286,15);
bres(135,293,342,293,15);
bres(135,296,342,296,15);

for(cx=490;cx<630;cx=cx+15)
{
bres(cx,300,cx,280,15);
bres(cx+3,300,cx+3,280,15);
}
bres(487,283,630,283,15);
bres(487,286,630,286,15);
bres(487,293,630,293,15);
bres(487,296,630,296,15);

for(cx=408,cy=320;cx<550;cx=cx+20,cy=cy+19)
{
bres(cx,cy,cx,cy+20,15);
bres(cx+5,cy,cx+5,cy+22,15);
}
bres(408,320,575,475,15);
//bres(408,326,570,476,15);
//bres(408,335,555,476,15);
bres(412,335,558,476,15);


for(cx=510,cy=325;cx<700;cx=cx+20,cy=cy+19)
{
bres(cx,cy,cx,cy+20,15);
bres(cx+5,cy,cx+5,cy+22,15);
}
bres(510,325,700,500,15);


for(cx=140,cy=320;cx<700;cx=cx-7,cy=cy+19)
{
bres(cx,cy,cx,cy+20,15);
bres(cx+5,cy,cx+5,cy+22,15);
}
bres(140,320,100,440,15);


for(cx=130,cy=275;cx<700;cx=cx-7,cy=cy-4)
{
bres(cx,cy,cx,cy+20,15);
bres(cx+5,cy,cx+5,cy+22,15);
}
bres(140,298,2,220,15);
bres(140,282,2,205,15);


for(cx=85,cy=293;cx<700;cx=cx-7,cy=cy-4)
{
bres(cx,cy,cx,cy+20,15);
bres(cx+5,cy,cx+5,cy+22,15);
}


for(cx=85,cy=293;cx<700;cx=cx-6,cy=cy+15)
{
bres(cx,cy,cx,cy+20,15);
bres(cx+5,cy,cx+5,cy+22,15);
}

/*Bench*/
bres(230,380,330,380,15);
bres(250,395,350,395,15);

bres(230,380,250,395,15);
bres(330,380,350,395,15);

bres(230,400,230,360,15);
bres(330,380,330,360,15);

bres(330,400,330,395,15);

bres(230,360,330,360,15);
bres(230,363,330,363,15);
bres(230,366,330,366,15);
bres(230,369,330,369,15);
bres(230,372,330,372,15);
bres(230,375,330,375,15);
bres(230,378,330,378,15);
bres(230,381,330,381,15);

bres(250,395,250,415,15);
bres(350,395,350,415,15);

getch();
}
