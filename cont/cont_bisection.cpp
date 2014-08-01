/*finds the root of an equation using bisection method*/
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

float polynom(float);

int main ()
{
	//declarations
	float x0, x1, x2, error, f0, f1, f2, p; 
	int i;

	//input
	cout << "Enter values of x0, x1, error\n";
	cin >> x0 >> x1 >> error;
	cout << "Finding roots for equation x^3-x-1...\n";
	
	f0=polynom(x0);
	f1=polynom(x1);
	i=0;

	//checks for invalid input
	if (f0>=0&&f1>0 || f0>0&&f1>=0 || f0<=0&&f1<0 || f0<0&&f1<=0)
	{
		cout << "Entered values x0, x1, f0, f1 are invalid\n";
		goto endprg;
	}

	//main program
	do
	{
		p=((x1-x0)/x1);
		p=p*p;
		p=sqrt(p);
		
		x2=(x1+x0)/2;
		f2=polynom(x2);
		++i;

		if (f0>0&&f2>0||f0<0&&f2<0)
		{
			x0=x2;
		}
		else 
		{
			x1=x2;
		}
	}while (p>error);

	//output
	cout << "The solution converges to a root\n"
		<< "Number of iterations = " << i << endl
		<< "Value of x" << i << "=" << x2 << "\nValue of f(x" << i << ")=" << polynom(x2) << endl;

endprg:
	return 0;
}

float polynom(float p)
{
	p=pow(p,3)-p-1;
	return (p);
}
