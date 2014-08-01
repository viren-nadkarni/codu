/*secant method*/
#include <stdio.h>

float polynom(float v);

int main()
{
	int n,i,flagC;
	float x0,x1,f0,f1,x2,f2,delta,p,q,error;

	printf("Enter intial values x0 & x1:\n");
	scanf("%f %f",&x0,&x1);
	printf("Enter error, slope and max no. of iterations:\n");
	scanf("%f %f %d",&error,&delta,&n);

	f0=polynom(x0);
	f1=polynom(x1);

	for(i=1;i<=n;i++)
	{
		p=(f1-f0);
		p=p*p;
		p=sqrt(p);

		if(p<delta)
		{
			printf("\nSlope is too small\n");
			flagC=0;
			break;
		}

		x2=((x0*f1)-(x1*f0))/(f1-f0);
		f2=polynom(x2);

		q=f2*f2;
		q=sqrt(q);

		printf("\nx%d=%.4f \nf%d=%.4f\n",i,x2,i,f2);

		if (q<error)
		{
			printf("Root found at %dth iteration\n",i);
			flagC=0;
			break;
		}

		if(i==n)
		{
			flagC=1;
			break;
		}

		f0=f1;
		f1=f2;
		x0=x1;
		x1=x2;
	}

	if(flagC==1)
	{
		printf("Root could not be found in %d iterations\n",n);
	}
	return 0;
}

float polynom(float v)
{
	float u;
	u=pow(v,3)+pow(v,2)+v+7;
	return (u);
}

/*OUTPUT
Enter intial values x0 & x1:
-2 -3
Enter error, delta and max no. of iterations:
0.001 0.01 4

x1=-2.0667
f1=0.3775

x2=-2.0912
f2=0.1371

x3=-2.1052
f3=-0.0028

x4=-2.1049
f4=0.0000

Root found at 4th iteration


Enter intial values x0 & x1:
-2 -3
Enter error, delta and max no. of iterations:
0.001 0.01 3

x1=-2.0667
f1=0.3775

x2=-2.0912
f2=0.1371

x3=-2.1052
f3=-0.0028

Root could not be found in 3 iterations

*/