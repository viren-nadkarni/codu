//lagranges interpolation
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	float ax[21], ay[21], nr, dr, x, y=0;
	int i, j,n;

	cout << "Enter the value of n: ";
	cin >> n;

	cout << "\nEnter values of x:\n";
	for(i=0;i<n;++i)
		cin >> ax[i];

	cout << "\nEnter values of y:\n";
	for(i=0;i<n;++i)
		cin >> ay[i];

	cout << "\nEnter the value of x for which y is to be found: ";
	cin >> x;

	for(i=0;i<n;++i)
	{
		nr=dr=1;
		for(j=0;j<n;j++)
			if(j!=i)
			{
				nr*=x-ax[j];
				dr*=ax[i]-ax[j];
			}
			y+=(nr/dr)*ay[i];
	}

	cout << "\nWhen x = " << setprecision(2) << x << ", value of y = " << setprecision(4) << y << endl;

	return(0);
}
