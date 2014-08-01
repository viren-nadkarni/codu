//newtons backward interpolation
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	float ax[21], ay[21], diff[21][5], nr=1, dr=1, x, p, h, yp;
	int n, i, j, k;

	cout << "Enter the value of n: ";
	cin >> n;
	
	cout << "\nEnter values of x and y:\n";
	for(i=0;i<n;++i)
		cin >> ax[i] >> ay[i];

	cout << "\nEnter the value of x for which y is to be found: ";
	cin >> x;

	h=ax[1]-ax[0];

	for(i=n;i>=1;--i)
		diff[i][1]=ay[i]-ay[i-1];

	for(j=2;j<=4;++j)
		for(i=n;i>j;--i)
			diff[i][j]=diff[i][j-1]-diff[i-1][j-1];

	i=n-1;
	
	p=( (x-ax[i]) / h);
	
	yp=ay[i];
	
	for(k=1;k<i;++k)
	{
		nr *= p+k-1;
		dr *= k;
		yp += (nr/dr)*diff[i][k];
	}

	cout << "\nWhen x= " << fixed << setprecision(2) << x << " y= " << setprecision(6) << yp << endl;
	
	return 0;
}
