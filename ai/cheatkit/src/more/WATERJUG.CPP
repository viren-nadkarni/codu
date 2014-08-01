

#include<iostream.h>
#include<conio.h>
#include<stdlib.h>


int mj1=5;
int mj2=3;
int target=4;

int waterjug(int j1, int j2)
{
	cout<<"\n\n\n";
	if(j2!=mj2)
	{
	j1=j1-mj2+j2;
	j2=j2+mj2-j2;
	}
	else if(j2>j1)
	{
	j2=0;
	cout<<"\nWater is thrown out from jug 2";
	cout<<"\njar1="<<j1<<"\njar2="<<j2;
	j2=j1;
	j1=0;
	cout<<"\nWater from jug 1 is emptied into jug 2";
	cout<<"\njar1="<<j1<<"\njar2="<<j2;
	j1=mj1;
	cout<<"\nWater in jug 1 is refilled";
	}
	cout<<"\njar1="<<j1;
	cout<<"\njar2="<<j2;
	if(j1==target || j2==target)
	return 999;
	else
	return waterjug(j1,j2);
}
void main()
{
	int a=mj1,b=0;
	clrscr();
	cout<<"\njar1="<<a;
	cout<<"\njar2="<<b;
	waterjug(a,b);
	getch();
	cout<<"\nProgram done";
	getch();
}


