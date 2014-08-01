#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int a,b,c,x1,x2;
	
	cout << "\n\nax^2 + bx + c = 0\nEnter values of a  b  c:\n";
	cin >> a >> b >> c;
	
	x1=((-b-sqrt(b*b+(4*a*c)))/2*a);
	x2=((-b+sqrt(b*b+(4*a*c)))/2*a);
	
	cout << "\nRoots are " << x1 << " and " << x2 << endl;
	
	return 0;
}
