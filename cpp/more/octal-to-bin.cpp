#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int num, ans=0 ,i=0,a;
	
	cout << "Enter octal number: ";
	cin >> num;
	
	int x=num;
	a=num;
		
	while(a>0)
	{
		x=a%10;
		ans+=(x)*pow(8,i);
		++i;
		a=a/10;
	}
	cout << "Decimal equivalent: " << ans << endl;
	a=ans;
	ans=i=0;
	
	while(a>0)
	{
		x=a%2;
		ans+=x*pow(10,i);
		++i;
		a=a/2;
	}
		
	cout << "Binary equivalent: " << ans << endl;
	
	
	
	return 0;
}
