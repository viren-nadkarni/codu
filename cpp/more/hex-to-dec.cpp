#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	char hex[10];
	int ans=0, x, sz=0, k=0;
	
	cout << "\nEnter hexadecimal number: ";
	cin >> hex;
	
	for(int i=0;hex[i]!='\0';++i)
		sz++;
	
	for(int j=sz-1; j>=0; --j)
	{
		switch(hex[j])
		{
			case '0':
				x=0;
				break;
			case '1':
				x=1;
				break;
			case '2':
				x=2;
				break;
			case '3':
				x=3;
				break;
			case '4':
				x=4;
				break;
			case '5':
				x=5;
				break;
			case '6':
				x=6;
				break;
			case '7':
				x=7;
				break;
			case '8':
				x=8;
				break;
			case '9':
				x=9;
				break;
			case 'a':
				x=10;
				break;
			case 'b':
				x=11;
				break;
			case 'c':
				x=12;
				break;
			case 'd':
				x=13;
				break;
			case 'e':
				x=14;
				break;
			case 'f':
				x=15;
				break;
			default:
				break;
		}
		ans+=x*pow(16.0,k);
		++k;
	}
	
	cout << "\nDecimal equivalent: " << ans;
	return 0;
}
		
					 
