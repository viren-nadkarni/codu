/*newton-raphson method*/
#include <stdio.h>

int main()
{
	int i, n, c,flag;
	float x0, x1, e, f0, f1, q, d;
	
	printf("Enter values of x0, error, iterations, slope:\n");
	scanf("%f %f %d %f",&x0, &e, &n, &d);
	for (i=1;i<=n;i++)
	{
		f0= x0*x0*x0 + x0*x0 + x0 + 7;
		f1=3*x0*x0 + 2*x0 + 1;
		
		if(f1<0)
			f1=-f1;
		if (f1<=d)
		{
			c=1;
			break;
		}
		x1=x0-(f0/f1);
		q=(x1-x0)/x1;
		
		if(q<0)
			q=-q;
		if (q<e)
		{
			flag=1;
			break;
		}
		printf("x%d=%f\tf(x%d)=%f\n",i, x0, i, f0);
		x0=x1;
	}
	if (flag==1)
	{
		printf("x%d=%f \tf(x%d)=%f\nRoots found...\nFinal values: \nx%d=%f \tf(x%d)=%f\n",i, x0, i, f0, i, x0, i, f0);	
	}
	else
	{
		printf("Does not converge in %d iterations\n",i);
		printf("f0=%f\tf'0=%f\nx0=%f\tx=%f\n",f0,f1,x0,x1);
	}
	if (c==1)
		printf("Slope is too small\n");
	return 0;
}




OUTPUT
Enter values of x0, error, iterations, slope:
-2 0.0001 2 0.1
x1=-2.000000    f(x1)=1.000000
x2=-2.111111    f(x2)=-0.063101
Does not converge in 3 iterations
f0=-0.063101    f'0=10.148149
x0=-2.104893    x=-2.104893

Enter values of x0, error, iterations, slope:
-2 0.0001 4 0.1
x1=-2.000000    f(x1)=1.000000
x2=-2.111111    f(x2)=-0.063101
x3=-2.104893    f(x3)=-0.000206
Roots found...
Final values: 
x3=-2.104893    f(x3)=-0.000206
