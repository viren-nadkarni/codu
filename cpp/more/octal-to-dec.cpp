#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int num,dec,ans=0, ans_=0, i=0;
	
	cout << "Enter octal number using a space instead of a decimal point: ";
	cin >> num >> dec;
	
	int x=num, y=dec;
	
	for(int a=num; a>0 ; a/=10)
	{
		x=x%10;
		ans+=(x)*pow(8,i);
		++i;
	}
	
	i=0;
	for(int a=dec; a>0 ; a/=10)
	{
		y=y%10;
		ans_+=(y)*(1/pow(8,i));
		++i;
	}
	
	cout << "Decimal equivalent: " << ans << "." << ans_ << endl;
	
	return 0;
}
