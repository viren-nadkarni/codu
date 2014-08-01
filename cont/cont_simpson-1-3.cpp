//simpsons 1/3 rule
#include<iostream>

using namespace std;

float funct(float);

int main( )
{
	int i,n;
	float y[20],c,h,Y,a,b,se=0,so=0;

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
	{
		if(i%2==0)
			se=se+y[i];
		else
			so=so+y[i];
	}

	Y=h/3*((y[0]+y[n])+4*so+2*se);

	cout << "\nThe value of integral for limits (" << a << "," << b << ") is Y= " << Y << endl;

	return 0;
}

float funct(float x1)
{
	float X;
	X=1/(1+(x1*x1));
	return X;
}





/*

Enter limits (a,b) of integral (1/(1+x^2))dx 
0 6

Enter no. of parts to divide the limits 
6

X   Y
0 = 1
1 = 0.5
2 = 0.2
3 = 0.1
4 = 0.0588235
5 = 0.0384615
6 = 0.027027

The value of intergarl for limits (0,6) is Y= 1.36617

*/