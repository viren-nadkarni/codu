#include <iostream>
using namespace std;

float round(int x, double num)
int main()
{	
	double num;
	int x;
	
	cout << "Enter number: ";
	cin >> num;
	cout << "\nRound to? ";
	cin >> x;
	
	ans=round(x,num);
	
	cout << "\nAnswer is " << ans;
	
	return 0;
}

double round(double n)
{
    double d;
    int    i;

    
    d = n * 100.0;
    /* round off: 12345.678 + 0.5 = 12346.178 -> 12346 */ 
    i = d + 0.5;
    /* restore to its original scale: 12346 -> 123.46 */
    d = (float)i / 100.0;

    return d;
}
