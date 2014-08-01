#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>
int x[9]={0,0,0,0,0,0,0,0,0};
int r,no;

nq(int k,int n)
{
   int xmin=169,xmax=569,ymin=39,ymax=439;
int i,j,p,y;
for(i=1;i<=n;i++)
{
if (place(k,i))
{
x[k]=i;
if (k==n)
{  r=r+1;
if(r>no)
exit(0);
else
{
 printf("\nSOLUTION NO.  ");
printf("%d",r);
for(i=ymin;i<=ymax;i+=50)
	  line(xmin,i,xmax,i);
     for(i=xmin;i<=xmax;i+=50)
	  line(i,ymin,i,ymax);
	  }

for(j=1;j<=n&&r<=no;j++)

{


y=j-1;

outtextxy(169+25+50*(x[j]-1),39+25+50*y,"Q");


}

getch();
//closegraph();
cleardevice();

}
else
nq(k+1,n);
}
}
}





int place(int k,int i)
{
int j;
for(j=1;j<=k-1;j++)
if((x[j]==i)||(abs(x[j]-i)==abs(j-k)))
return 0;
return 1;

}
void main()
{  int r=0;
   int gdriver = DETECT, gmode, errorcode;
   initgraph(&gdriver, &gmode, "\\tc\\bgi\\");
   errorcode = graphresult();

   if (errorcode != grOk)
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1);
   }
     printf("\n\nenter no of solutions");
     scanf("%d",&no);

nq(1,8);

}
