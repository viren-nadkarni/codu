/*finds the root by the method of false postion*/
//x0=2   x1=2.5   error=3   iterations=6
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

float polynom(float);
float moduls(float);

int main ()
{
	//declaration
	float x0, x1, error, f0, f1, modf2;
	int n, i, flag=0;
	double f2, x2;


	//input
	cout << "Enter value of x0: ";
	cin >> x0;
	cout << "\nEnter value of x1: ";
	cin >> x1;
	cout << "\nEnter error: ";
	cin >> error;
	cout << "\nEnter the number of iterations: ";
	cin >> n;
	cout << "\nFinding roots for equation x^3-2x-5...\n\n";
	
	f0=polynom(x0);
	f1=polynom(x1);
	

	//main algorithm
	for(i=1;i<=n;i++)
	{
		x2=(x0*f1-x1*f0)/(f1-f0);
		f2=polynom(x2);
		
		modf2=moduls(f2);

		if(modf2<=error)
		{
			flag=1;
			cout.precision (4);
			cout << "x" << i << "=" << fixed << x2 << endl
				<< "f" << i << "=" << fixed << f2 << endl << endl;
		}

		if (f2>=0&&f1>0 || f2>0&&f1>=0 || f2<=0&&f1<0 || f2<0&&f1<=0)
		{
			x1=x2;
			f1=f2;
		}

		else
		{
			x0=x2;
			f0=f2;
		}
	}

	if (flag!=1)
	{
		cout << "The solution does not converge in " << n << " iterations.\nx2=" << x2 << "\nf2=" << f2 << endl;
	}
	
	return 0;
}

//calculates polynomial value
float polynom(float p)
{
	p=(p*p*p)-2*p-5;
	return (p);
}

//finds modulus
float moduls(float m)
{
	m=m*m;
	m=sqrt(m);
	return (m);
}

