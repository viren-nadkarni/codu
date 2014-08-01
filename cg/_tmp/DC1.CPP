#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<graphics.h>
#include<dos.h>
#include<iostream.h>

int main()
{
	int gd=DETECT,gm;
	int x[10],i,n;
	initgraph(&gd,&gm,"..\\bgi");
	cout<<"\nEnter the no. of digits:";
	cin>>n;
	cout<<"\nEnter the binary digit...";
	for(i=0;i<n;i++)


	cin>>x[i];
	clrscr();
	//getch();

	line(10,10,10,500);
	line(10,250,700,250);
	for(i=0;i<n;i++)
	{
	 setcolor(3);
	 setlinestyle(1,1,1);
	 line(30+(20*i),100,30+(20*i),400);
	 delay(200);
	 setcolor(15);
	 setlinestyle(0,1,1);
	 if(x[i]==1)
	 {
	   setcolor(5);

	   line(10+(20*i),210,20+(20*i),210);
	   delay(200);
	   line(20+(20*i),210,20+(20*i),290);
	   delay(200);
	   line(20+(20*i),290,30+(20*i),290);
	   delay(200);
	   cout<<"1";
	 }
	 else
	 {setcolor(1);
	 line(10+(20*i),290,20+(20*i),290);
	 delay(200);
	 line(20+(20*i),290,20+(20*i),210);
	 delay(200);
	 line(20+(20*i),210,30+(20*i),210);
	 delay(200);
	 cout<<"0";
	 }

	 }




	getch();
	closegraph();

	return 0;
}
