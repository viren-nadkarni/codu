#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<graphics.h>
#include<dos.h>
#include<iostream.h>

int main()
{
	int gd=DETECT,gm;
	int A[4],i,n;
	initgraph(&gd,&gm,"..\\bgi");
	cout<<"Enter the no: of digits:";
	cin>>n;
	cout<<"\nEnter the data:";
	for(i=0;i<n;i++)
	cin>>A[i];
	clrscr();
	//axis

	line (30,30,30,400);
	line(30,185,400,185);
	for(i=0;i<n;i++)
	{
	   setlinestyle(0,1,1);
	if(A[i]==1)
	{ setcolor(12) ;
		delay(300);
	line(30+(30*i),77,45+(30*i),77);
	delay(300);
	line(45+(30*i),77,45+(30*i),290);
		delay(300);
	line(45+(30*i),290,60+(30*i),290);
		delay(300);
		outtextxy(30+(15*i),30,"1");
	}

	if(A[i]==0)
	{ setcolor(9);
		delay(300);
	line(30+(30*i),290,45+(30*i),290);
		delay(300);
	line(45+(30*i),290,45+(30*i),77);
		delay(300);
	line(45+(30*i),77,60+(30*i),77);
		delay(300);

	}
	 setcolor(14);
       //inbetween line
	 setlinestyle(1,1,1);
	line(60+(30*i),30,60+(30*i),400);
	}

	getch();
	closegraph();

	return 0;
}
