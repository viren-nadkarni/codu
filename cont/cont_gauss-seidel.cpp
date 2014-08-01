//gauss seidel method
#include <iostream>
#include <iomanip>
using namespace std;

float func(int m,float x,float y,float z,float tabl[5][5]);

int main()
{
	float tabl[5][5],x,y,z;

	for(int i=0;i<3;++i)
	{
		cout << "\nEnter coefficients for equation (" << i+1 << "): ";
		cin >> tabl[i][0] >> tabl[i][1] >> tabl[i][2] >> tabl[i][3];
	}

	x=y=z=0;

	for(int j=0;j<10;++j)
	{
		x=func(1,x,y,z,tabl);
		y=func(2,x,y,z,tabl);
		z=func(3,x,y,z,tabl);
	}

	cout << "\nx = " << setprecision(4) << x << "\ty = " << setprecision(4) << y << "\tz = " << setprecision(4) << z;
	cin.get();
	return 0;
}

float func(int m, float x, float y, float z, float tabl[5][5])
{
	switch(m)
	{
		case 1:
			x=( tabl[0][3] - (tabl[0][1]*y) - (tabl[0][2]*z) ) / tabl[0][0];
			break;
		case 2:
			y=( tabl[1][3] - (tabl[1][0]*x) - (tabl[1][2]*z) ) / tabl[1][1];
			break;
		case 3:
			z=( tabl[2][3] - (tabl[2][0]*x) - (tabl[2][1]*y) ) / tabl[2][2];
			break;
	}
	if(m==1)
		return x;
	else if(m==2)
		return y;
	else
		return z;
}
