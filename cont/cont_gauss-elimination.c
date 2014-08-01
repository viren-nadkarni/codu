#include <stdio.h>
#include <math.h>
#include <conio.h>


int main()
{
	int eqs,i,j,flag_piv,flag_error;
	float tabl[20][20],x1=1,x2=1,x3=1,t1,t2,t3;

	printf("\n*** Gauss Elimination ***\n\nEnter number of equations: 3");
	eqs=3;

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

	printf("\n\nInput\n------------------------------\n");
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

	t1=(tabl[1][0]/tabl[0][0]);
	t2=(tabl[2][0]/tabl[0][0]);

	for(j=0;j<4;j++)
	{
		tabl[1][j]=tabl[1][j]-(t1*tabl[0][j]);
		tabl[2][j]=tabl[2][j]-(t2*tabl[0][j]);
	}

	t3=(tabl[2][1]/tabl[1][1]);

	for(j=0;j<4;j++)
		tabl[2][j]=tabl[2][j]-(t3*tabl[1][j]);

	x3=tabl[2][3]/tabl[2][2];
	x2=(tabl[1][3]-x1*tabl[1][2])/tabl[1][1];
	x1=(tabl[0][3]-x1*tabl[0][2]-x2*tabl[0][1])/tabl[0][0];
		
	printf("\n\nx1= %f",x1);
	printf("\nx2= %f",x2);
	printf("\nx3= %f",x3);
	
	getch();
	return 0;
}