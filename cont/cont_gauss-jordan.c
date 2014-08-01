/* gauss-jordan method*/
#include <stdio.h>
#include <math.h>
#include <conio.h>

int main()
{
	int eqs=3,i,j,m,flag_piv,flag_error;
	float tabl[20][20],x1,x2,x3,t1,t2,t3,norm0,norm1,norm2;

	printf("\n*** Gauss Jordan Elimination ***\n\nNumber of equations: 3");

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

	norm0=tabl[0][0];

	for(m=0;m<=eqs;++m)
		tabl[0][m]=tabl[0][m]/norm0;

	t1=(tabl[1][0]/tabl[0][0]);
	t2=(tabl[2][0]/tabl[0][0]);

	for(j=0;j<=3;++j)
	{
		tabl[1][j]=tabl[1][j]-(t1*tabl[0][j]);
		tabl[2][j]=tabl[2][j]-(t2*tabl[0][j]);
	}

	norm1=tabl[1][1];

	for(m=0;m<=eqs;++m)
		tabl[1][m]=tabl[1][m]/norm1;

	t1=(tabl[0][1]/tabl[1][1]);
	t2=(tabl[2][1]/tabl[1][1]);

	for(j=1;j<=3;++j)
	{
		tabl[0][j]=tabl[0][j]-(t1*tabl[1][j]);
		tabl[2][j]=tabl[2][j]-(t2*tabl[1][j]);
	}

	norm2=tabl[2][2];

	for(m=0;m<=eqs;++m)
		tabl[2][m]=tabl[2][m]/norm2;

	t1=(tabl[0][2]/tabl[2][2]);
	t2=(tabl[1][2]/tabl[2][2]);

	for(j=2;j<=3;++j)
	{
		tabl[0][j]=tabl[0][j]-(t1*tabl[2][j]);
		tabl[1][j]=tabl[1][j]-(t2*tabl[2][j]);
	}

	printf("\n\nOutput values\n------------------------------\n");
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

	printf("\n\nx1= %.2f",tabl[0][3]);
	printf("\nx2= %.2f",tabl[1][3]);
	printf("\nx3= %.2f",tabl[2][3]);

	getch();
	return 0;
}