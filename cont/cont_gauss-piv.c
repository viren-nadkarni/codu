/* gauss elimination method with pivoting*/
#include <stdio.h>
#include <math.h>
#include <conio.h>

int main()
{
	int eqs=3,i,j,m=0,flag_piv,flag_error;
	float tabl[20][20],x1,x2,x3,tmp_,t1,t2,t3,w00,w10,w20;

	printf("\n*** Gauss Elimination with Pivoting ***\n\nNumber of equations: 3");

	for(i=0;i<eqs;++i)
	{
		printf("\nEquation %d\n",i+1);
		for(j=0;j<=eqs;++j)
		{
			if(i==j)
				flag_piv=1;
			else
				flag_piv=0;
			do
			{
				flag_error=0;
				printf("x%d= ",j+1);
				scanf("%f",&tabl[i][j]);
				if(flag_piv==1)
				{
					if(tabl[i][j]==0)
					{
						flag_error=1;
						printf("\nPivot element cannot be 0, please try again...");
					}
				}
			}while(flag_error==1);
		}
	}

	printf("\n\nInput values\n------------------------------\n");
	for(j=0;j<=eqs;++j)
		printf("  \tx%d",j+1);
	printf("\n------------------------------\n");
	for(i=0;i<eqs;++i)
	{
		printf("E%d\t",i+1);
		for(j=0;j<=eqs;++j)
		{
			printf("%.0f\t",tabl[i][j]);
		}
		printf("\n");
	}

	/*finds absolute value*/
	w00=tabl[0][0];
	if(w00<0)
		w00=-w00;
	w10=tabl[1][0];
	if(w10<0)
		w10=-w10;
	w20=tabl[2][0];
	if(w20<0)
		w20=-w20;

	/* does the pivoting*/
	if(w10>w00)
	{
		printf("\nEquations were pivoted\n");
		if(w20<w00)
		{
			for(m=0;m<=eqs;++m)
			{
				tmp_=tabl[1][m];
				tabl[1][m]=tabl[0][m];
				tabl[0][m]=tmp_;
				tmp_=333;
			}
		}
		else if(w20>w00)
		{
			for(m=0;m<=eqs;++m)
			{
				tmp_=tabl[2][m];
				tabl[2][m]=tabl[0][m];
				tabl[0][m]=tmp_;
				tmp_=444;
			}
		}
	}

	printf("\n\nValues after pivoting\n------------------------------\n");
	for(j=0;j<=eqs;++j)
		printf("  \tx%d",j+1);
	printf("\n------------------------------\n");
	for(i=0;i<eqs;++i)
	{
		printf("E%d\t",i+1);
		for(j=0;j<=eqs;++j)
		{
			printf("%.1f\t",tabl[i][j]);
		}
		printf("\n");
	}

	t1=(tabl[1][0]/tabl[0][0]);
	t2=(tabl[2][0]/tabl[0][0]);

	for(j=0;j<=3;++j)
	{
		tabl[1][j]=tabl[1][j]-(t1*tabl[0][j]);
		tabl[2][j]=tabl[2][j]-(t2*tabl[0][j]);
	}

	printf("\n\nValues after first set of operations\n------------------------------\n");
	for(j=0;j<=eqs;++j)
		printf("  \tx%d",j+1);
	printf("\n------------------------------\n");
	for(i=0;i<eqs;++i)
	{
		printf("E%d\t",i+1);
		for(j=0;j<=eqs;++j)
		{
			printf("%.1f\t",tabl[i][j]);
		}
		printf("\n");
	}

	t3=(tabl[2][1]/tabl[1][1]);

	for(j=0;j<=3;++j)
		tabl[2][j]=tabl[2][j]-(t3*tabl[1][j]);

	x3=tabl[2][3]/tabl[2][2];
	x2=(tabl[1][3]-x3*tabl[1][2])/tabl[1][1];
	x1=(tabl[0][3]-x3*tabl[0][2]-x2*tabl[0][1])/tabl[0][0];

	printf("\n\nFinal values\n------------------------------\n");
	for(j=0;j<=eqs;++j)
		printf("  \tx%d",j+1);
	printf("\n------------------------------\n");
	for(i=0;i<eqs;++i)
	{
		printf("E%d\t",i+1);
		for(j=0;j<=eqs;++j)
		{
			printf("%.1f\t",tabl[i][j]);
		}
		printf("\n");
	}

	printf("\n\nx1= %.2f",x1);
	printf("\nx2= %.2f",x2);
	printf("\nx3= %.2f",x3);

	getch();
	return 0;
}