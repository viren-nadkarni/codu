//newtons divided difference
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	float ax[21], ay[21], diff[21][5], nr=1, dr=1, x, yp;
	int n, i, j;

	cout << "Enter the value of n: ";
	cin >> n;
	
	cout << "\nEnter values of x:\n";
	for(i=0;i<n;++i)
		cin >> ax[i] >> ay[i];

	cout << "\nEnter the value of x for which y is to be found: ";
	cin >> x;

	for(i=0;i<n;++i)
		diff[i][0]=ay[i];
		
	for(j=1;j<n;++j)
		for(i=0;i<n-j;++i)
			diff[i][j]=( diff[i+1][j-1]-diff[i][j-1] ) / (ax[i+j]-ax[i]) ;
		
	yp=ay[0];

	for(i=0;i<n-1;++i)
	{
		nr *= (x-ax[i]);
		yp += nr*diff[0][i+1];
	}

	cout << "\nWhen x= " << fixed << setprecision(2) << x << " y= " << setprecision(6) << yp << endl;
	return 0;
}
