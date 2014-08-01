/*calculates errors*/
#include <stdio.h>
#include <conio.h>

int main()
{
	clrscr();
	
	//input
	float ano, bno, pe, re, ae;
	printf ("Enter original number\n");
	scanf ("%f",&ano);
	printf ("Enter rounded number\n");
	scanf ("%f",&bno);
	
	//main program body
	ae=ano-bno;
	if(ae<0)
	{
		ae=-ae;
	}
	re=ae/ano;
	pe=re*100;
	
	//output
	printf ("Absolute error = %f\nRelative error = %f\nPercentage error = %f\n",ae,re,pe);
	getch();
	return 0;
}