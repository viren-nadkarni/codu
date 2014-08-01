//trapazoidal 
#include<iostream>
float funct(float);

using namespace std;

int main( )
{
	int i,n;
	float y[20],c,h,Y,a,b,s=0;

	cout << "\n Enter limits (a,b) of integral (1/(1+x^2))dx \n";
	cin >> a >> b;
	cout << "\n Enter no. of parts to divide the limits \n";
	cin >> n;

	h=(b-a)/n*1.0;
	c=a;
	cout << "X   Y" << endl;
	for(i=0;i<=n;i++)
	{
		y[i]=funct(c);
		c+=h;
		cout << i << " = " << y[i] << endl;
	}

	for(i=1;i<n;i++)
	s=s+y[i];

	Y=h/2*(y[0]+(2*s)+y[n]);

	cout << "\nThe value of integral for limits (" << a << "," << b << ") is Y= " << Y << endl;
	return 0;
}

float funct(float x1)
{
	float X;
	X=1/(1+(x1*x1));
	return X;
}
